class MyClass {

    private static int si;

    private String s;

    private native void accessField();
    private native void accessStaticField();

    public static void main(String args[]) {
        MyClass c = new MyClass();
        c.s = "abc";
        MyClass.si = 100;
        c.accessField();
        c.accessStaticField();

        System.out.println("In Java:");
        System.out.println("  c.s = \"" + c.s + "\"");
        System.out.println("  c.si = \"" + MyClass.si + "\"");
    }
    
    static {
        System.loadLibrary("MyClass");
    }
}
