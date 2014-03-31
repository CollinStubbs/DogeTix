package BackEnd;
/*************************
This class is used to declare a new object
that will be used to split up sections of 
each instance of the mergedDTF array into a 
new object.
**************************/
public class DTForm
{
   private String transType;
   private String userName;
   private String userType;
   private String availCredit;

   public void setTType(String t){
      transType = t;
   }
   public String getTType(){
      return transType;
   }

   public void setName(String n){
      userName = n;
   }
   public String getName(){
      return userName;
   }

   public void setUType(String u){
      userType = u;
   }
   public String getUType(){
      return userType;
   }

   public void setCredit(String c){
      availCredit = c;
   }
   public String getCredit(){
      return availCredit;
   }
 }