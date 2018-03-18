public class PassNativeTypes {
 
 //SEND VALUES TO C
    public static native void displayByte(byte value);
    public static native void displayShort(short value);
    public static native void displayInt(int value);
    public static native void displayLong(long value);
    public static native void displayFloat(float value);
    public static native void displayDouble(double value);
    public static native void displayBoolean(boolean value);
    public static native void displayChar(char value);

//RECEIVE VALUES FROM C

    public static native boolean getBoolean();
    public static native byte getByte();
    public static native char getChar();
    public static native short getShort();
    public static native int getInt();
    public static native long getLong();
    public static native float getFloat();
    public static native double getDouble();

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

      System.out.println("Receiving values from C");

      /* Call to shared library */
      boolean boolVal = PassNativeTypes.getBoolean();
      byte    byteVal = PassNativeTypes.getByte();
      char    charVal = PassNativeTypes.getChar();
      short   shortVal = PassNativeTypes.getShort();
      int     intVal = PassNativeTypes.getInt();
      long    longVal = PassNativeTypes.getLong();
      float   floatVal = PassNativeTypes.getFloat();
      double  doubleVal = PassNativeTypes.getDouble();
  
      /* We can use results inside Java */
      System.out.println("Boolean from C: " + boolVal);
      System.out.println("Byte from C: " + byteVal);
      System.out.println("Char from C: " + charVal);
      System.out.println("Short from C: " + shortVal);
      System.out.println("Int from C: " + intVal);
      System.out.println("Long from C: " + longVal);
      System.out.println("Float from C: " + floatVal);
      System.out.println("Double from C: " + doubleVal);
    }
}