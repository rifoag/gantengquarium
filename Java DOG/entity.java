import javafx.util.Pair;
import java.util.Random;
public class entity{
    protected Pair<Double,Double> pos;
    public entity(){
        Random rand=new Random();
        double x = rand.nextDouble() * 640;
        double y = rand.nextDouble() * 480;
        pos = new Pair<Double,Double>(x,y);
    }
    public entity(double x,double y){
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
    public Boolean equals(entity other){
        return this.getAbsis()==other.getAbsis() && this.getOrdinat()==other.getOrdinat();
    }
    public double getDistance(entity other){
        return Math.sqrt(Math.pow(this.getAbsis()-other.getAbsis(),2)+Math.pow(this.getOrdinat()-other.getOrdinat(),2));
    }
    public String toString(){
        return "("+this.getAbsis()+","+this.getOrdinat()+")";
    }
}