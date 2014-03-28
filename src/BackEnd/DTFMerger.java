package BackEnd;

import java.util.*;
import java.io.*;
/*******************************
   This class is used to handle the dtf files.
   It reads them in and merges them together 
   for use in the OldToNewManager instance.
*******************************/
public class DTFMerger{

   static ArrayList<String> mergedDTF;
   
   //constructor
   public DTFMerger(){
      mergeDTF();
   }
   
   //used to read in all dtf files and merge them.
   public static String[] mergeDTF(){
   //this section reads in all the text file names
      mergedDTF = new ArrayList<String>();
      File f = new File("/DTFFolder/");
      FilenameFilter filter = 
         new FilenameFilter(){
            public boolean accept(File dir, String name){
               return name.toLowerCase().endsWith(".txt");// or .dtf
            }
         };
      
      File[] files = f.listFiles(filter);
      Scanner scan;
      try{
      //for every dtf file in the directory
         for(File file : files){
            scan = new Scanner(file);
            while(scan.hasNextLine()){
            //add the line to the arraylist
               mergedDTF.add(scan.nextLine());
            }
         }
      }
      catch(IOException e){
         System.out.println(e);
         System.exit(0);
      }
      
      
      //merge the files into mergedDTF string array 
      return (String[])mergedDTF.toArray();
   }
}
//*************NOTE THIS ASSUMES THAT THE merged DTF FILE IS NOT KEPT which is unclear in the doc*/