import javax.swing.*;
import java.awt.*;

public class BannerApplication extends JFrame implements Runnable {
    private String text = " Java World ";
    private int x = 0;
    private int y = 100;
    private int textWidth;
    private boolean movingRight = true;
    private Thread thread;

    public BannerApplication() {
        setTitle("Banner Application :)");
        setSize(600, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        thread = new Thread(this);
        thread.start();
    }

    @Override
    public void paint(Graphics g) {
        super.paint(g);
        g.setFont(new Font("Arial", Font.BOLD, 20));
        textWidth = g.getFontMetrics().stringWidth(text);
        g.setColor(Color.BLACK);
        g.drawString(text, x, y);
    }

    @Override
    public void run() {
        while (true) {
            if (movingRight) {
                x += 20;
                if (x + textWidth >= getWidth()) {
                    movingRight = false;
                }
            } else {
                x -= 20;
                if (x <= 0) {
                    movingRight = true;
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
            BannerApplication app = new BannerApplication();
            app.setVisible(true);
        });
    }
}
