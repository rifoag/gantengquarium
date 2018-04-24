public class Coin extends Entity implements movingObject {
  private int value;

  public Coin() {
    value = 15;
  }
  
  public Coin(int val,double x,double y) {
    super(x,y);
    value = val;
  }

  public Boolean equals(Coin other) {
    return super.equals(other) && this.value == other.value;
  }

  public void setVal(int val) {
    value = val;
  }

  public int getVal() {
    return value;
  }

  /**
    Method to move.
   */
  public void move(double diff) {
    if (this.getOrdinat() < 450) {
      this.setPos(this.getAbsis(), this.getOrdinat() + diff * 40);
    }
  }

  /**
    Method to print.
   */
  public String toString() {
    return "(" + this.getAbsis() + "," + this.getOrdinat() + "," + value + ")";    
  }

  /**
    Main program to test.
   */
  public static void main(String [] args) {
    Coin c = new Coin();
    System.out.println(c.toString());
    System.out.println(c.getVal());
  }
}