/* TEAM 12
 *
 * Matthew Militante, 100457072
 * Collin Stubbs, 100454604
 * Andrew Gulla, 100395486
 *
 * This is the backend of our ticket system, DogeTix.
 * It reads in the previous days User Accounts file and 
 * Available Tickets File and then applies all transactions
 * from a merged set of daily transaction files to these files 
 * Then it produces a new Current User Accounts File and new 
 * Available Tickets File for the next front end run
 *
 */
import java.util.*;
import java.io.*;


public class Backend{

    public String readFile(String fileName){
        String returnValue = "";
        FileReader file = null;
        String line = "";
        try {
            file = new FileReader(fileName);
            BufferedReader reader = new BufferedReader(file);
            while ((line = reader.readLine()) != null) {
                returnValue += line + "\n";
            }
        }catch (FileNotFoundException e) {
            throw new RuntimeException("File not found");
        }catch (IOException e){
            throw new RuntimeException("IO Error occured");
        }finally{
            if (file != null) {
                try{
                    file.close();
                }catch(IOException e){
                    e.printStackTrace();
                }
            }
        }
        return returnValue;
    }

    public static void main(String[] args){

        String inputDTFfile = "DailyTransactionFile.txt";


    }
}
