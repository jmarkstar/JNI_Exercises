# JNI Exercises

###Steps

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

###Recipes

######Recipe 01

The first recipe is a simple HelloWorld.

######Recipe 02

In this recipe I'm passing the Java Primitive Types to C where will be converted to the appropiate Native Type. [More information](https://docs.oracle.com/javase/7/docs/technotes/guides/jni/spec/types.html)

| Java Primitive Types        | Native Types           | Description     |
| --------------------------- |:----------------------:| ---------------:|
| byte | jbyte | signed 8 bits |
| short | jshort | signed 16 bits |
| int | jint | signed 32 bits |
| long | jlong | signed 64 bits |
| float | jfloat | 32 bits |
| double | jdouble | 64 bits |
| boolean  | jboolean | unsigned 8 bits |
| char | jchar | unsigned 16 bits |
| void | void | N/A |

`signed` means that the type can represent negavite numbers; `unsigned` cannot.

######Recipe 03

String

######Recipe 04

Arrays


