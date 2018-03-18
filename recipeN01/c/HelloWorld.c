#include <stdio.h>
#include "jni.h"
#include "HelloWorld.h"

JNIEXPORT void JNICALL Java_HelloWorld_displayMessage(JNIEnv *env, 
    jclass obj) {
 
  printf("Hello JNI!\n");
 
}