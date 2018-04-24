import org.junit.Test;
import static org.junit.Assert.*;

public class TestJunit_Aquarium {

   Aquarium myAquarium = new Aquarium();

   @Test
   public void testAdd() {
      assertTrue(myAquarium.isThereIsNoFish());
      myAquarium.addGuppy();
      assertFalse(myAquarium.isThereIsNoFish());
   }
}