#include <stdio.h>
#include "jni.h"
#include "MyClass.h"


JNIEXPORT void JNICALL Java_MyClass_nativeMethod
  (JNIEnv *env, jobject obj){
      jclass myClassRef = (*env)->GetObjectClass(env, obj);

      jmethodID callbackMethodId = (*env)->GetMethodID(env, myClassRef, "callback", "()V");
      if(callbackMethodId == NULL){
          return;
      }

      jmethodID callMyStaticMethodId = (*env)->GetStaticMethodID(env, myClassRef, "myStaticMethod", "()V");
      if(callMyStaticMethodId == NULL){
          return;
      }

      printf("In C \n");
      (*env)->CallVoidMethod(env, obj, callbackMethodId);
      (*env)->CallStaticVoidMethod(env, myClassRef, callMyStaticMethodId);
}


JNIEXPORT void JNICALL Java_MyClass_accessStaticField(JNIEnv *env, jobject obj){
    
    jclass myClass = (*env)->GetObjectClass(env, obj);

    printf(" In C: \n");

    jfieldID fid = (*env)->GetStaticFieldID(env, myClass, "si", "I");
    if(fid == NULL){
        return; //failed to find the field
    }

    jint siValue = (*env)->GetStaticIntField(env, myClass, fid);
    printf("MyClass.si = %d \n", siValue);

    (*env)->SetStaticIntField(env, myClass, fid, 200);
}

JNIEXPORT void JNICALL Java_MyClass_accessField(JNIEnv *env, jobject obj){
    
    jclass myClass = (*env)->GetObjectClass(env, obj);

    printf(" In C: \n");

    jfieldID fid = (*env)->GetFieldID(env, myClass, "s", "Ljava/lang/String;");

    if(fid == NULL){
        return; //failed to find the field
    }

    /*Read the instance field s */

    jstring jstr = (*env)->GetObjectField(env, obj, fid);

    const char *strValue = (*env)->GetStringUTFChars(env, jstr, NULL);

    if(strValue == NULL){
        return; //out of memory
    }

    printf(" c.s = \"%s\" \n", strValue);
    (*env)->ReleaseStringUTFChars(env, jstr, strValue);

    //create a new string and overwrite the instance field

    jstr = (*env)->NewStringUTF(env, "123");
    if(jstr == NULL){
        return; //out of memory
    }
    (*env)->SetObjectField(env, obj, fid, jstr);
}