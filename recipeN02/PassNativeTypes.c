#include <stdio.h>
#include "jni.h"
#include "PassNativeTypes.h"

JNIEXPORT void JNICALL Java_PassNativeTypes_displayByte(JNIEnv *env, jclass obj, jbyte value){
    printf("Passed byte value: %d \n", value);
}

JNIEXPORT void JNICALL Java_PassNativeTypes_displayShort(JNIEnv *env, jclass obj, jshort value){
    printf("Passed short value: %d \n", value);
}

JNIEXPORT void JNICALL Java_PassNativeTypes_displayInt(JNIEnv *env, jclass obj, jint value){
    printf("Passed Int value: %d \n", value);
}

JNIEXPORT void JNICALL Java_PassNativeTypes_displayLong(JNIEnv *env, jclass obj, jlong value){
    printf("Passed long value: %ld \n", value);
}

JNIEXPORT void JNICALL Java_PassNativeTypes_displayFloat(JNIEnv *env, jclass obj, jfloat value){
    printf("Passed float value: %.4f \n", value);
}

JNIEXPORT void JNICALL Java_PassNativeTypes_displayDouble(JNIEnv *env, jclass obj, jdouble value){
    printf("Passed double value: %lf \n", value);
}

JNIEXPORT void JNICALL Java_PassNativeTypes_displayBoolean(JNIEnv *env, jclass obj, jboolean value){
    printf("Passed boolean value: %s \n", value ? "true" : "false");
}

JNIEXPORT void JNICALL Java_PassNativeTypes_displayChar(JNIEnv *env, jclass obj, jchar value){
    printf("Passed char value: %c \n", value);
}
