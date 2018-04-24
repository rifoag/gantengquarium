public class Guppy extends Fish {
  private double time;
  private static final int COIN_TIME = 7;

  public Guppy() {
    time = 0;
  }

  public Guppy(int x,int y) {
    super(x,y);
    time = 0;
  }

  public Boolean equals(Guppy other) {
    return super.equals(other) && (this.time == other.time); 
  }

  /**
    Method to move.
   */
  public void move(double diff,LinkedList<Food> listFood) {
    if (isStarving() && !listFood.isEmpty()) {
      // Jika lapar, Guppy bergerak mendekati makanan (jika ada)
      findFood(diff,listFood); 
    } else {
      // bergerak bebas
      super.move(diff);
    }
    fullRate -= diff; // tingkat kekenyangan berkurang
    if (Math.cos(orientation) > 0) {
      if (growth == 1) {
        // draw_image("ikanLv1Right.png", pos.first, pos.second);
      } else if (growth == 2) {
        // draw_image("ikanLv2RightC.png", pos.first, pos.second);
      } else {
        // draw_image("ikanLv3RightC.png", pos.first, pos.second);
      }
    } else {
      if (growth == 1) {
        // draw_image("ikanLv1Left.png", pos.first, pos.second);
      } else if (growth == 2) {
        // draw_image("ikanLv2LeftC.png", pos.first, pos.second);
      } else {
        // draw_image("ikanLv3LeftC.png", pos.first, pos.second);
      }
    }
  }

  /**
    Method to find food.
  */
  public void findFood(double diff , LinkedList<Food> listFood) {
    // Saat lapar, Guppy akan mendekati makanan ikan yang ada di akuarium
    Food near = this.getNearestFood(listFood);
    double deltaY = near.getOrdinat() - this.getOrdinat();
    double deltaX = near.getAbsis() - this.getAbsis();
    orientation = Math.atan2(deltaY , deltaX) * 180 / 3.14159265;
    setPos(this.getAbsis() + SPEED * diff * Math.cos(orientation), this.getOrdinat() + SPEED * diff * Math.sin(orientation));
    eat(near, listFood);
  }

  /**
    Method to eat.
  */
  public void eat(Food feed,LinkedList<Food> listFood) {
    // Guppy memakan makanan ikan yang berada pada radius makannya
    if (!listFood.isEmpty()) {
      if (this.getDistance(feed) <= FOOD_RADIUS) {
        fullRate = FULL_TIME;
        foodEaten++;
        if (foodEaten == FOOD_NEEDED && growth < 3) {
          growth++;
          foodEaten = 0;
        }
        listFood.remove(feed);
      }
    }
  }

  /**
    Method to produce coins.
  */
  public void produceCoin(double diff,LinkedList<Coin> listCoin) {
    // Guppy mengeluarkan koin setiap periode tertentu
    if (time >= COIN_TIME) {
      Coin produced = new Coin(growth * 5,this.getAbsis(),this.getOrdinat());
      time = 0;
      listCoin.add(produced);
    } else {
      time += diff;
    }
  }

  /**
    Method to get nearest food.
  */
  public Food getNearestFood(LinkedList<Food> listFood) {
    // Mengembalikan Food terdekat ke Guppy pada listFood
    Node<Food> temp = listFood.getHead();
    Food minFood = temp.getData();
    temp = temp.getNext();
    while (temp != null) {
      if (this.getDistance(temp.getData()) < this.getDistance(minFood)) {
        minFood = temp.getData();
      }
      temp = temp.getNext();
    }
    return minFood;
  }

  /**
    Main Method.
  */
  public static void main(String [] args) {
    Guppy g = new Guppy();
    System.out.println(g.toString());
    LinkedList<Food> listFood = new LinkedList<Food>();
    g.move(0.03,listFood);
    System.out.println(g.toString());
  }
}