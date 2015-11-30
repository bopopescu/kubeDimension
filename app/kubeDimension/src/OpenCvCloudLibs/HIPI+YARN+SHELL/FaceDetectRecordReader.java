package facedetec;
import hipi.image.ImageHeader;
import hipi.imagebundle.HipiImageBundle;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.FileSystem;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.BytesWritable;

import org.apache.hadoop.mapreduce.InputSplit;
import org.apache.hadoop.mapreduce.RecordReader;
import org.apache.hadoop.mapreduce.TaskAttemptContext;
import org.apache.hadoop.mapreduce.lib.input.FileSplit;

import java.io.IOException;


//used to read record in split
public class FaceDetectRecordReader extends RecordReader<ImageHeader, BytesWritable> {

  protected Configuration conf;
  private HipiImageBundle.FileReader reader;

  @Override
  public void initialize(InputSplit split, TaskAttemptContext context) throws IOException, InterruptedException {
 
    FileSplit bundleSplit = (FileSplit) split;
    conf = context.getConfiguration();
    
    Path path = bundleSplit.getPath();
    FileSystem fs = path.getFileSystem(conf);

    // Report locations of first and last byte in image segment
    System.out.println("Record starts at byte " + bundleSplit.getStart() + " and ends at byte " + (bundleSplit.getStart() + bundleSplit.getLength() - 1));

    reader = new HipiImageBundle.FileReader(fs, path, conf, bundleSplit.getStart(), bundleSplit.getStart() + bundleSplit.getLength() - 1);
  }

  @Override
  public void close() throws IOException {
    reader.close();
  }

  @Override
  public ImageHeader getCurrentKey() throws IOException, InterruptedException {
    return reader.getCurrentKey();
  }

  @Override
  public BytesWritable getCurrentValue() throws IOException, InterruptedException {
    return new BytesWritable(reader.getRawBytes());
  }

  @Override
  public float getProgress() throws IOException, InterruptedException {
    return reader.getProgress();
  }

  @Override
  public boolean nextKeyValue() throws IOException, InterruptedException {
    return reader.nextKeyValue();
  }
}
