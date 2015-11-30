package FaceDetectJNI;

import java.lang.*;

public class FaceDetectBR{
	
	public FaceDetectBR(){
		System.load("~/libfacedetectjni.so");
        }
	public native double compareResult(String file1,String file2);
	public native void initopenBR();
	public native void finishopenBR();
	
	//public static void main(String[] args){
	//	FaceDetectBR openBR = new FaceDetectBR();
	//	double result = openBR.compareResult(args[0],args[1]);
	//	System.out.println(result);
	//	openBR.finishopenBR();
 // }
}
