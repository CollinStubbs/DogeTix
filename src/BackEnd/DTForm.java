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
   public void setName(String n){
      userName = n;
   }
   public void setUType(String u){
      userType = u;
   }
   public void setCredit(String c){
      availCredit = c;
   }
 }