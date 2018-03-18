public class PassInt {
 
    public static native void displayInt(int value);
   
    static {
      System.loadLibrary("PassInt");
    }
   
    public static void main(String[] args) {
      System.out.println("library: " + System.getProperty("java.library.path"));
   
      /* Call to shared library */
      PassInt.displayInt(1);
    }
}