package BackEnd;

import org.junit.Assert;
import static org.junit.Assert.*;
import org.junit.Before;
import org.junit.Test;


public class BackEndManagerTest {
   

   /** Fixture initialization (common initialization
    *  for all tests). **/
   @Before public void setUp() {
   }


   @Test public void mergeDTFTest() {
      Assert.assertEquals(true, BackEndManager.mergeDTF());
   }
   
   @Test public void readinUAFTest() {
      Assert.assertEquals(true, BackEndManager.readInUserAccountFile());
   }
   
   @Test public void readinATFTest() {
      Assert.assertEquals(true, BackEndManager.readInAvailableTicketsFile());
   }
   
   @Test public void updateFilesTest() {
      Assert.assertEquals(false, BackEndManager.updateFiles());
   }
   
   @Test public void applyMergedDTFTest() {
      Assert.assertEquals(true, OldToNewManager.applyMergedDTF());
   }
   
   @Test public void createTest() {
      Assert.assertEquals(true, OldToNewManager.create("01_Collin__________BS_000000000"));
   }
   
   @Test public void deleteTest() {
      Assert.assertEquals(true, OldToNewManager.delete("02_ANDREWGULLA_____SS_000001000"));
   }
   
   @Test public void sellTest() {
      Assert.assertEquals(true, OldToNewManager.sell("03_ANEVENT_____________ANDREWGULLAA____030_000000100"));
   }
   
   @Test public void buyTest() {
      Assert.assertEquals(true, OldToNewManager.buy("04_ANEVENT_____________ANDREWGULLAA____003_000000100"));
   }
   
   @Test public void refundTest() {
      Assert.assertEquals(true, OldToNewManager.refund("05_ANDREWGULLAAA_______ANDREWGULLAA___000000300"));
   }
   
   @Test public void addcreditTest() {
      Assert.assertEquals(true, OldToNewManager.addcredit("02_ANDREWGULLAAA___SS_000001000"));
   }
   @Test public void writenewUAFTest() {
      Assert.assertEquals(true, OldToNewManager.writeToNewUAFFile());
   }
   @Test public void writenewATFTest() {
      Assert.assertEquals(true, OldToNewManager.writeToNewATFFile());
   }
}
