import org.junit.Test;
import static org.junit.Assert.*;

public class TestJunit_Snail {

   Snail s = new Snail();
   LinkedList<Coin> listCoin = new LinkedList<Coin>();
   Integer money = 0;
   Coin cc = new Coin();

   @Test
   public void testAdd() {
       assertEquals(s.getOrdinat(), 440, 0.1);
       s.move(0.1, listCoin, money);
       assertEquals(s.getOrdinat(), 440, 0.1);
       double abs = s.getAbsis();
       assertEquals(s.getAbsis(), abs, 0.1);
       listCoin.add(cc);
       s.move(0.1, listCoin, money);
       assertFalse(s.getAbsis() == abs);
       Coin cc2 = s.getNearestCoin(listCoin);
       assertTrue(cc.equals(cc2));   
   }
}