import javax.swing.*;
import java.awt.*;
import java.net.URL;

public class Ball extends JFrame implements Runnable {
    private Image image;
    private int x = 300;
    private int y = 100;
    private boolean movingRight = true;
    private boolean movingDown = true;
    private Thread thread;

    public Ball() {
        setTitle("Ball Game :)");
        setSize(900, 700);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        URL imageUrl = getClass().getResource("circular_ball.png");
        if (imageUrl != null) {
            image = new ImageIcon(imageUrl).getImage();
        } else {
            System.out.println("Image not found!");
        }

        thread = new Thread(this);
        thread.start();
    }

    @Override
    public void paint(Graphics g) {
        super.paint(g);
        if (image != null) {
            g.drawImage(image, x, y, this);
        }
    }

    @Override
    public void run() {
        while (true) {
            if (movingRight) {
                x += 10;
                if (x + image.getWidth(this) >= getWidth()) {
                    movingRight = false;
                }
            } else {
                x -= 10;
                if (x <= 0) {
                    movingRight = true;
                }
            }
    
            if (movingDown) {
                y += 10;
                if (y + image.getHeight(this) >= getHeight()) {
                    movingDown = false;
                }
            } else {
                y -= 10;
                if (y <= 0) {
                    movingDown = true;
                }
            }
    
            repaint();
            
            try {
                Thread.sleep(10);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
    

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            Ball app = new Ball();
            app.setVisible(true);
        });
    }
}
