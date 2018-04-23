import java.io.PushbackReader;

public class Piranha extends Fish{
    private final int price;
    public Piranha(){
        price = 1000;
    }
    public Piranha(int price,int x,int y){
        super(x,y);
        this.price=price;
    }
    public Boolean equals(Piranha other){
        return super.equals(other) && (price==other.price);
    }
    public void findFood(double diff, LinkedList<Guppy> listGuppy, LinkedList<Coin> listCoin){
        // Saat lapar, Piranha akan mendekati Guppy yang ada di aquarium
        Guppy Near = this.getNearestGuppy(listGuppy); 
        orientation = Math.atan2(Near.getOrdinat() - this.getOrdinat(), Near.getAbsis() - this.getAbsis());
        setPos(this.getAbsis() + SPEED*diff*Math.cos(orientation), this.getOrdinat() + SPEED*diff*Math.sin(orientation));
        eat(Near,listGuppy,listCoin);
    }
    public void eat(Guppy prey,LinkedList<Guppy> listGuppy,LinkedList<Coin> listCoin){
        // Piranha memakan Guppy terdekat darinya
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
    public void produceCoin(int guppyGrowth, LinkedList<Coin> listCoin){
        // Piranha mengeluarkan koin setelah memakan Guppy
        Coin produced = new Coin(price*(guppyGrowth+1),this.getAbsis(),this.getOrdinat());
        listCoin.add(produced);
    }
    public Guppy getNearestGuppy(LinkedList<Guppy> prey) {
        // mengembalikan Guppy terdekat dari posisi Piranha
        Node<Guppy> temp = prey.getHead();
        Guppy minGuppy = temp.getData();
        temp = temp.getNext();
        while (temp != null) {
            if (this.getDistance(temp.getData()) < this.getDistance(minGuppy)) {
                minGuppy = temp.getData();
            }
            temp = temp.getNext();
        }
        return minGuppy;
    }
    public void move(double diff, LinkedList<Guppy> listGuppy,LinkedList<Coin> listCoin){
        if (isStarving() && !listGuppy.isEmpty()) {
            // Jika lapar, ia akan bergerak mendekati Guppy terdekat
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

    public static void main (String[] args){
        Piranha p = new Piranha();
        System.out.println(p.toString());
        LinkedList<Coin> listCoin = new LinkedList<Coin>();
        LinkedList<Guppy> listGuppy = new LinkedList<Guppy>();
        p.move(0.01, listGuppy, listCoin);
        System.out.println(p.toString());
    }
}