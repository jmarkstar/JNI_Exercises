#include <stdio.h>
#include "jni.h"
#include "PassString.h"
 

/* Gets a jstring from Java
 */
JNIEXPORT void JNICALL Java_PassString_displayString
  (JNIEnv *env, jclass obj, jstring str) {
      
    const char *c_str;
    //const jchar *c_str2;

    c_str = (*env)->GetStringUTFChars(env, str, NULL);
    //c_str2 = (*env)->GetStringChars(env, str, NULL);

    jsize size = (*env)->GetStringLength(env, str);
    printf("Passed string size: %d \n", size);
    jsize size2 = (*env)->GetStringUTFLength(env, str);
    printf("Passed UTF string size: %d \n", size2);

    if(c_str == NULL){
        return;
    }

    printf("Passed UTF string: %s \n", c_str);
    (*env)->ReleaseStringUTFChars(env, str, c_str);

/*
    if(c_str2 == NULL){
        return;
    }
*/
    //printf("Passed string: %s \n", c_str2);
    //(*env)->ReleaseStringChars(env, str, c_str2);
}

/* Sends a String to Java
**/
JNIEXPORT jstring JNICALL Java_PassString_getStringFromC
    (JNIEnv *env, jclass obj){

    int version = (*env)->GetVersion(env);
    printf("%d \n", version);

    char buffer [] = "This is a sample string \n";

    return (*env)->NewStringUTF(env, buffer);
}


//const = constants


//GetStringUTFChars -> Convert jstring to const char *.
//ReleaseStringUTFChars -> Release memory.
//NewStringUTF -> create a new jstring


/*
GetStringChars takes the Java string and returns a pointer to an array of Unicode characters that comprise the string.
ReleaseStringChars releases the pointer to the array of Unicode characters.
NewString constructs a new java.lang.String object from an array of Unicode characters.
GetStringLength returns the length of a string that is comprised of an array of Unicode characters.
GetStringUTFLength returns the length of a string if it is represented in the UTF-8 format.
*/
