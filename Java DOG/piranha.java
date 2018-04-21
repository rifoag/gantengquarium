import java.io.PushbackReader;

public class piranha extends fish{
    private int price;
    public piranha(){
        price = 1000;
    }
    public piranha(int price,int x,int y){
        super(x,y);
        this.price=price;
    }
    public Boolean equals(piranha other){
        return super.equals(other) && (price==other.price);
    }
    public void findFood(double diff, LinkedList<guppy> listGuppy, LinkedList<coin> listCoin){
        // Saat lapar, piranha akan mendekati guppy yang ada di aquarium
        guppy Near = this.getNearestGuppy(listGuppy); 
        orientation = Math.atan2(Near.getOrdinat() - this.getOrdinat(), Near.getAbsis() - this.getAbsis());
        setPos(this.getAbsis() + SPEED*diff*Math.cos(orientation), this.getOrdinat() + SPEED*diff*Math.sin(orientation));
        eat(Near,listGuppy,listCoin);
    }
    public void eat(guppy prey,LinkedList<guppy> listGuppy,LinkedList<coin> listCoin){
        // piranha memakan guppy terdekat darinya
        if (!listGuppy.isEmpty() && this.getDistance(prey) <= FOOD_RADIUS){
            fullRate = FULL_TIME;
            foodEaten++;
            if (foodEaten == FOOD_NEEDED && growth < 3){
                growth++;
                foodEaten = 0;
            }
            produceCoin(prey.getGrowth(),listCoin);
            listGuppy.remove(prey);
        }
    }
    public void produceCoin(int guppyGrowth, LinkedList<coin> listCoin){
        // piranha mengeluarkan koin setelah memakan guppy
        coin produced = new coin(price*(guppyGrowth+1),this.getAbsis(),this.getOrdinat());
        listCoin.add(produced);
    }
    public guppy getNearestGuppy(LinkedList<guppy> prey) {
        // mengembalikan guppy terdekat dari posisi piranha
        Node<guppy> temp = prey.getHead();
        guppy minGuppy = temp.getData();
        temp = temp.getNext();
        while (temp != null) {
            if (this.getDistance(temp.getData()) < this.getDistance(minGuppy)) {
                minGuppy = temp.getData();
            }
            temp = temp.getNext();
        }
        return minGuppy;
    }
    public void move(double diff, LinkedList<guppy> listGuppy,LinkedList<coin> listCoin){
        if (isStarving() && !listGuppy.isEmpty()) {
            // Jika lapar, ia akan bergerak mendekati guppy terdekat
            findFood(diff,listGuppy,listCoin);
        } else {
            // berenang bebas
            super.move(diff);
        }
        fullRate-=diff; // tingkat kekenyangan berkurang setiap waktu
        if (Math.cos(orientation) > 0) {
          // draw_image("piranhaRight.png", pos.first, pos.second);
        } else {
          // draw_image("piranhaLeft.png", pos.first, pos.second);
        }
    }
}