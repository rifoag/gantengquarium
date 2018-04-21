public class snail extends entity{
    private static final int COIN_RADIUS = 15; //Radius coin yang dapat diambil siput
    private static final int SPEED = 50;
    public snail(){
        // ctor
        // snail selalu ada di bagian bawah akuarium
        super(-1,440);
    }
    public snail(int x,int y){
        super(x,y);
    }    
    public void move(double diff,LinkedList<coin> listCoin,int money){
        // Siput hanya berada di dasar akuarium
        // Siput hanya bergerak ke kiri dan ke kanan
        // Siput hanya bergerak saat terdapat koin di akuarium
        // Siput berdekat ke koin terdekat
        if (!listCoin.isEmpty()){
            coin Near = this.getNearestCoin(listCoin);
            if (Near.getAbsis() > this.getAbsis()) {
                setPos(this.getAbsis()+SPEED*diff*1, this.getOrdinat());
                // draw_image("snailRight.png", pos.first, pos.second);
            } else if (Near.getAbsis() < this.getAbsis()) {
                setPos(this.getAbsis()+SPEED*diff*(-1), this.getOrdinat());
                // draw_image("snailLeft.png", pos.first, pos.second);
            } else {
                // draw_image("snailRight.png", pos.first, pos.second);
            }
            takeCoin(Near, listCoin, money);
        } else {
            // draw_image("snailRight.png", pos.first, pos.second);
        }
    }
        
    public coin getNearestCoin(LinkedList<coin> listCoin) {
        // mengembalikan coin terdekat dari posisi snail
        Node<coin> temp = listCoin.getHead();
        coin minCoin = temp.getData();
        temp = temp.getNext();
        while (temp != null) {
            if (this.getDistance(temp.getData()) < this.getDistance(minCoin)) {
                minCoin = temp.getData();
            }
            temp = temp.getNext();
        }
        return minCoin;
    }
        
    public void takeCoin(coin cc,LinkedList<coin> listCoin, int money){
        // mengambil coin cc bila coin berada pada radius (COIN_RADIUS)
        if (this.getDistance(cc)<=COIN_RADIUS){
            money += cc.getVal();
            listCoin.remove(cc);
        }
    }    
}