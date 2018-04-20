public class coin extends entity implements movingObject{
    private int value;
    public coin(){
        value=15;
    }
    public coin(int val,double x,double y){
        super(x,y);
        value=val;
    }
    public Boolean equals(coin other){
        return super.equals(other) && this.value==other.value;
    }
    public void setVal(int val){
        value=val;
    }
    public int getval(){
        return value;
    }
    public void move(double diff){
        if (this.getOrdinat() < 450){
            this.setPos(this.getAbsis(), this.getOrdinat()+diff*40);
        }
    }
    public String toString(){
        return "("+this.getAbsis()+","+this.getOrdinat()+","+value+")";    
    }
}