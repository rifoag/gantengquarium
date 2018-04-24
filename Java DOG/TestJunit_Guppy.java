import org.junit.Test;
import static org.junit.Assert.*;

public class TestJunit_Guppy {

   Guppy gg = new Guppy();
   Guppy gg2 = new Guppy();
   LinkedList<Food> listFood = new LinkedList<Food>();

   @Test
   public void testAdd() {
       assertFalse(gg.equals(gg2));
       gg.setPos(610, 100);
       gg2.setPos(610, 100);
       gg.setFullRate(0);
       gg.setGrowth(1);
       gg.setOrientation(1);
       gg2.setFullRate(0);
       gg2.setGrowth(1);
       gg2.setOrientation(1);
       assertTrue(gg.equals(gg2));
       gg.move(1);
       assertFalse(gg.equals(gg2));

       double or = gg.getOrientation();
       Food makan = new Food(200);
       listFood.add(makan);
       gg.findFood(1, listFood);
       assertFalse(gg.getOrientation() == or);

       Food f2 = gg.getNearestFood(listFood);
       assertEquals(makan, f2);
   }
}