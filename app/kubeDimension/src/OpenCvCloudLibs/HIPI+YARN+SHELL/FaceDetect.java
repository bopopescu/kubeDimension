package facedetec;
import hipi.image.FloatImage;
import hipi.image.ImageHeader;
import hipi.imagebundle.mapreduce.ImageBundleInputFormat;
import hipi.image.ImageHeader.ImageType;
import hipi.image.io.*;
import hipi.util.ByteUtils;
import hipi.image.io.JPEGImageUtil;


import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.conf.Configured;
import org.apache.hadoop.util.Tool;
import org.apache.hadoop.util.ToolRunner;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.Mapper;
import org.apache.hadoop.mapreduce.Reducer;
import org.apache.hadoop.fs.FileSystem;
import org.apache.hadoop.fs.FSDataOutputStream;
import org.apache.hadoop.io.BytesWritable;
import org.apache.hadoop.io.BooleanWritable;
import org.apache.hadoop.mapreduce.lib.input.FileSplit;

import java.util.Iterator;
import java.util.ArrayList;
import java.io.IOException;
import java.util.List;
import java.io.FileOutputStream;
import java.io.File;
import java.io.*;
import javax.imageio.stream.FileImageOutputStream;

//import facedetec.FaceDetectJNA.*;
import FaceDetectJNI.FaceDetectBR;


public class FaceDetect extends Configured implements Tool {
  
 public static class FaceDetectMapper extends Mapper<ImageHeader, BytesWritable, Text, Text> {
    
    public Path path;
    public FileSystem fileSystem;

    @Override
    public void setup(Context context) throws IOException {
      Configuration conf = context.getConfiguration();
      fileSystem = FileSystem.get(context.getConfiguration());
      path = new Path(conf.get("facedetect.outdir"));
      fileSystem.mkdirs(path);
    }


    @Override
    public void map(ImageHeader key, BytesWritable value, Context context) 
        throws IOException, InterruptedException {

      // Verify that image was properly decoded, is of sufficient size, and has three color channels (RGB)
	if (value == null) {
	System.err.println("Null byte array, skipping image."); 
        return;
	}
	else {
        // Determine file type
        String ext = ".jpg";
        if (key.getImageType() == ImageType.JPEG_IMAGE) {
            ext = ".jpg";
	   // iencoder = new JPEGImageUtil();
        } else if (key.getImageType() == ImageType.PNG_IMAGE) {
           ext = ".png";
	   // iencoder = new PNGImageUtil();
        } else {
        System.err.println("Unsupported image type, skipping image.");
          return;
        }

        //hash the image read from hib to make it unique 
        String hashval = ByteUtils.asHex(value.getBytes());
	      Path localpath = new Path("~/temp_images/" + hashval + ext);
	      File localfile = new File(localpath.toString());
        //write file to local
	      if(!localfile.exists())
	      {
		      localfile.createNewFile();
	
		      BufferedOutputStream localbos = new BufferedOutputStream(new FileOutputStream(localfile));
		      localbos.write(value.getBytes());
		      localbos.flush();
		      localbos.close();
	      }
        //using shell command to execute OpenBR algoithm 
        String command = "br -algorithm FaceRecognition -compare ~/compare.jpg ~/temp_images/" + hashval + ext;
	      String[] commandAndArgs2 = new String[]{"/bin/sh", "-c", command};
        // execute my command
        String difference = "";
	      String currentline = "";
        try {
             
            // using the Runtime exec method:
            Process p = Runtime.getRuntime().exec(commandAndArgs2);

            BufferedReader stdInput = new BufferedReader(new
                 InputStreamReader(p.getInputStream()));
 
            // read the output from the command
            while((currentline = stdInput.readLine()) != null){
	   	       difference = currentline;
	          }
          }
        catch (IOException e) {
            e.printStackTrace();
            System.exit(-1);
        }

        context.write(new Text("compare.jpg"), new Text(hashval + ext + "," + difference));
      } // If (value != null...
      
    } // map()

  } // FaceDetectMapper


 public static class FaceDetectReducer extends Reducer<Text, Text, Text, Text> {
   
   @Override
   public void reduce(Text key, Iterable<Text> values, Context context)
        throws IOException, InterruptedException {
        double maxValue = 0;
	      String photoID = "";
        for(Text tempString : values){
	        String[] fields = tempString.toString().split(",");
	        double temp_value = Double.parseDouble(fields[1]);
          if(maxValue < temp_value)
	        {
	         maxValue = temp_value;
	         photoID = fields[0];
	        }
        }
        context.write(new Text(key), new Text(photoID + "," + Double.toString(maxValue)));
    } // reduce()

  } // FaceDetectReducer



 public int run(String[] args) throws Exception {
    // Check input arguments
    if (args.length != 2) {
      System.out.println("Usage: FaceDetect <image hib> <output directory>");
      System.exit(0);
    }
    
    String inputPath = args[0];
    String outputPath = args[1];
    
    // Setup job configuration
    Configuration conf = new Configuration();
    conf.setStrings("facedetect.outdir", outputPath);
 
    removeDir(outputPath, conf);

    // Initialize and configure MapReduce job
    Job job = Job.getInstance(conf,"face");
    // Set input format class which parses the input HIB and spawns map tasks
    job.setInputFormatClass(FaceDetectInputFormat.class);
    //job.setInputFormatClass(ImageBundleInputFormat.class);
    // Set the driver, mapper, and reducer classes which express the computation
    job.setJarByClass(FaceDetect.class);
    job.setMapperClass(FaceDetectMapper.class);
    job.setReducerClass(FaceDetectReducer.class);
    // Set the types for the key/value pairs passed to/from map and reduce layers
    job.setMapOutputKeyClass(Text.class);
    job.setMapOutputValueClass(Text.class);
    job.setOutputKeyClass(Text.class);
    job.setOutputValueClass(Text.class);
    
    // Set the input and output paths on the HDFS
    FileOutputFormat.setOutputPath(job, new Path(outputPath));
    ImageBundleInputFormat.setInputPaths(job, new Path(inputPath));	
    // Execute the MapReduce job and block until it complets
    boolean success = job.waitForCompletion(true);
    
    // Return success or failure
    return success ? 0 : 1;
  }
  

  private static void removeDir(String pathToDirectory, Configuration conf) throws IOException {
    Path pathToRemove = new Path(pathToDirectory);
    FileSystem fileSystem = FileSystem.get(conf);
    if (fileSystem.exists(pathToRemove)) {
      fileSystem.delete(pathToRemove, true);
    }
  }



  public static void main(String[] args) throws Exception {
    ToolRunner.run(new FaceDetect(), args);
    System.exit(0);
  }
  
}

