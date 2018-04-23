import javafx.util.Pair;
import java.util.Random;
public abstract class Entity{
    protected Pair<Double,Double> pos;
    public Entity(){
        Random rand=new Random();
        double x = rand.nextDouble() * 640;
        double y = rand.nextDouble() * 480;
        pos = new Pair<Double,Double>(x,y);
    }
    public Entity(double x,double y){
        Random rand=new Random();
        if (x == -1){
            x = rand.nextDouble() * 640;
        }
        if (y == -1){
            y = rand.nextDouble() * 480;
        }
        pos = new Pair<Double,Double>(x,y);
    }
    public double getAbsis(){
        return pos.getKey();
    }
    public double getOrdinat(){
        return pos.getValue();
    }
    public void setPos(double x,double y){
        pos = new Pair<Double,Double>(x,y);
    }
    public Boolean equals(Entity other){
        return this.getAbsis()==other.getAbsis() && this.getOrdinat()==other.getOrdinat();
    }
    public double getDistance(Entity other){
        return Math.sqrt(Math.pow(this.getAbsis()-other.getAbsis(),2)+Math.pow(this.getOrdinat()-other.getOrdinat(),2));
    }
    public String toString(){
        return "("+this.getAbsis()+","+this.getOrdinat()+")";
    }
    
    // Driver
    // sebelumnya kelas tidak abstrak
    public static void main (String[] args){
        // Entity e = new Entity();
        // Entity e2 = new Entity();
        // System.out.println(e.toString());
        // e.setPos(10, 10);
        // e2.setPos(10, 10);
        // System.out.println(e.equals(e2));
    }
}