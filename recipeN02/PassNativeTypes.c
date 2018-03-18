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

//RETURN VALUES TO JAVA

JNIEXPORT jboolean JNICALL Java_PassNativeTypes_getBoolean(JNIEnv *env, jclass obj) {
 
  jboolean result = JNI_TRUE;
  return result;
}
 
JNIEXPORT jbyte JNICALL Java_PassNativeTypes_getByte(JNIEnv *env, jclass obj) {
 
  jbyte result = 127;
  return result;
}
 
JNIEXPORT jchar JNICALL Java_PassNativeTypes_getChar(JNIEnv *env, jclass obj) {
 
  jchar result = 'a';
  return result;
}
 
JNIEXPORT jshort JNICALL Java_PassNativeTypes_getShort(JNIEnv *env, jclass obj) {
 
  jshort result = 2500;
  return result;
}
 
JNIEXPORT jint JNICALL Java_PassNativeTypes_getInt(JNIEnv *env, jclass obj) {
 
  jint result = 12500;
  return result;
}
 
JNIEXPORT jlong JNICALL Java_PassNativeTypes_getLong(JNIEnv *env, jclass obj) {
 
  jlong result = 125000000;
  return result;
}
 
JNIEXPORT jfloat JNICALL Java_PassNativeTypes_getFloat(JNIEnv *env, jclass obj) {
 
  jfloat result = 1.1;
  return result;
}
 
JNIEXPORT jdouble JNICALL Java_PassNativeTypes_getDouble(JNIEnv *env, jclass obj) {
 
  jdouble result = 1.1;
  return result;
}