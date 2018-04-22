public class Food extends Entity implements movingObject{
    private static final int FOOD_SPEED = 34;
    public Food(){}
    public Food(int x){
        super(x,100);
    }
    public int getSpeed(){
        return FOOD_SPEED;
    }
    public void move(double diff){}
    public void move(double diff,LinkedList<Food> listFood){
        if (this.getOrdinat() < 480){
            this.setPos(this.getAbsis(), this.getOrdinat()+FOOD_SPEED*diff);
        }
        if (this.getOrdinat() < 450) {
            /* draw_image("pillfood.png", pos.first, pos.second); */
        } else {
            listFood.remove(this);
        }
    }
    
    // driver
    public static void main (String[] args){
        Food f = new Food(300);
        LinkedList<Food> listFood = new LinkedList<Food>();
        System.out.println(f.toString());
        f.move(0.03, listFood);
        System.out.println(f.toString());
    }
}