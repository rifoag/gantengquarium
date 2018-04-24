import java.util.Random;

public abstract class Entity {
  protected double x;
  protected double y;

  /**
    Ctor.
   */
  public Entity() {
    Random rand = new Random();
    x = rand.nextDouble() * 640;
    y = rand.nextDouble() * 480;
  }

  /**
    Ctor user defined.
   */
  public Entity(double x,double y) {
    Random rand = new Random();
    if (x == -1) {
      this.x = rand.nextDouble() * 640;
    }
    if (y == -1) {
      this.y = rand.nextDouble() * 480;
    }
  }

  public double getAbsis() {
    return this.x;
  }

  public double getOrdinat() {
    return this.y;
  }

  public void setPos(double x,double y) {
    this.x = x;
    this.y = y;
  }

  public Boolean equals(Entity other) {
    return this.getAbsis() == other.getAbsis() && this.getOrdinat() == other.getOrdinat();
  }

  /**
    Method to get distance between 2 objects.
   */
  public double getDistance(Entity other) {
    double evX = Math.pow(this.getAbsis() - other.getAbsis(),2);
    double evY = Math.pow(this.getOrdinat() - other.getOrdinat(),2);
    return Math.sqrt(evX + evY);
  }

  public String toString() {
    return "(" + this.getAbsis() + "," + this.getOrdinat() + ")";
  }
}