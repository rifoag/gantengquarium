public class food extends entity implements movingObject{
    private static final int FOOD_SPEED = 34;
    public food(){}
    public food(int x){
        super(x,100);
    }
    public int getSpeed(){
        return FOOD_SPEED;
    }
    public void move(double diff){}
    public void move(double diff,LinkedList<food> listFood){
        if (this.getOrdinat() < 480){
            this.setPos(this.getAbsis(), this.getOrdinat()+FOOD_SPEED*diff);
        }
        if (this.getOrdinat() < 450) {
            /* draw_image("pillfood.png", pos.first, pos.second); */
        } else {
            listFood.remove(this);
        }
    }
}