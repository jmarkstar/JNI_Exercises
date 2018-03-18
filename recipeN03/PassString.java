public class PassString {
 
    /* This is the native method we want to call */
    public static native void displayString(java.lang.String value);
   
    public static native String getStringFromC();

    /* Inside static block we will load shared library */
    static {
      System.loadLibrary("PassString");
    }
   
    public static void main(String[] args) {
      /* This message will help you determine whether
          LD_LIBRARY_PATH is correctly set
      */
      System.out.println("library: "
        + System.getProperty("java.library.path"));
   
      java.lang.String strHello = "Hello";
      java.lang.String strWorld = "world";
   
      /* Call to shared library */
      PassString.displayString(strHello);
      PassString.displayString(strWorld);

      String strFromC = PassString.getStringFromC();

      System.out.print(" String from C:  "+strFromC);
    }
  }