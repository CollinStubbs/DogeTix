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
   //create - DECISION AND LOOP COVERAGE
   /*
   
   Looping:
      Our backend was not designed in a way that is optimal for looping coverage.
      The best example we can give is with our create function. This function
      has a loop in it that checks the name with every other name in the UserAccountFile.
      To test this function with zero loops the User Account File must be empty.
      To safely test our other methods we thought it best to keep the User Account File intact
      and to give a simulation in the comments below of what could happen.
      
      First for the loop coverage is 0 loops (this is assuming empty UAF):
      
      @Test public void createNoLoopsTest() {
         Assert.assertEquals(true, OldToNewManager.create("01_Collin__________BS_000000000"));
      }
      
      Second is the 1 loop (this is asusming the UserAccountFile is populated with 1 user):
      
      @Test public void createTest() {
         Assert.assertEquals(true, OldToNewManager.create("01_UNIQUENAME1_____BS_000000000"));
      }
      
      Third is the multiple times loop (this is assuming the UAF is populated with multiple users):
      
      @Test public void createTest() {
         Assert.assertEquals(true, OldToNewManager.create("01_CollinCollin____BS_000000000"));
      }
   Decision:
      For our decision part we want to cover every entry and exit possible in every possible way.
      There are two entries within the method, a for loop for looping over user's and an if statement
      that checks their names with the new one. To enter the for loop we would just run createTest below.
      This has been designed as a unique username to exit as well.
   */
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
