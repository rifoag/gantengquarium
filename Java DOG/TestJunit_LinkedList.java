import org.junit.Test;

import static org.junit.Assert.*;

public class TestJunit_LinkedList {

    @Test
    public void getHead() {
        LinkedList<Double> l1 = new LinkedList<Double>();
        l1.add(2.5);
        assertEquals(2.5,l1.get(0), 0.1);
    }

    @Test
    public void add() {
        LinkedList<Double> l1 = new LinkedList<Double>();
        l1.add(2.5);
        assertFalse(l1.isEmpty());
    }

    @Test
    public void get() {
        LinkedList<Double> l1 = new LinkedList<Double>();
        l1.add(3.7);
        l1.add(4.8);
        l1.add(9.6);
        assertEquals(3.7,l1.get(0), 0.1);
        assertEquals(4.8,l1.get(1), 0.1);
        assertEquals(9.6,l1.get(2), 0.1);
    }
}