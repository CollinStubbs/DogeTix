package BackEnd;
/*************************************
   This is a class designed to handle
  errors within the code. If an error is
  found an instance of this class will be
  created to deal with it.
**************************************/

public class ErrorLogManager{
   static String type;
   static String desc;
   static String transaction;
   //constructor for fatal errors
   public ErrorLogManager(String type, String desc){
      this.type = type;
      this.desc = desc;
      writeToLog();
   }
   //constructor for constraint errors
   public ErrorLogManager(String type, String desc, String transaction){
      this.type = type;
      this.desc = desc;
      this.transaction = transaction; 
      writeToLog2();
   }
   //writes to the terminal in the ase of a fatal error
   public static void writeToLog(){
      //print to console here with specific messages
      System.out.println("ERROR: type = "+type+
         " description: "+ desc);
   }
   //writes to the terminal in the case of a constraint error
   public static void writeToLog2(){
      //print to console here with specific messages
      System.out.println("ERROR: type = "+type+
         " description: "+ desc+
         " transaction: "+ transaction);
   }
}