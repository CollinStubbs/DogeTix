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
   ArrayList<String> newUAFAR;
   String[] mergedDTF;
   String[] newUAF;
   String[] newATF;

   
   //Constructor
   public OldToNewManager(String[] userAccountFileHolder, String[] availableTicketHolder, String[] mergedDTF){
      ErrorLogManager a;
      this.userAccountFileHolder = userAccountFileHolder;
      this.availableTicketHolder = availableTicketHolder;
      this.mergedDTF = mergedDTF; 
      newUAFAR = new ArrayList<String>(Arrays.asList(userAccountFileHolder));
        
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
      String holder;
      String type;
      boolean b;
      for(int i = 0; i < mergedDTF.length; i++){
         holder = mergedDTF[i];
         type = holder.substring(0, 2);
         if(type == "01"){
            b = create(holder);
            if(b == false){
               a = new ErrorLogManager("fatal","error from creation of account");
               System.exit(0);
            }
         }
         else if(type == "02"){
            b = delete(holder);
            if(b == false){
               a = new ErrorLogManager("fatal", "error from deletion of account");
               System.exit(0);
            }
         }
         else if(type == "03"){
            b =  sell(holder);
            if(b == false){
               a = new ErrorLogManager("fatal", "error from selling of tickets");
               System.exit(0);
            }
         }
         else if(type == "04"){
            b = buy(holder);
            if(b == false){
               a = new ErrorLogManager("fatal", "error from buying of tickets");
               System.exit(0);
            }
         }
         else if(type == "05"){
            b = refund(holder);
            if(b == false){
               a = new ErrorLogManager("fatal", "error from refund of tickets");
               System.exit(0);
            }
         }
         else if(type == "06"){
            b = addcredit(holder);
            if(b == false){
               a = new ErrorLogManager("fatal", "error from adding of credits");
               System.exit(0);
            }
         }
         else if(type == "07"){
            b = true;
         }
         else{
            a = new ErrorLogManager("fatal", "error from reading of dtf file");
            System.exit(0);
         }
      }
          
      return true;
   }
   public static boolean create(String x){
      String nameholder;
      nameholder = x.substring(3, 18);
      nameholder = nameholder.substring(0, nameholder.indexOf("__"));
      //checks if name already exists
      for(int i = 0; i < userAccountFileHolder.length; i++){
         if(userAccountFileHolder[i].startsWith(nameholder)){
            ErrorLogManager a = new ErrorLogManager("constraint", "username already exists", "in create");
            System.exit(0);
         }
      }
      newUAFAR.add(nameholder);
      return true;
      //add user check names
   }
   public static boolean delete(String x){
   
   }
   public static boolean sell(String x){
   
   }
   public static boolean buy(String x){
   
   }
   public static boolean refund(String x){
   
   }
   public static boolean addcredit(String x){
   
   }
   public static boolean end(String x){
   
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

