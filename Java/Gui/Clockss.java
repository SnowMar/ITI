import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.time.Clock;
import java.util.Date;
import javax.swing.JFrame;

public class Clockss extends JFrame implements Runnable {
    Thread th; 
    Date d = new Date();

    public Clockss() {
        this.setTitle(d.toString());
        th = new Thread(this);
        th.start();

        this.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });
    }

    public static void main(String[] args) {
        Clockss app = new Clockss();
        app.setBounds(50, 50, 600, 400);
        app.setVisible(true);
    }

    public void run() {
        while (true) {
            d = new Date();
            this.setTitle(d.toString()); // Update the frame title with the current time
            try {
                Thread.sleep(1000); // Pause for 1 second
            } catch (InterruptedException e) {
                e.printStackTrace(); // Handle interruption
            }
        }
    }
}
