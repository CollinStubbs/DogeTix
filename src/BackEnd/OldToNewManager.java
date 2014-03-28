package BackEnd;

public class OldToNewManager{
   String[] userAccountFileHolder;
   String[] availableTicketHolder;
   String[] mergedDTF;
   String[] newUAF;
   String[] newATF;
   //Constructor
   public OldToNewManager(String[] userAccountFileHolder, String[] availableTicketHolder, String[] mergedDTF){
      this.userAccountFileHolder = userAccountFileHolder;
      this.availableTicketHolder = availableTicketHolder;
      this.mergedDTF = mergedDTF;   
      if(!applyMergedDTF()){
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
   public static boolean writeError(String msg){
      //ErrorLogManager log = new ErrorLogManager);
      return false;
   }
   /*Checks for negative ticknum constraing*/
   public static boolean checkTicketNum(int num){
      return (num>=0)? true : false;
   }
   /*Checks for the new user username constraint*/
   public static boolean newUserCheck(){
   //if name does not match any names in the user list 
   //return true else
      return false;
   }

}