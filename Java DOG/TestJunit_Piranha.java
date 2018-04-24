import org.junit.Test;
import static org.junit.Assert.*;

public class TestJunit_Piranha {

   Piranha p1 = new Piranha();
   Piranha p2 = new Piranha();
   LinkedList<Guppy> listGuppy = new LinkedList<Guppy>();
   LinkedList<Coin> listCoin = new LinkedList<Coin>();
   Guppy g1 = new Guppy();
   Coin cc = new Coin();

   @Test
   public void testAdd() {
      assertTrue(p1.getPrice() == 1000);
      assertFalse(p1.equals(p2));

      listGuppy.add(g1);
      listCoin.add(cc);
      double or = p1.getOrientation();
      p1.findFood(1, listGuppy, listCoin);
      assertFalse(or == p1.getOrientation());

      Piranha p3 = p1;
      assertTrue(p1.equals(p3));
      p1.move(0.1);
   }
}