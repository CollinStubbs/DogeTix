package BackEnd;

public class ErrorLogManager{
   static String type;
   static String desc;
   static String transaction;
   
   public ErrorLogManager(String type, String desc){
      this.type = type;
      this.desc = desc;
      writeToLog();
   }
   public ErrorLogManager(String type, String desc, String transaction){
      this.type = type;
      this.desc = desc;
      this.transaction = transaction; 
      writeToLog2();
   }
   public static void writeToLog(){
      //print to console here with specific messages
      System.out.println("ERROR: type = "+type+
         " description: "+ desc);
   }
   public static void writeToLog2(){
      //print to console here with specific messages
      System.out.println("ERROR: type = "+type+
         " description: "+ desc+
         " transaction: "+ transaction);
   }
}