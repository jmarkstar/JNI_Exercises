
#include <stdio.h>
#include "jni.h"
#include "CatchThrow.h"

JNIEXPORT void JNICALL Java_CatchThrow_doit(JNIEnv *env, jobject obj){
    jthrowable exc;

    jclass cls = (*env)->GetObjectClass(env, obj);

    jmethodID mid = (*env)->GetMethodID(env, cls, "callback", "()V");
    if (mid == NULL) {
        return; 
    }

    (*env)->CallVoidMethod(env, obj, mid);

    exc = (*env)->ExceptionOccurred(env);
    if (exc) {
        /* We don't do much with the exception, except that
              we print a debug message for it, clear it, and
              throw a new exception. */
        
        (*env)->ExceptionDescribe(env);
        (*env)->ExceptionClear(env);

        //JNU_ThrowByName(env, *name, *msg);
        
        jclass newExcCls = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        if (newExcCls == NULL) {
            // Unable to find the exception class, give up. 
        return; 
        }
        (*env)->ThrowNew(env, newExcCls, "thrown from C code");
        
    }
}


//the JNU prefix stands for JNI Utilities. 
void JNU_ThrowByName(JNIEnv *env, const char *name, const char *msg)
{
    jclass cls = (*env)->FindClass(env, name);
    /* if cls is NULL, an exception has already been thrown */
    if (cls != NULL) {
        (*env)->ThrowNew(env, cls, msg);
    }
    /* free the local ref */
    (*env)->DeleteLocalRef(env, cls);
}
