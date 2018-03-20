
public class JNIArrays {
 
    public static native void passBooleanArray(boolean [] array);
    public static native void passByteArray(byte [] array);
    public static native void passCharArray(char [] array);
    public static native void passShortArray(short [] array);
    public static native void passIntArray(int [] array);
    public static native void passLongArray(long [] array);
    public static native void passFloatArray(float [] array);
    public static native void passDoubleArray(double [] array);

    public static native int [] returnIntArray(int size);
   
    static {
      System.loadLibrary("JNIArrays");
    }
   
    public static void main(String[] args) {

      System.out.println("library: "
        + System.getProperty("java.library.path"));
   
      /* Arrays declared inside Java */
      boolean [] boolArray    = { true, true, false };
      byte    [] byteArray    = { -128, 127, 0 };
      char    [] charArray    = { 'a', 'b', 'c' };
      short   [] shortArray   = { 1, 2, (short) 0xffff };
      int     [] intArray     = { 1, 2, 0xffffffff };
      long    [] longArray    = { 1, 2, 0xffffffffffffffffL };
      float   [] floatArray   = { 1.1f, 1.2f, 1.3f };
      double  [] doubleArray  = { 1.1d, 1.2d, 1.3d };
   
      /* Call to shared library */
      passBooleanArray(boolArray);
      passByteArray(byteArray);
      passCharArray(charArray);
      passShortArray(shortArray);
      passIntArray(intArray);
      passLongArray(longArray);
      passFloatArray(floatArray);
      passDoubleArray(doubleArray);

      for(int i=0;i<3;i++) {
        System.out.println(
                "boolArray["    + i + "] = " + boolArray[i]   + "\n"
              + "byteArray["    + i + "] = " + byteArray[i]   + "\n"
              + "charArray["    + i + "] = " + charArray[i]   + "\n"
              + "shortArray["   + i + "] = " + shortArray[i]  + "\n"
              + "intArray["     + i + "] = " + intArray[i]    + "\n"
              + "longArray["    + i + "] = " + longArray[i]   + "\n"
              + "floatArray["   + i + "] = " + floatArray[i]  + "\n"
              + "doubleArray["  + i + "] = " + doubleArray[i] + "\n");
      }

      System.out.println();
      System.out.println("-------------------------");
      System.out.println();

      int returnedIntArray [] = returnIntArray(10);

      for(int i=0;i<returnedIntArray.length; i++){
        System.out.println("value ["+i+"] = "+returnedIntArray[i]);
      }
    

    }
}