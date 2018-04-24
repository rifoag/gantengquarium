import org.junit.Test;
import static org.junit.Assert.*;

public class TestJunit_Coin {

   Coin cc = new Coin(30, 100, 200);
   Coin cc2 = new Coin(30, 100, 200);

   @Test
   public void testAdd() {
      // test ctor
      assertEquals(100, cc.getAbsis(), 0.1);
      assertEquals(200, cc.getOrdinat(), 0.1);
      assertEquals(30, cc.getVal());

      // method
      assertTrue(cc.equals(cc2));
      cc.move(1);
      assertEquals(cc.getOrdinat(), 240, 0.1);
   }
}