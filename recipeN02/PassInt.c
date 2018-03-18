#include <stdio.h>
#include "jni.h"
#include "PassInt.h"

JNIEXPORT void JNICALL Java_PassInt_displayInt(JNIEnv *env, jclass obj, jint value){
    printf("Passed value: %d \n", value);
}