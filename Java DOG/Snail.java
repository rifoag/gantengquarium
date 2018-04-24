public class Snail extends Entity {
  private static final int COIN_RADIUS = 15; //Radius Coin yang dapat diambil siput
  private static final int SPEED = 50; // Speed snail

  /**
    Ctor snail. Selalu berada di dasar.
   */
  public Snail() {
    super(-1,440);
  }

  /**
    Ctor user defined.
   */
  public Snail(int x,int y) {
      super(x,y);
  }

  /**
    Method to move the damn snail.
   */
  public void move(double diff,LinkedList<Coin> listCoin,Integer money) {
    // Siput hanya berada di dasar akuarium
    // Siput hanya bergerak ke kiri dan ke kanan
    // Siput hanya bergerak saat terdapat koin di akuarium
    // Siput berdekat ke koin terdekat
    if (!listCoin.isEmpty()) {
      Coin near = this.getNearestCoin(listCoin);
      if (near.getAbsis() > this.getAbsis()) {
        setPos(this.getAbsis() + SPEED * diff * 1, this.getOrdinat());
        // draw_image("snailRight.png", pos.first, pos.second);
      } else if (near.getAbsis() < this.getAbsis()) {
        setPos(this.getAbsis() + SPEED * diff * (-1), this.getOrdinat());
        // draw_image("snailLeft.png", pos.first, pos.second);
      } else {
        // draw_image("snailRight.png", pos.first, pos.second);
      }
      takeCoin(near, listCoin, money);
    } else {
      // draw_image("snailRight.png", pos.first, pos.second);
    }
  }
  
  /**
    Method to get nearest coin.
   */
  public Coin getNearestCoin(LinkedList<Coin> listCoin) {
    // mengembalikan Coin terdekat dari posisi Snail
    Node<Coin> temp = listCoin.getHead();
    Coin minCoin = temp.getData();
    temp = temp.getNext();
    while (temp != null) {
      if (this.getDistance(temp.getData()) < this.getDistance(minCoin)) {
        minCoin = temp.getData();
      }
      temp = temp.getNext();
    }
    return minCoin;
  }
  
  /**
    Method take coin.
   */
  public void takeCoin(Coin cc, LinkedList<Coin> listCoin, Integer money) {
    // mengambil Coin cc bila Coin berada pada radius (COIN_RADIUS)
    if (this.getDistance(cc) <= COIN_RADIUS) {
      money += cc.getVal();
      listCoin.remove(cc);
    }
  }

  /**
    Main Method to test the damn shits.
   */
  public static void main(String[] args) {
    Snail s = new Snail();
    double diff = 0.02;
    LinkedList<Coin> listCoin = new LinkedList<Coin>();
    Coin cc = new Coin();
    listCoin.add(cc);
    int money = 0;
    System.out.println(s.toString());
    s.move(diff, listCoin, money);
    System.out.println(s.toString());
  }
}