#include <stdio.h>
#include "jni.h"
#include "JNIArrays.h"


JNIEXPORT jintArray JNICALL Java_JNIArrays_returnIntArray(JNIEnv *env, jclass obj, jint size){
    
    //Create a java structure
    jintArray  = (*env)->NewIntArray(env, size);
    if (javaArray == NULL) {
        return NULL; /* out of memory error thrown */
    }

    //create a temp structure to populate the jaba int array
    jint tempArray [size];
    for (int i = 0; i < size; i++) {
        tempArray[i] = i*100; 
    }

    //move from the temp structure to the java structure
    (*env)->SetIntArrayRegion(env, javaArray, 0, size, tempArray);

    return javaArray;
}


/* All changes must be ignored. 
    Release mode is JNI_ABORT
*/
JNIEXPORT void JNICALL Java_JNIArrays_passBooleanArray(JNIEnv *env, 
    jclass obj, jbooleanArray array){

        jsize length = (*env)->GetArrayLength(env, array);

        jboolean *body = (*env)->GetBooleanArrayElements(env, array, 0);

        for(int i=0; i<length; i++){
            printf("Boolean value: %s \n", body[i] == JNI_TRUE ? "true" : "false");
            body[i] = 0;
            printf("Boolean changed value: %s \n", body[i] == JNI_TRUE ? "true" : "false");
        }

        (*env)->ReleaseBooleanArrayElements(env, array, body, JNI_ABORT);
}

/* All changes must be return to Java.
Release mode is 0
*/
JNIEXPORT void JNICALL Java_JNIArrays_passByteArray
  (JNIEnv *env, jclass obj, jbyteArray array) {
 
  jsize len = (*env)->GetArrayLength(env, array);
 
  jbyte *body = (*env)->GetByteArrayElements(env, array, 0);
 
  for(int i=0; i < len; i++) {
    printf("Byte value: %d\n", body[i]);
    body[i]=5;
    printf("Byte changed value: %d\n", body[i]);
  }
 
  (*env)->ReleaseByteArrayElements(env, array, body, 0);
}
 
/* All changes must be return to Java.
Release mode is JNI_COMMIT
*/
JNIEXPORT void JNICALL Java_JNIArrays_passCharArray
  (JNIEnv *env, jclass obj, jcharArray array) {
 
  jsize len = (*env)->GetArrayLength(env, array);
 
  jchar *body = (*env)->GetCharArrayElements(env, array, 0);
 
  for(int i=0; i < len; i++) {
    printf("Char value: %c\n", body[i]);
    body[i] = 'M';
    printf("Char changed value: %c\n", body[i]);
  }
 
  (*env)->ReleaseCharArrayElements(env, array, body, JNI_COMMIT);
}
 

JNIEXPORT void JNICALL Java_JNIArrays_passShortArray
  (JNIEnv *env, jclass obj, jshortArray array) {
 
  jsize len = (*env)->GetArrayLength(env, array);
 
  jshort *body = (*env)->GetShortArrayElements(env, array, 0);
 
  for(int i=0; i < len; i++) {
    printf("Short value: %hd\n", body[i]);
    
  }
  (*env)->ReleaseShortArrayElements(env, array, body, 0);
}
 
JNIEXPORT void JNICALL Java_JNIArrays_passIntArray
  (JNIEnv *env, jclass obj, jintArray array) {
 
  jsize len = (*env)->GetArrayLength(env, array);
 
  jint *body = (*env)->GetIntArrayElements(env, array, 0);
 
  for(int i=0; i < len; i++) {
    printf("Int value: %d\n", body[i]);
  }
 
  (*env)->ReleaseIntArrayElements(env, array, body, 0);
}
 
JNIEXPORT void JNICALL Java_JNIArrays_passLongArray
  (JNIEnv *env, jclass obj, jlongArray array) {
 
  jsize len = (*env)->GetArrayLength(env, array);
 
  jlong *body = (*env)->GetLongArrayElements(env, array, 0);
 
  for(int i=0; i < len; i++) {
    printf("Long value: %ld\n", body[i]);
  }
 
  (*env)->ReleaseLongArrayElements(env, array, body, 0);
}
 
JNIEXPORT void JNICALL Java_JNIArrays_passFloatArray
  (JNIEnv *env, jclass obj, jfloatArray array) {
 
  jsize len = (*env)->GetArrayLength(env, array);
 
  jfloat *body = (*env)->GetFloatArrayElements(env, array, 0);
 
  for(int i=0; i < len; i++) {
    printf("Float value: %f\n", body[i]);
  }
 
  (*env)->ReleaseFloatArrayElements(env, array, body, 0);
}
 
JNIEXPORT void JNICALL Java_JNIArrays_passDoubleArray
  (JNIEnv *env, jclass obj, jdoubleArray array) {
 
  jsize len = (*env)->GetArrayLength(env, array);
 
  jdouble *body = (*env)->GetDoubleArrayElements(env, array, 0);
 
  for(int i=0; i < len; i++) {
    printf("Double value: %f\n", body[i]);
  }
 
  (*env)->ReleaseDoubleArrayElements(env, array, body, 0);
}
