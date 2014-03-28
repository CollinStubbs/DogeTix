package BackEnd;

public class OldToNewManager{
   String[] userAccountFileHolder;
   String[] availableTicketHolder;
   String[] mergedDTF;
   String[] newUAF;
   String[] newATF;
   public OldToNewManager(String[] userAccountFileHolder, String[] availableTicketHolder, String[] mergedDTF){
      this.userAccountFileHolder = userAccountFileHolder;
      this.availableTicketHolder = AvailableTicketHolder;
      this.mergedDTF = mergedDTF;   
      if(!applyMergedDTF()){
         ErrorLog log = new ErrorLog();
      }
   }
   public static boolean applyMergedDTF(){ 
      return false;
   }
   public static boolean writeToNewUAFFile(){
      return false;
   }
   public static boolean writeToNewATFFile(){
      return false;
   }
   public static boolean writeError(){
      return false;
   }
   public static bool checkTicketNum(int num){
      return (num>=0)? true : false;
   }

}