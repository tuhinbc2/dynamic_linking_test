#include <iostream>
#include <string>
#include <jni.h>
#include <curl/curl.h>
#include "coreproject.h"

std::string myip;

size_t writeCallback(char* buf, size_t size, size_t nmemb, void* up)
{ //callback must have this declaration
    //buf is a pointer to the data that curl has for us
    //size*nmemb is the size of the buffer

    for (int c = 0; c<size*nmemb; c++)
    {
        myip.push_back(buf[c]);
    }
    return size*nmemb; //tell curl how many bytes we handled
}

std::string Fetch(std::string url)
{
    myip.clear();
    
    CURL *curl = curl_easy_init();

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &writeCallback);
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

    curl_easy_perform(curl);

    //cout << endl << data << endl;

    curl_easy_cleanup(curl);
    curl_global_cleanup();

    return myip;
}

std::string GetMyIP2()
{
    std::string val = Fetch("http://httpbin.org/ip");
    val = val.substr(val.find(":") + 3);
    val = val.substr(0, val.find("\""));
    return val;
}

extern "C" JNIEXPORT jstring JNICALL Java_com_example_root_dynamiclibtest_MainActivity_GetMyIP(JNIEnv *env, jobject obj)
{
    GetMyIP2();
    jstring result = env->NewStringUTF(myip.c_str());
    return result;
}


extern "C" JNIEXPORT jstring JNICALL Java_com_example_root_dynamiclibtest_MainActivity_GetLifeValue(JNIEnv *env, jobject obj)
{
	std::string val = "42";
	jstring result = env->NewStringUTF(val.c_str());
    return result;
}

std::string httpbin::getMyUserAgent()
{
    return Fetch("http://httpbin.org/user-agent");
}

std::string httpbin::getSampleXML()
{
    return Fetch("http://httpbin.org/xml");
}