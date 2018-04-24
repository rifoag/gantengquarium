import java.util.Random;

public abstract class Fish extends Entity implements movingObject {
  protected static final int FULL_TIME = 10;
  protected static final int STARVE_TIME = -12;
  protected static final int FOOD_NEEDED = 4;
  protected static final int FOOD_RADIUS = 27;
  protected int SPEED = 115;
  protected int growth;
  protected double fullRate;
  protected double orientation;
  protected int foodEaten;

  public Fish() {
    Random rand = new Random();
    growth = 1;
    fullRate = FULL_TIME;
    orientation = rand.nextDouble() * 360;
    foodEaten = 0;
  }

  public Fish(int x,int y) {
    super(x,y);
    Random rand = new Random();
    growth = 1;
    fullRate = FULL_TIME;
    orientation = rand.nextDouble() * 360;
    foodEaten = 0;
  }

  public Boolean equals(Fish other) {
    return super.equals(other) && (growth == other.growth) && (fullRate == other.fullRate) && (orientation == other.orientation) && (foodEaten == other.foodEaten);
  }

  public double getFullRate() {
    return fullRate;
  }

  public double getOrientation() {
    return orientation;
  }
  
  public int getGrowth() {
    return growth;
  }

  public void setFullRate(double f) {
    fullRate = f;
  }

  public void setOrientation(double o) {
    orientation = o;
  }

  public void setGrowth(int g) {
    growth = g;
  }

  public void restoreFullRate() {
    fullRate = FULL_TIME;
  }

  public Boolean isStarving() {
      return (fullRate <= 0);
  }

  public void move(double diff) {
    if (this.getAbsis() > 640 - 40 || this.getAbsis() < 40 || this.getOrdinat() < 130 || this.getOrdinat() > 400) {
      Random rand = new Random();
      if (this.getAbsis() > 640 - 40 && this.getOrdinat() < 130) {
        // pojok kanan atas
        orientation = 180 + rand.nextDouble() * 90;
        this.setPos(640 - 40,130);
      } else if (this.getAbsis() > 640 - 40 && this.getOrdinat() > 400) {
        // pojok kanan bawah
        orientation = 90 + rand.nextDouble() * 90;
        this.setPos(640 - 40,400);
      } else if (this.getAbsis() < 40 && this.getOrdinat() > 400) {
        // pojok kiri bawah
        orientation = rand.nextDouble() * 90;
        this.setPos(40, 400);
      } else if (this.getAbsis() < 40 && this.getOrdinat() < 130) {
        // pojok kiri atas
        orientation = 270 + rand.nextDouble() * 90;
        this.setPos(40,130);
      } else if (this.getAbsis() > 640 - 40) {
        // kiri
        orientation = rand.nextDouble() * 180 - 90;
        this.setPos(640 - 40, this.getOrdinat());
      } else if (this.getAbsis() < 40) {
        // kanan
        orientation = 90 + rand.nextDouble() * 180;
        this.setPos(40, this.getOrdinat());
      } else if (this.getOrdinat() < 130) {
        // atas
        orientation = 180 + rand.nextDouble() * 180;
        this.setPos(this.getAbsis(),130);
      } else {
        // bawah
        orientation = 180 + rand.nextDouble() * 180;
        this.setPos(this.getAbsis(),400);
      }
    }
    this.setPos(this.getAbsis() + SPEED * diff * Math.cos(orientation),this.getOrdinat() + SPEED * diff * Math.sin(orientation));
  } 
}