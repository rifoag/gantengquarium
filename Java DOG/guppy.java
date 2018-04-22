public class Guppy extends Fish{
    private double time;
    private static final int COIN_TIME=7;
    public Guppy(){
        time=0;
    }
    public Guppy(int x,int y){
        super(x,y);
        time=0;
    }
    public Boolean equals(Guppy other){
        return super.equals(other) && (this.time==other.time); 
    }
    public void move(double diff,LinkedList<Food> listFood){
        if (isStarving() && !listFood.isEmpty()){
            // Jika lapar, Guppy bergerak mendekati makanan (jika ada)
            findFood(diff,listFood); 
        } else {	
           // bergerak bebas
            super.move(diff);
        }
        fullRate-=diff; // tingkat kekenyangan berkurang
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
    public void findFood(double diff , LinkedList<Food> listFood){
        // Saat lapar, Guppy akan mendekati makanan ikan yang ada di akuarium
        Food Near = this.getNearestFood(listFood);
        orientation = Math.atan2(Near.getOrdinat() - this.getOrdinat() , Near.getAbsis() - this.getAbsis()) * 180/3.14159265;
        setPos(this.getAbsis() + SPEED*diff*Math.cos(orientation), this.getOrdinat() + SPEED*diff*Math.sin(orientation));
        eat(Near, listFood);
    }
    public void eat(Food feed,LinkedList<Food> listFood){
        // Guppy memakan makanan ikan yang berada pada radius makannya
        if (!listFood.isEmpty()){
            if (this.getDistance(feed)<=FOOD_RADIUS){
                fullRate=FULL_TIME;
                foodEaten++;
                if (foodEaten==FOOD_NEEDED && growth<3){
                    growth++;
                    foodEaten=0;
                }
                listFood.remove(feed);
            }
        }
    }
    public void produceCoin(double diff,LinkedList<Coin> listCoin){
        // Guppy mengeluarkan koin setiap periode tertentu
        if (time >= COIN_TIME){
            Coin produced = new Coin(growth*5,this.getAbsis(),this.getOrdinat());
            time = 0;
            listCoin.add(produced);
        } else{
            time+= diff;
        }
    }
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

    public static void main(String [] args){
        Guppy g = new Guppy();
        System.out.println(g.toString());
        LinkedList<Food> listFood = new LinkedList<Food>();
        g.move(0.03,listFood);
        System.out.println(g.toString());
    }
}