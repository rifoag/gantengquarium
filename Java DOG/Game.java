import java.awt.EventQueue;
import javax.swing.JFrame;

public class Game extends JFrame {

    public Game() {

        initUI();
    }

    private void initUI() {

        add(new DrawAquarium());

        setResizable(false);
        pack();

        setTitle("Taiquarium");
        setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    public static void main(String[] args) {

        EventQueue.invokeLater(() -> {
            JFrame ex = new Game();
            ex.setVisible(true);
        });
    }
}
