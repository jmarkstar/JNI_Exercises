public class PassNativeTypes {
 
    public static native void displayByte(byte value);
    public static native void displayShort(short value);
    public static native void displayInt(int value);
    public static native void displayLong(long value);

    public static native void displayFloat(float value);
    public static native void displayDouble(double value);
   
    public static native void displayBoolean(boolean value);

    public static native void displayChar(char value);

    static {
      System.loadLibrary("PassNativeTypes");
    }
   
    public static void main(String[] args) {
      System.out.println("library: " + System.getProperty("java.library.path"));
   
      /* Call to shared library */

      PassNativeTypes.displayBoolean(true);
      PassNativeTypes.displayBoolean(false);

      PassNativeTypes.displayChar('M');

      System.out.print("Positive Numbers");

      PassNativeTypes.displayByte((byte)1);
      PassNativeTypes.displayShort((short)200);
      PassNativeTypes.displayInt(1000);
      PassNativeTypes.displayLong(5000000);

      PassNativeTypes.displayFloat(100.23f);
      PassNativeTypes.displayDouble(20000.34534);

      System.out.print("Negative Numbers");

      PassNativeTypes.displayByte((byte)-1);
      PassNativeTypes.displayShort((short)-200);
      PassNativeTypes.displayInt(-1000);
      PassNativeTypes.displayLong(-5000000);

      PassNativeTypes.displayFloat(-100.23f);
      PassNativeTypes.displayDouble(-20000.34534);
    }
}