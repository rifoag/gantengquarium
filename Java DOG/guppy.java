public class guppy extends fish{
    private double time;
    private static final int COIN_TIME=7;
    public guppy(){
        time=0;
    }
    public guppy(int x,int y){
        super(x,y);
        time=0;
    }
    public Boolean equals(guppy other){
        return super.equals(other) && (this.time==other.time); 
    }
    public void move(double diff,LinkedList<food> listFood){
        if (isStarving() && !listFood.isEmpty()){
            // Jika lapar, guppy bergerak mendekati makanan (jika ada)
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
    public void findFood(double diff , LinkedList<food> listFood){
        // Saat lapar, Guppy akan mendekati makanan ikan yang ada di akuarium
        food Near = this.getNearestFood(listFood);
        orientation = Math.atan2(Near.getOrdinat() - this.getOrdinat() , Near.getAbsis() - this.getAbsis()) * 180/3.14159265;
        setPos(this.getAbsis() + SPEED*diff*Math.cos(orientation), this.getOrdinat() + SPEED*diff*Math.sin(orientation));
        eat(Near, listFood);
    }
    public void eat(food feed,LinkedList<food> listFood){
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
    public void produceCoin(double diff,LinkedList<coin> listCoin){
        // Guppy mengeluarkan koin setiap periode tertentu
        if (time >= COIN_TIME){
            coin produced = new coin(growth*5,this.getAbsis(),this.getOrdinat());
            time = 0;
            listCoin.add(produced);
        } else{
            time+= diff;
        }
    }
    public food getNearestFood(LinkedList<food> feed) {
        // Mengembalikan food terdekat ke guppy pada listFood
        Node<food> temp = feed.getHead();
        food minFood = temp.getData();
        temp = temp.getNext();
        while (temp != null) {
            if (this.getDistance(temp.getData()) < this.getDistance(minFood)) {
                minFood = temp.getData();
            }
            temp = temp.getNext();
        }
        return minFood;
    }
}