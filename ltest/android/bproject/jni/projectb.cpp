
#include <string.h>
#include <jni.h>
#include <iostream>
#include <string>
#include "../../coreproject/jni/coreproject.h"

extern "C" JNIEXPORT jstring JNICALL Java_com_example_root_dynamiclibtest_MainActivity_GetMyIpSuperFormatted(JNIEnv *env, jobject obj)
{
	std::string val = GetMyIP2();
	val = "(:(::D:D:D  " + val + ":D:D:D:):)";
	jstring result = env->NewStringUTF(val.c_str());
    return result;
}