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
   @Test public void createWithTooMuchMoneyTest() {
      Assert.assertEquals(false, OldToNewManager.create("01_Collin__________BS_009999999"));
   }
   @Test public void createWithNonUniqueNameTest() {
      Assert.assertEquals(false, OldToNewManager.create("01_ANDREWGULLA_____BS_000000000"));
   }
   
   @Test public void deleteTest() {
      Assert.assertEquals(true, OldToNewManager.delete("02_ANDREWGULLA_____SS_000001000"));
   }
   
   @Test public void sellTest() {
      Assert.assertEquals(true, OldToNewManager.sell("03_ANEVENT_____________ANDREWGULLAA____030_000000100"));
   }
   @Test public void sellMoreThan100Test() {
      Assert.assertEquals(false, OldToNewManager.sell("03_ANEVENT1____________ANDREWGULLAA____101_000000100"));
   }
   @Test public void sellMaxPriceTest() {
      Assert.assertEquals(false, OldToNewManager.sell("03_ANEVENT2____________ANDREWGULLAA____100_099000100"));
   }
   @Test public void buyTest() {
      Assert.assertEquals(true, OldToNewManager.buy("04_ANEVENT_____________ANDREWGULLAA____003_000000100"));
   }
   @Test public void buyMoreThan4Test() {
      Assert.assertEquals(false, OldToNewManager.buy("04_ANEVENT_____________ANDREWGULLAA____100_000000100"));
   }
   //checks if ticket num can go negative
   //note: the event hadonly 3 tickets left before the transaction
   @Test public void buyUntilNegativeTest() {
      Assert.assertEquals(false, OldToNewManager.buy("04_ANEVENTfortesting___ANDREWGULLAA____004_000000100"));
   }
   @Test public void refundTest() {
      Assert.assertEquals(true, OldToNewManager.refund("05_ANDREWGULLAAA_______ANDREWGULLAA___000000300"));
   }
   
   @Test public void addcreditTest() {
      Assert.assertEquals(true, OldToNewManager.addcredit("02_ANDREWGULLAAA___SS_000001000"));
   }
   @Test public void addcreditMoreThan1000Test() {
      Assert.assertEquals(true, OldToNewManager.addcredit("02_ANDREWGULLAAA___SS_000001001"));
   }
   @Test public void writenewUAFTest() {
      Assert.assertEquals(true, OldToNewManager.writeToNewUAFFile());
   }
   @Test public void writenewATFTest() {
      Assert.assertEquals(true, OldToNewManager.writeToNewATFFile());
   }
}
