#include <jni.h>
#include <iostream>
#include "FaceDetectJNI_FaceDetectBR.h"
#include <openbr/openbr_plugin.h>

QSharedPointer<br::Distance> distance;

JNIEXPORT jdouble JNICALL Java_FaceDetectJNI_FaceDetectBR_compareResult(JNIEnv *env, jobject obj, jstring file1, jstring file2)
{
    
    const char* filepath1 = env->GetStringUTFChars(file1, NULL);
    const char* filepath2 = env->GetStringUTFChars(file2, NULL);

    double result;

    // Retrieve classes for enrolling and comparing templates using the FaceRecognition algorithm
    QSharedPointer<br::Transform> transform = br::Transform::fromAlgorithm("FaceRecognition");

    // Initialize templates
    br::Template queryA(filepath1);
    br::Template target(filepath2);
    
    // Enroll templates
    queryA >> *transform;
    target >> *transform;

    // Compare templates
    result = distance->compare(target, queryA);

    env->ReleaseStringUTFChars(file1,filepath1);
    env->ReleaseStringUTFChars(file2,filepath2);
    return result;
}


JNIEXPORT void JNICALL Java_FaceDetectJNI_FaceDetectBR_initopenBR(JNIEnv *env, jobject obj)
{
   int inputParameter = 1;
   char *inputAlgorithm[] = {"FaceRecognition"};
   br::Context::initialize(inputParameter,inputAlgorithm);
   distance = br::Distance::fromAlgorithm("FaceRecognition");
}

JNIEXPORT void JNICALL Java_FaceDetectJNI_FaceDetectBR_finishopenBR(JNIEnv *env, jobject obj)
{
   br::Context::finalize();
}


