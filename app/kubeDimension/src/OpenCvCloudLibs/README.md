# Cloud-Computing
Environment: <br />
Linux ubuntu 14.04 <br />
Installation: <br />
&nbsp;&nbsp;a. Install HIPI: http://hipi.cs.virginia.edu/ <br />
&nbsp;&nbsp;b. Install OpenBR: http://openbiometrics.org/doxygen/latest/linux_gcc.html <br />
&nbsp;&nbsp;c. Install OpenCV: http://docs.opencv.org/doc/tutorials/introduction/linux_install/linux_install.html <br />
PreProcessing: <br />
&nbsp;&nbsp;1. To download images, refer to the link: https://github.com/XingKaihang/FindFaceImage <br />
&nbsp;&nbsp;2. To create eigen vector from some pictures :https://github.com/XingKaihang/create_feature <br />
Running: 1. HIPI + YARN + SHELLCOMMAND  <br />
&nbsp;&nbsp;a.Make a directory named “facedetec” under hipi/ directory;<br />
&nbsp;&nbsp;b.Copy all files in HIPI+YARN+SHELL to “facedetec” directory;<br />
&nbsp;&nbsp;c.Edit hipi/build.xml<br />
<blockquote>
&nbsp;&nbsp; &lt target name = "facedetec" &gt <br />
&nbsp;&nbsp;&nbsp;&nbsp;   &lt antcall target = "compile" &gt<br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;     &lt param name = "srcdir" value = "facedetec" / &gt<br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;     &lt param name = "jarfilename" value = "face.jar" / &gt<br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;     &lt param name = "jardir" value = "facedetec" / &gt <br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;     &lt param name = "mainclass" value = "facedetec.FaceDetect" / &gt<br />
&nbsp;&nbsp;&nbsp;&nbsp;    &lt /antcall &gt<br />
&nbsp;&nbsp;  &lt /target &gt<br />
</blockquote>
&nbsp;&nbsp;d.run command “ant facedetec” to build the project;<br />
&nbsp;&nbsp;e.run command “hadoop jar facedetec/face.jar <hib file in hdfs> <output directory>”<br />
2. HIPI + JNI + OPENBR<br />
&nbsp;&nbsp;a. Make a directory named “facedetec” in hipi/ directory;<br />
&nbsp;&nbsp;b. Copy all files in HIPI+JNI+OPENBR to “facedetec” directory;<br />
&nbsp;&nbsp;c. Edit hipi/build.xml<br />
<blockquote>
&nbsp;&nbsp; &lt target name = "facedetec" &gt <br />
&nbsp;&nbsp;&nbsp;&nbsp;   &lt antcall target = "compile" &gt<br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;     &lt param name = "srcdir" value = "facedetec" / &gt<br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;     &lt param name = "jarfilename" value = "face.jar" / &gt<br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;     &lt param name = "jardir" value = "facedetec" / &gt <br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;     &lt param name = "mainclass" value = "facedetec.FaceDetect" / &gt<br />
&nbsp;&nbsp;&nbsp;&nbsp;    &lt /antcall &gt<br />
&nbsp;&nbsp;  &lt /target &gt<br />
</blockquote>
&nbsp;&nbsp;d. run command “ant facedetec” to build the project;<br />
&nbsp;&nbsp;e. run command “hadoop jar facedetec/face.jar <hib file in hdfs> <output directory>”<br />
&nbsp;Note: In FaceDetectJNI directory, you can use any IDE to generate libfacedetectjni.so dynamic library.Put the library to the “~/” path.<br />
3. HADOOPSTREAMING + OPENCV<br />
&nbsp;&nbsp;a. Use gcc command to compile the project.<br />
&nbsp;&nbsp;b. run the command hadoop jar /opt/hadoop-2.6.0/share/hadoop/tools/lib/hadoop-streaming- 2.6.0.jar -input <input txt featurefile> -output <output directory> -mapper facecalmapper -file facecalmapper -reducer facecalreducer -file facecalreducer
run command “hadoop jar facedetec/face.jar <hib file in hdfs> <output directory>”<br />
