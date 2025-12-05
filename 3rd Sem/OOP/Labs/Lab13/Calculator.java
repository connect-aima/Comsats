import java.awt.*;
import javax.swing.*;

public class Calculator extends JFrame {  // fixed: extend JFrame because this is the window
    public Calculator() {

        // Create panel p1 for the buttons and set GridLayout
        JPanel p1 = new JPanel();
        p1.setLayout(new GridLayout(4, 4));  // fixed
        p1.add(new JButton("7"));
        p1.add(new JButton("8"));
        p1.add(new JButton("9"));
        p1.add(new JButton("/"));
        p1.add(new JButton("4"));
        p1.add(new JButton("5"));
        p1.add(new JButton("6"));
        p1.add(new JButton("*"));
        p1.add(new JButton("1"));
        p1.add(new JButton("2"));
        p1.add(new JButton("3"));
        p1.add(new JButton("-"));
        p1.add(new JButton("0"));
        p1.add(new JButton("." ));
        p1.add(new JButton("=" ));
        p1.add(new JButton("+"));

        // Create panel p2 to hold a text field and p1
        JPanel p2 = new JPanel(new BorderLayout());

        JTextField text = new JTextField();  // fixed: empty text field
        p2.add(text, BorderLayout.NORTH);    // fixed

        p2.add(p1, BorderLayout.CENTER);     // fixed: correct way to add panel

        // add main panel into the frame
        add(p2);  // fixed: add p2 into the JFrame (NOT p2.add(p2))

    }

    public static void main(String[] args) {
        Calculator frame = new Calculator();   // fixed: create Calculator, not TestPanels

        frame.setTitle("Calculator");
        frame.setSize(300, 300);               // fixed: better size
        frame.setLocationRelativeTo(null);     // center
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}
