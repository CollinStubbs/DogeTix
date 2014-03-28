package BackEnd;
/****************************************************
   This class is used to handle all back end components.
   It is the top level of all backed end instances.
   From this class: the dtf files are merged, all files are read in,
   and the new files are created.
   
   TODO:
      implement file read-ins
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
      else if(!updateFiles()){
         a = new ErrorLogManager("fatal", "creating the new files");
      }
     
   }
   //creates a DTFMerger instance and uses it to merge the DTF's which are then stored in dtfTemp
   public static boolean mergeDTF(){
    //DONE  
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
      return false;
   }
   //reads in the data from the available ticket files and stores it in atfTemp
   public static boolean readInAvailableTicketsFile(){
      return false;
   }
   //creates an instance of OldToNewManager and uses it to create the new files
   public static boolean updateFiles(){
   //DONE
      OldToNewManager otnm = new OldToNewManager(uafHolder, atfHolder, dtfHolder);
      
      return false;
   }

}