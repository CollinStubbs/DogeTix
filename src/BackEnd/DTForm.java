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
   
   public void DTForm(String transType, String userName, String userType, String availCredit){
      this.transType = transType;
      this.userName = userName;
      this.userType = userType;
      this.availCredit = availCredit;
   }
   public String getTType(){
      return transType;
   }
   public String getName(){
      return userName;
   }
   public String getUType(){
      return userType;
   }
   public String getCredit(){
      return availCredit;
   }
}