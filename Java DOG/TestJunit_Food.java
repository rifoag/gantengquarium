import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class TestJunit_Food {

   int x_pos = 500;
   Food f = new Food(500);
   int speed = 34;

   @Test
   public void testAdd() {
      // konstruktor
      assertEquals(f.getAbsis(), x_pos, 0.5);

      // getter speed
    //   assertEquals(speed,f.getSpeed());
   }
}