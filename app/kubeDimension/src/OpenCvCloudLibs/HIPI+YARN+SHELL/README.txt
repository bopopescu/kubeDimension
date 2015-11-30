Environment: 
Linux ubuntu 14.04 
Installation: 
  a. Install HIPI: http://hipi.cs.virginia.edu/ 
  b. Install OpenBR: http://openbiometrics.org/doxygen/latest/linux_gcc.html 
  c. Install OpenCV: http://docs.opencv.org/doc/tutorials/introduction/linux_install/linux_install.html 
Running: 1. HIPI + YARN + SHELLCOMMAND 
  a.Make a directory named “facedetec” under hipi/ directory;
  b.Copy all files in HIPI+YARN+SHELL to “facedetec” directory;
  c.Edit hipi/build.xml

   < target name = "facedetec" > 
     < antcall target = "compile" >
      < param name = "srcdir" value = "facedetec" / >
      < param name = "jarfilename" value = "face.jar" / >
      < param name = "jardir" value = "facedetec" / > 
      < param name = "mainclass" value = "facedetec.FaceDetect" / >
     < /antcall >
   < /target >
  d.run command “ant facedetec” to build the project;
  e.run command “hadoop jar facedetec/face.jar ”

Note: Mapper and Reducer are implemented in FaceDetect.java file.
