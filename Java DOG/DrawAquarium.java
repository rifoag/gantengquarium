import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.FontMetrics;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.Toolkit;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import javax.swing.ImageIcon;
import javax.swing.JPanel;
import javax.swing.Timer;

public class DrawAquarium extends JPanel implements ActionListener{
  private final int W_Width = 640;
  private final int W_Height = 480;
  private final int DELAY = 30;

  private Timer timer;
  private Image background;
  private Image fish;
  private Image piranha;
  private Image food;
  private Image snail;
  private Image coin;

  private int posXfish;
  private int posYfish;

  private int posXbg;
  private int posYbg;

  private boolean inGame = true;
  private boolean isLeft;

  // private Guppy adam;

  public DrawAquarium() {
    initAquarium();
  }

  public void initAquarium(){
    addKeyListener(new TAdapter());
    setBackground(Color.black);
    setFocusable(true);
    setDoubleBuffered(true);

    setPreferredSize(new Dimension(W_Width, W_Height));
    loadImages();
    initGame();
  }

  private void loadImages() {
    ImageIcon iid = new ImageIcon("coin.png");
    coin = iid.getImage();

    ImageIcon imgBackground = new ImageIcon("background.png");
    background = imgBackground.getImage();
    // ImageIcon iia = new ImageIcon("src/resources/apple.png");
    // piranha = iia.getImage();
    //
    // ImageIcon iih = new ImageIcon("src/resources/head.png");
    // head = iih.getImage();
  }

  private void initGame(){
    // adam = new Guppy();
    posXfish = 20;
    posYfish = 20;
    posYbg = 0;
    posXbg = 0;
    isLeft = true;
    timer = new Timer(DELAY, this);
    timer.start();
  }

  @Override
  public void paintComponent(Graphics g) {
    super.paintComponent(g);
    doDrawing(g);
  }

  private void doDrawing(Graphics g) {
    if (inGame) {
      g.drawImage(background, posXbg, posYbg, this);
      g.drawImage(coin, posXfish, posYfish, this);
      Toolkit.getDefaultToolkit().sync();
    } else {
      gameOver(g);
    }
  }

  private void gameOver(Graphics g) {
    String msg = "Game Over";
        Font small = new Font("Purisa", Font.BOLD, 14);
        FontMetrics metr = getFontMetrics(small);

        g.setColor(Color.white);
        g.setFont(small);
        g.drawString(msg, (W_Width - metr.stringWidth(msg)) / 2, W_Height / 2);
  }

  private void move() {
    if (posXfish > 620) {
      isLeft = false;
    } else if (posXfish < 20){
      isLeft = true;
    }
    if (isLeft) {
      posXfish += 3;
    } else {
      posXfish -= 3;
    }
  }

  @Override
  public void actionPerformed(ActionEvent e) {
        if (inGame) {
            // checkApple();
            // checkCollision();
            move();
        }

        repaint();
  }
  private class TAdapter extends KeyAdapter {

        @Override
        public void keyPressed(KeyEvent e) {

            // int key = e.getKeyCode();
            //
            // if ((key == KeyEvent.VK_LEFT) && (!rightDirection)) {
            //     leftDirection = true;
            //     upDirection = false;
            //     downDirection = false;
            // }
            //
            // if ((key == KeyEvent.VK_RIGHT) && (!leftDirection)) {
            //     rightDirection = true;
            //     upDirection = false;
            //     downDirection = false;
            // }
            //
            // if ((key == KeyEvent.VK_UP) && (!downDirection)) {
            //     upDirection = true;
            //     rightDirection = false;
            //     leftDirection = false;
            // }
            //
            // if ((key == KeyEvent.VK_DOWN) && (!upDirection)) {
            //     downDirection = true;
            //     rightDirection = false;
            //     leftDirection = false;
            // }
        }
    }
}
