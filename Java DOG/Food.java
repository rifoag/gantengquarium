public class Food extends Entity implements movingObject {
  private static final int FOOD_SPEED = 34;

  public Food() {}

  public Food(int x) {
    super(x,100);
  }

  public int getSpeed() {
    return FOOD_SPEED;
  }

  public void move(double diff) {}

  /**
  *Method to move.
  */
  public void move(double diff,LinkedList<Food> listFood) {
    if (this.getOrdinat() < 480) {
      this.setPos(this.getAbsis(), this.getOrdinat() + FOOD_SPEED * diff);
    }
    if (this.getOrdinat() < 450) {
      /* draw_image("pillfood.png", pos.first, pos.second); */
    } else {
      listFood.remove(this);
    }
  }
  
  /**
    Main Program to test.
   */
  public static void main(String[] args) { // Main Program
    Food f = new Food(300);
    System.out.println(f.toString());
  }
}