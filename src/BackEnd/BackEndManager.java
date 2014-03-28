package BackEnd;
//used to manage the BackEnd
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
   public static boolean mergeDTF(){
      
      DTFMerger merge = new DTFMerger();
      dtfTemp = merge.mergeDTF();
      return false;
   }
   public static boolean readInUserAccountFile(){
      return false;
   }
   public static boolean readInAvailableTicketsFile(){
      return false;
   }
   public static boolean updateFiles(){
      return false;
   }

}