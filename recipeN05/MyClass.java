class MyClass {

    private static int si;

    private String s;

    private native void accessField();
    private native void accessStaticField();

    private native void nativeMethod();

    private void callback(){
        System.out.println("In Java");
    }

    private static void myStaticMethod(){
        System.out.println("Static method: In Java");
    }

    public static void main(String args[]) {
        MyClass c = new MyClass();
        c.s = "abc";
        MyClass.si = 100;
        c.accessField();
        c.accessStaticField();

        System.out.println("Fields");
        System.out.println("-----------");
        System.out.println("In Java:");
        System.out.println("  c.s = \"" + c.s + "\"");
        System.out.println("  c.si = \"" + MyClass.si + "\"");

        System.out.println();
        System.out.println("Methods");
        System.out.println("-----------");

        c.nativeMethod();
    }
    
    static {
        System.loadLibrary("MyClass");
    }
}
