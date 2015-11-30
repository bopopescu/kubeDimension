Environment: 
Linux ubuntu 14.04 
Installation: 
  a. Install HIPI: http://hipi.cs.virginia.edu/ 
  b. Install OpenBR: http://openbiometrics.org/doxygen/latest/linux_gcc.html 
  c. Install OpenCV: http://docs.opencv.org/doc/tutorials/introduction/linux_install/linux_install.html 
PreProcessing: 
  1. To download images, refer to the link: https://github.com/XingKaihang/FindFaceImage 
  2. To create eigen vector from some pictures :https://github.com/XingKaihang/create_feature 
HADOOPSTREAMING + OPENCV
  a. Use gcc command to compile the project.
  b. run the command hadoop jar /opt/hadoop-2.6.0/share/hadoop/tools/lib/hadoop-streaming- 2.6.0.jar -input -output -mapper facecalmapper -file facecalmapper -reducer facecalreducer -file facecalreducer run command “hadoop jar facedetec/face.jar ”

NOTE: 
  1.This folder is used to generate the Eigen Values of the input dataset. facecalmapper.cpp and facecalreducer.cpp are the implementation.
