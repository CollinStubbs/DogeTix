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
   
   @Test public void applyMergedDTFTest() {
      Assert.assertEquals(true, OldToNewManager.applyMergedDTF());
   }
}
