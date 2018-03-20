# JNI Exercises

## Simple example on macOS 

Create the java file. `HelloWorld.java`

Execute `javac HelloWorld.java `, this generate a `HelloWorld.class` file.

After that, generate the C Header executing `javah -jni HelloWorld`, you'll get `HelloWorld.h` file.

Create a C file. `HelloWorld.c`.

Implement the C functions.

Compile C file with this command on macOS.

`gcc -c -Wall -Werror -fpic HelloWorld.c -I${JAVA_HOME}/include -I${JAVA_HOME}/include/darwin`

`-I flag` adds other C files needed like `jni.h` and `jni_md.h`.

This command will generate a `HelloWorld.o` file.

Then, you should create a shared library from the `*.o` file using this command.

`gcc -shared -o libHelloWorld.dylib HelloWorld.o`

This command will generate a `libHelloWorld.dylib` file.

If you have all the files on the same directory you should have the following files.

* HelloWorld.java
* HelloWorld.class
* HelloWorld.h
* HelloWorld.c
* HelloWorld.o
* HelloWorld.dylib

Finally, Execute the java class.

`java HelloWorld -Djava.library.path=libHelloWorld.dylib`

### Recipes

###### Recipe 01

The first recipe is a simple HelloWorld.

###### Recipe 02

In this recipe I'm passing the Java Primitive Types to C where will be converted to the appropiate Native Type. [More information](https://docs.oracle.com/javase/7/docs/technotes/guides/jni/spec/types.html)

| Java Primitive Types        | JNI Types           | C Type | Description     |
| ------------ |:------:| -----:|-------:|
| byte | jbyte | signed char | signed 8 bits |
| short | jshort | short | signed 16 bits |
| int | jint | int |signed 32 bits |
| long | jlong | long long  |signed 64 bits |
| float | jfloat | float| 32 bits |
| double | jdouble | double  | 64 bits |
| boolean  | jboolean | unsigned char | unsigned 8 bits |
| char | jchar | unsigned short | unsigned 16 bits |
| void | void | N/A | N/A |

`signed` means that the type can represent negavite numbers; `unsigned` cannot.

###### Recipe 03

In this recipe I'm passing Strings and using some JNI methods like:

UTF-8

* `GetStringUTFChars()` Convert `jstring` to `const char *`.
* `ReleaseStringUTFChars()` Release memory
* `NewStringUTF()` Create new string
* `GetStringUTFLength()` get the `jsize` of the string.

Unicode

* `GetStringChars()` Convert `jstring` to `const char *`.
* `ReleaseStringChars()` Release memory
* `NewString()` Create new string
* `GetStringLength()` get the `jsize` of the string.

`jsize` is an alias, its real type is `jint`.

`typedef jint jsize;`



[More information](http://www.softlab.ntua.gr/facilities/documentation/unix/java/tutorial/native1.1/implementing/string.html)

###### Recipe 04

Arrays

## JNI Stuffs 

##### JNIEnv interface pointer 

Points to a location that contains a pointer to a function table. Each entry in the function table points to a JNI function. Native methods always access data structures in the Java virtual machine through one of the JNI functions.

##### jni.h and jni_md

`jni.h` contains the JNI types and functions to communicate Java and Native Libraries.

`jni_md.h` contains the machine-dependent typedefs for jbyte, jint
   and jlong.

## C stuffs

`typedef` is a keyword in the C and C++ languages to create an alias name for another data type.

`#define` allows constant values.

`#ifdef` and `#endif` directive allows for conditional compilation

### References

http://journals.ecs.soton.ac.uk/java/tutorial/native1.1/implementing/array.html


