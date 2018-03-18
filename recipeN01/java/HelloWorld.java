public class HelloWorld{

    static {
        System.loadLibrary("HelloWorld");
    }

    public static void main(String[] args) {
        System.out.println("Library: "+System.getProperty("java.library.path"));
        HelloWorld.displayMessage();
    }

    public static native void displayMessage();
}