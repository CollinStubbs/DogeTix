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
      Assert.assertEquals(true, OldToNewManager.sell("03_ANDREWGULLAA____SS_000001000"));
   }
}
