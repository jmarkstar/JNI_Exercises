#include <stdio.h>
#include "jni.h"
#include "PassString.h"
 

/* Gets a jstring from Java
 */
JNIEXPORT void JNICALL Java_PassString_displayString
  (JNIEnv *env, jclass obj, jstring str) {
      
    const char *c_str;
    c_str = (*env)->GetStringUTFChars(env, str, NULL);
    if(c_str == NULL){
        return;
    }
    
    printf("Passed string: %s \n", c_str);

    //release memory
    (*env)->ReleaseStringUTFChars(env, str, c_str);
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
