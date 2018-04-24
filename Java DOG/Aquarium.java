public class Aquarium {
  private static final int MAX_LENGTH = 640;
  private static final int MAX_WIDTH = 480;
  private Integer money;
  private LinkedList<Guppy> listGuppy;
  private LinkedList<Piranha> listPiranha;
  private LinkedList<Coin> listCoin;
  private LinkedList<Snail> listSnail;
  private LinkedList<Food> listFood;

  /**
    Ctor.
   */
  public Aquarium() {
    listGuppy = new LinkedList<Guppy>();
    listPiranha = new LinkedList<Piranha>();
    listCoin = new LinkedList<Coin>();
    listSnail = new LinkedList<Snail>();
    listFood = new LinkedList<Food>();
    money = 10000;
  }

  /**
    Ctor defined.
   */
  public void moveAll(double diff) {
    // menggerakkan semua entity yang ada di Aquarium
    moveGuppy(diff);
    moveSnail(diff);
    movePiranha(diff);
    moveFood(diff);
    moveCoin(diff);
  }

  /**
    Method to move the damn guppy.
   */
  public void moveGuppy(double diff) {
    // Menggerakkan seluruh Guppy
    Node<Guppy> tempGuppy = listGuppy.getHead();
    Node<Guppy> tempGuppy2;
    while (tempGuppy != null) {
      if (tempGuppy.getData().GetFullRate() <= -12) {
        // Guppy mati
        tempGuppy2 = tempGuppy.getNext();
        listGuppy.remove(tempGuppy.getData());
        tempGuppy = tempGuppy2;
      } else {
        tempGuppy.getData().produceCoin(diff,listCoin);
        tempGuppy.getData().move(diff,listFood);
        tempGuppy = tempGuppy.getNext();
      }
    }
  }

  /**
    Method to move the damn snail.
   */
  public void moveSnail(double diff) {
    // Mengerakkan seluruh Snail
    Node<Snail> tempSnail = listSnail.getHead();
    while (tempSnail != null) {
      tempSnail.getData().move(diff,listCoin,money);
      tempSnail = tempSnail.getNext();
    }
  }

  /**
    Method to move the damn piranha.
   */
  public void movePiranha(double diff) {
    // Menggerakkan seluruh Piranha
    Node<Piranha> tempPiranha = listPiranha.getHead();
    Node<Piranha> tempPiranha2;
    while (tempPiranha != null) {
      if (tempPiranha.getData().GetFullRate() <= -12) {
        // Piranha mati
        tempPiranha2 = tempPiranha.getNext();
        listPiranha.remove(tempPiranha.getData());
        tempPiranha = tempPiranha2;
      } else {
        tempPiranha.getData().move(diff,listGuppy,listCoin);
        tempPiranha = tempPiranha.getNext();
      }
    }
  }

  /**
    Method to move the damn food.
   */
  public void moveFood(double diff) {
    // Menggerakkan seluruh Food
    Node<Food> tempFood = listFood.getHead();
    while (tempFood != null) {
      tempFood.getData().move(diff, listFood);
      tempFood = tempFood.getNext();
    }
  }

  /**
    Method to move the damn coin.
   */
  public void moveCoin(double diff) {
    // Menggerakkan seluruh Coin
    Node<Coin> tempCoin = listCoin.getHead();
    while (tempCoin != null) {
      tempCoin.getData().move(diff);
      tempCoin = tempCoin.getNext();
    }
  }
  
  /**
    Method to add the damn guppy.
   */
  public void addGuppy() {
    // menambahkan seekor Guppy pada list Guppy
    Guppy newGuppy = new Guppy();
    listGuppy.add(newGuppy);
  }
  
  /**
    Method to add the damn piranha.
   */
  public void addPiranha() {
    // menambahkan seekor Piranha pada listFish
    Piranha newPiranha = new Piranha();
    listPiranha.add(newPiranha);
  }
  
  /**
    Method to add coin.
   */
  public void addCoin() {
    // menambahkan sebuah koin pada listCoin
    Coin newCoin = new Coin();
    listCoin.add(newCoin);
  }
  
  /**
    Method to move snail.
   */
  public void addSnail() {
    // Menambahkan seekor siput pada listSnail
    Snail newSnail = new Snail();
    listSnail.add(newSnail);
  }
  
  /**
    Method to add food.
   */
  public void addFood(int x) {
    // menambahkan sebuah makanan pada listFood
    Food newFood = new Food(x);
    listFood.add(newFood);
  }
  
  /**
    Method to find out if there is no Fish in guppy neither piranha.
   */
  public Boolean isThereIsNoFish() {
    return (listGuppy.getHead() == null) && (listPiranha.getHead() == null);
  }

  /**
    Money getter.
   */
  public int getMoney() {
    return money;
  }

  /**
    Method to set money.
   */
  public void setMoney(int money) {
    this.money = money;
  }
}