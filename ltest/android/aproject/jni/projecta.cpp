
#include <string.h>
#include <jni.h>
#include <iostream>
#include <string>
#include "../../coreproject/jni/coreproject.h"

extern "C" JNIEXPORT jstring JNICALL Java_com_example_root_dynamiclibtest_MainActivity_GetMyIpFormatted(JNIEnv *env, jobject obj)
{
	std::string val = GetMyIP2();
	val = "(:(:  " + val + ":):)";
	jstring result = env->NewStringUTF(val.c_str());
    return result;
}

extern "C" JNIEXPORT jstring JNICALL Java_com_example_root_dynamiclibtest_MainActivity_GetMyUserAgent(JNIEnv *env, jobject obj)
{
	httpbin h;
	std::string val = h.getMyUserAgent();
	jstring result = env->NewStringUTF(val.c_str());
    return result;
}