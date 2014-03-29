package BackEnd;

import java.util.*;
import java.io.*;
/****************************************************
   This class is used to handle all back end components.
   It is the top level of all backed end instances.
   From this class: the dtf files are merged, all files are read in,
   and the new files are created.
******************************************************/
public class BackEndManager{
   static private String[] uafTemp;
   static private String[] atfTemp;
   static private String[] dtfTemp;
   
   public static void main(String[] args){
      ErrorLogManager a;
   
      if(!mergeDTF()){
         a = new ErrorLogManager("fatal", "merging the Daily Transaction Files");
      }
      else if(!readInUserAccountFile()){
         a = new ErrorLogManager("fatal", "reading in user account file");
      }
      else if(!readInAvailableTicketsFile()){
         a = new ErrorLogManager("fatal", "reading in available ticket file");
      }
      else if(updateFiles()){
         a = new ErrorLogManager("fatal", "creating the new files");
      }
     
   }
   //creates a DTFMerger instance and uses it to merge the DTF's which are then stored in dtfTemp
   public static boolean mergeDTF(){

      DTFMerger merge = new DTFMerger();
      dtfTemp = merge.mergeDTF();
      if(dtfTemp.length == 0){
         return false;
      }
      else{
         return true;
      }
   }
   //reads in the data from the user account file and stores it in uafTemp
   public static boolean readInUserAccountFile(){
      ArrayList<String> temp = new ArrayList<String>();
      try{
         Scanner scan = new Scanner( new File("/DogeTix/src/BackEnd/userAccountsFile.txt"));
         while(scan.hasNextLine()){
            temp.add(scan.nextLine());
         }
      }
      catch(IOException e){
         System.out.println(e);
         return false;
      }
      uafTemp = temp.toArray(new String[0]);
      return true;
   }
   //reads in the data from the available ticket files and stores it in atfTemp
   public static boolean readInAvailableTicketsFile(){
      ArrayList<String> temp = new ArrayList<String>();
      try{
         Scanner scan = new Scanner( new File("/DogeTix/src/BackEnd/availableTicketsFile.txt"));
         while(scan.hasNextLine()){
            temp.add(scan.nextLine());
         }
      }
      catch(IOException e){
         System.out.println(e);
         return false;
      }
      atfTemp = temp.toArray(new String[0]);
      return true;
   }
   //creates an instance of OldToNewManager and uses it to create the new files
   public static boolean updateFiles(){
  
      OldToNewManager otnm = new OldToNewManager(uafTemp, atfTemp, dtfTemp);
      
      return false;
   }

}