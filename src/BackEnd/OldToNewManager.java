
package BackEnd;
import java.util.*;
import java.io.*;
/********************************************
   This class is used to handle updating and
  creating the new files. BackEndManager creates
  an instance of this when all the old files are 
  storef and ready.
  
  TODO:
   implment methods and error writing
********************************************/


public class OldToNewManager{
   static String[] userAccountFileHolder;
   static String[] availableTicketHolder;
   static ArrayList<String> newUAFAR;
   static ArrayList<String> newATFAF;
   static String[] mergedDTF;

   
   //Constructor
   public OldToNewManager(String[] userAccountFileHolder, String[] availableTicketHolder, String[] mergedDTF){
      ErrorLogManager a;
      this.userAccountFileHolder = userAccountFileHolder;
      this.availableTicketHolder = availableTicketHolder;
      this.mergedDTF = mergedDTF; 
      
   
      if(!applyMergedDTF()){
         a = new ErrorLogManager("fatal", "parsing error");
         System.exit(0);
      //write new error
      }
      else if(!writeToNewUAFFile()){
         a = new ErrorLogManager("fatal", "error writing to user account file");
         System.exit(0);
      //write new error
      }
      else if(!writeToNewATFFile()){
         a = new ErrorLogManager("fatal", "error writing to available ticket file");
         System.exit(0);
      //write new error
      }
   }
   
   //used to apply the data from the merged DTF to the user account files
   public static boolean applyMergedDTF(){ 
      ErrorLogManager a;
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
      newUAFAR = new ArrayList<String>(Arrays.asList(userAccountFileHolder));
   
      String nameholder;
      nameholder = x.substring(3, 18);
      nameholder = nameholder.substring(0, nameholder.indexOf("__"));
      //checks if name already exists
      for(int i = 0; i < userAccountFileHolder.length; i++){
         if(userAccountFileHolder[i].startsWith(nameholder)){
            ErrorLogManager a = new ErrorLogManager("constraint", "username already exists", "error in create");
            System.exit(0);
         }
      }
      newUAFAR.add(nameholder);
      userAccountFileHolder = (String[]) newUAFAR.toArray();
      
      return true;
      //add user check names
   }
   public static boolean delete(String x){
      newUAFAR = new ArrayList<String>(Arrays.asList(userAccountFileHolder));
   
      String nameholder;
      nameholder = x.substring(3, 18);
      nameholder = nameholder.substring(0, nameholder.indexOf("__"));
      
      newUAFAR.remove(nameholder);
      userAccountFileHolder = (String[]) newUAFAR.toArray();
      return true;
      
   }
   public static boolean sell(String x){
      newATFAF = new ArrayList<String>(Arrays.asList(availableTicketHolder));
      //evN is 19
      String eNH;
      eNH = x.substring(3, 46);
      //eNH = eNH.substring(0, eNH.indexOf("__"));
      newATFAF.add(eNH);
      availableTicketHolder = (String[]) newATFAF.toArray();
      
      return true;
   }
   public static boolean buy(String x){
      String eventholder;
      String nameholder;
      int tnum = Integer.parseInt(x.substring(39, 42));
      eventholder = x.substring(3, 22);
      nameholder = x.substring(23, 38);
      String ppt = x.substring(42, 49);
      for(int i = 0; i < availableTicketHolder.length; i++){
         if(availableTicketHolder[i].contains(nameholder) && availableTicketHolder[i].startsWith(eventholder)){
            int actTnum = Integer.parseInt(availableTicketHolder[i].substring(36, 39));
            
            if((actTnum-tnum) <0){
               ErrorLogManager a = new ErrorLogManager("constraint", "error buying tickets", "not enough tickets");
               System.exit(0);
            }
            else{
               actTnum = actTnum - tnum;
            }
            //write to array
            
            String line = eventholder + "_" + nameholder + "_" + (Integer.toString(actTnum)) + ppt;
            availableTicketHolder[i] = line;
         }
      }
   
      return true;
   }
   public static boolean refund(String x){
      String bNH;
      String sNH;
      bNH = x.substring(3, 18);
      sNH = x.substring(19, 34);
      bNH = bNH.substring(0,bNH.indexOf("__"));
      sNH = sNH.substring(0,sNH.indexOf("__"));
      
      String rCH = x.substring(35, 44);
      double refundAmount = Double.parseDouble(rCH);
      
      //to take money from seller
      for(int i = 0; i < userAccountFileHolder.length; i++){
         if(userAccountFileHolder[i].startsWith(sNH)){
            String temp = userAccountFileHolder[i];
            
            String head = temp.substring(0, 19);
            String tail = temp.substring(19, 28);
            double credits = Double.parseDouble(tail);
            credits = credits - refundAmount;
            tail = Double.toString(credits);
            
            while(tail.length() != 9){
               tail = "0"+tail;
            }
            userAccountFileHolder[i] = (head+tail);
         }
      }
      //to add money to buyer
      for(int i = 0; i < userAccountFileHolder.length; i++){
         if(userAccountFileHolder[i].startsWith(bNH)){
            String temp = userAccountFileHolder[i];
            
            String head = temp.substring(0, 19);
            String tail = temp.substring(19, 28);
            double credits = Double.parseDouble(tail);
            credits = credits + refundAmount;
            tail = Double.toString(credits);
            
            while(tail.length() > 9){
               tail = tail.substring(1, tail.length());
            }
            userAccountFileHolder[i] = (head+tail);
         }
      }
      //take money from both and add ticket num to atf
      return true;
   }
   public static boolean addcredit(String x){
      String nameholder;
      String cH;
      nameholder = x.substring(3, 18);
      cH = x.substring(22,31);      
      nameholder = nameholder.substring(0, nameholder.indexOf("__"));
      double addcred = Double.parseDouble(cH);
      
      for(int i = 0; i < userAccountFileHolder.length; i++){
         if(userAccountFileHolder[i].startsWith(nameholder)){
            String temp = userAccountFileHolder[i];
            
            String head = temp.substring(0, 19);
            String tail = temp.substring(19, 28);
            double credits = Double.parseDouble(tail);
            credits = credits + addcred;
            tail = Double.toString(credits);
            
            while(tail.length() > 9){
               tail = tail.substring(1, tail.length());
            }
            userAccountFileHolder[i] = (head+tail);
         }
      }
      return true;
   }

   //used to wrie a new uaf file
   public static boolean writeToNewUAFFile(){
      try{
         BufferedWriter out = new BufferedWriter(new FileWriter("UserAccountFile.txt"));
         for (int i = 0; i < userAccountFileHolder.length; i++) {
            out.write(userAccountFileHolder[i] + "\n");
         }
         out.close();
      } 
      catch (IOException e) {
         ErrorLogManager a = new ErrorLogManager("fatal", "error writing uaf file");
      }
      return true;
   }
   
   //used to write a new atf file
   public static boolean writeToNewATFFile(){
      try{
         BufferedWriter out = new BufferedWriter(new FileWriter("AvailableTicketFile.txt"));
         for (int i = 0; i < availableTicketHolder.length; i++) {
            out.write(availableTicketHolder[i] + "\n");
         }
         out.close();
      } 
      catch (IOException e) {
         ErrorLogManager a = new ErrorLogManager("fatal", "error writing uaf file");
      }
      return false;
   }
      
   
}

