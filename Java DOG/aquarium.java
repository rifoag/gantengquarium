public class aquarium{
    private static final int MAX_LENGTH = 640;
    private static final int MAX_WIDTH = 480;
    private int money;
    private LinkedList<guppy> listGuppy;
    private LinkedList<piranha> listPiranha;
    private LinkedList<coin> listCoin;
    private LinkedList<snail> listSnail;
    private LinkedList<food> listFood;
    public aquarium(){
        listGuppy = new LinkedList<guppy>();
        listPiranha = new LinkedList<piranha>();
        listCoin = new LinkedList<coin>();
        listSnail = new LinkedList<snail>();
        listFood = new LinkedList<food>();
        money = 10000;
    }
    public void moveAll(double diff){
        // menggerakkan semua entity yang ada di aquarium
        moveGuppy(diff);
        moveSnail(diff);
        movePiranha(diff);
        moveFood(diff);
        moveCoin(diff);
    }
    public void moveGuppy(double diff){
        // Menggerakkan seluruh guppy
        Node<guppy> tempGuppy = listGuppy.getHead();
        Node<guppy> tempGuppy_2;
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
        // Mengerakkan seluruh snail
        Node<snail> tempSnail = listSnail.getHead();
        while (tempSnail != null){
            tempSnail.getData().move(diff,listCoin,money);
            tempSnail = tempSnail.getNext();
        }
    }
    public void movePiranha(double diff){
        // Menggerakkan seluruh piranha
        Node<piranha> tempPiranha = listPiranha.getHead();
        Node<piranha> tempPiranha_2;
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
        // Menggerakkan seluruh food
        Node<food> tempFood = listFood.getHead();
        while (tempFood != null){
            tempFood.getData().move(diff, listFood);
            tempFood = tempFood.getNext();
        }
    }
        
    public void moveCoin(double diff){
        // Menggerakkan seluruh coin
        Node<coin> tempCoin = listCoin.getHead();
        while(tempCoin != null){
            tempCoin.getData().move(diff);
            tempCoin = tempCoin.getNext();
        }
    }
        
    public void addGuppy(){
        // menambahkan seekor guppy pada list Guppy
        guppy new_guppy = new guppy();
        listGuppy.add(new_guppy);
    }
        
    public void addPiranha(){
        // menambahkan seekor piranha pada listFish
        piranha new_piranha = new piranha();
        listPiranha.add(new_piranha);
    }
        
    public void addCoin(){
        // menambahkan sebuah koin pada listCoin
        coin new_coin = new coin();
        listCoin.add(new_coin);
    }
        
    public void addSnail(){
        // Menambahkan seekor siput pada listSnail
        snail new_snail = new snail();
        listSnail.add(new_snail);
    }
        
    public void addFood(int x){
        // menambahkan sebuah makanan pada listFood
        food new_food = new food(x);
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