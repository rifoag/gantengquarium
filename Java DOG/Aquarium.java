public class Aquarium{
    private static final int MAX_LENGTH = 640;
    private static final int MAX_WIDTH = 480;
    private int money;
    private LinkedList<Guppy> listGuppy;
    private LinkedList<Piranha> listPiranha;
    private LinkedList<Coin> listCoin;
    private LinkedList<Snail> listSnail;
    private LinkedList<Food> listFood;
    public Aquarium(){
        listGuppy = new LinkedList<Guppy>();
        listPiranha = new LinkedList<Piranha>();
        listCoin = new LinkedList<Coin>();
        listSnail = new LinkedList<Snail>();
        listFood = new LinkedList<Food>();
        money = 10000;
    }
    public void moveAll(double diff){
        // menggerakkan semua entity yang ada di Aquarium
        moveGuppy(diff);
        moveSnail(diff);
        movePiranha(diff);
        moveFood(diff);
        moveCoin(diff);
    }
    public void moveGuppy(double diff){
        // Menggerakkan seluruh Guppy
        Node<Guppy> tempGuppy = listGuppy.getHead();
        Node<Guppy> tempGuppy_2;
        while (tempGuppy != null){
            if (tempGuppy.getData().GetFullRate() <= -12){
                // Guppy mati
                tempGuppy_2 = tempGuppy.getNext();
                listGuppy.remove(tempGuppy.getData());
                tempGuppy = tempGuppy_2;
            } else {
                tempGuppy.getData().produceCoin(diff,listCoin);
                tempGuppy.getData().move(diff,listFood);
                tempGuppy = tempGuppy.getNext();
            }
        }
    }
        
    public void moveSnail(double diff){
        // Mengerakkan seluruh Snail
        Node<Snail> tempSnail = listSnail.getHead();
        while (tempSnail != null){
            tempSnail.getData().move(diff,listCoin,money);
            tempSnail = tempSnail.getNext();
        }
    }
    public void movePiranha(double diff){
        // Menggerakkan seluruh Piranha
        Node<Piranha> tempPiranha = listPiranha.getHead();
        Node<Piranha> tempPiranha_2;
        while (tempPiranha != null){
            if (tempPiranha.getData().GetFullRate() <= -12){
                // Piranha mati
                tempPiranha_2=tempPiranha.getNext();
                listPiranha.remove(tempPiranha.getData());
                tempPiranha=tempPiranha_2;
            } else {
                tempPiranha.getData().move(diff,listGuppy,listCoin);
                tempPiranha=tempPiranha.getNext();
            }
        }
    }
        
    public void moveFood(double diff){
        // Menggerakkan seluruh Food
        Node<Food> tempFood = listFood.getHead();
        while (tempFood != null){
            tempFood.getData().move(diff, listFood);
            tempFood = tempFood.getNext();
        }
    }
        
    public void moveCoin(double diff){
        // Menggerakkan seluruh Coin
        Node<Coin> tempCoin = listCoin.getHead();
        while(tempCoin != null){
            tempCoin.getData().move(diff);
            tempCoin = tempCoin.getNext();
        }
    }
        
    public void addGuppy(){
        // menambahkan seekor Guppy pada list Guppy
        Guppy new_guppy = new Guppy();
        listGuppy.add(new_guppy);
    }
        
    public void addPiranha(){
        // menambahkan seekor Piranha pada listFish
        Piranha new_piranha = new Piranha();
        listPiranha.add(new_piranha);
    }
        
    public void addCoin(){
        // menambahkan sebuah koin pada listCoin
        Coin new_coin = new Coin();
        listCoin.add(new_coin);
    }
        
    public void addSnail(){
        // Menambahkan seekor siput pada listSnail
        Snail new_snail = new Snail();
        listSnail.add(new_snail);
    }
        
    public void addFood(int x){
        // menambahkan sebuah makanan pada listFood
        Food new_food = new Food(x);
        listFood.add(new_food);
    }
        
    public Boolean isThereIsNoFish() {
        return (listGuppy.getHead() == null) && (listPiranha.getHead() == null);
    }
    public int getMoney(){
        return money;
    }
    public void setMoney(int money){
        this.money = money;
    }
}