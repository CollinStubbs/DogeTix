package BackEnd;
/********************************************
   This class is used to handle updating and
  creating the new files. BackEndManager creates
  an instance of this when all the old files are 
  storef and ready.
  
  TODO:
   implment methods and error writing
********************************************/


public class OldToNewManager{
   String[] userAccountFileHolder;
   String[] availableTicketHolder;
   String[] mergedDTF;
   String[] newUAF;
   String[] newATF;
   
   //Constructor
   public OldToNewManager(String[] userAccountFileHolder, String[] availableTicketHolder, String[] mergedDTF){
      ErrorLogManager a;
      this.userAccountFileHolder = userAccountFileHolder;
      this.availableTicketHolder = availableTicketHolder;
      this.mergedDTF = mergedDTF; 
        
      if(!applyMergedDTF()){
      //write new error
      }
      else if(!writeToNewUAFFile()){
      //write new error
      }
      else if(!writeToNewATFFile()){
      //write new error
      }
   }
   
   //used to apply the data from the merged DTF to the user account files
   public static boolean applyMergedDTF(){ 
      ErrorLogManager a;
      //example of a way to check neg tick errors
         //String transaction - a substring of the dtf line pertaining to the transaction
      /*if(!checkTicketNum(num)){
         //a = new ErrorLogManager("constraint", "negative ticket number", transaction);
      }*/

      return false;
   }
   
   //used to wrie a new uaf file
   public static boolean writeToNewUAFFile(){
      return false;
   }
   
   //used to write a new atf file
   public static boolean writeToNewATFFile(){
      return false;
   }
   
   //used to create an instance of ErrorLogManager in the case of an error
   public static boolean writeError(String msg){
      //ErrorLogManager log = new ErrorLogManager);
      return false;
   }
   
   //used to check for negative ticknum constraint
   //param - num is the number of tickets
   public static boolean checkTicketNum(int num){
      return (num>=0)? true : false;
   }
   
   //used to check for the new user username constraint
   public static boolean newUserCheck(){
   //if name does not match any names in the user list 
   //return true else
      return false;
   }

}

public class DTForm
{
   public String transType;
   public String userName;
   public String userType;
   public String availCredit;
   
   public DTForm(String transType, String userName, String userType, String availCredit){
      this.transType = transType;
      this.userName = userName;
      this.userType = userType;
      this.availCredit = availCredit;
   }
 }