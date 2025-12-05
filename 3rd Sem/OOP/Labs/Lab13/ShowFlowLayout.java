import javax.swing.JLabel;//to add text
import javax.swing.JTextField;// to add feilds
import javax.swing.JFrame;//work as containor that holds content
import java.awt.FlowLayout;//layout manager It tells Java how to arrange components inside the window.

public class ShowFlowLayout extends JFrame {
        public ShowFlowLayout() { 
        //Set FlowLayout, aligned left with horizontal gap 10 
        //and vertical gap 20 between components 
        setLayout(new FlowLayout(FlowLayout.LEFT,  10, 20)); 
        add(new JLabel("First Name")); 
        add(new JTextField(8)); 
        add(new JLabel("MI")); 
        add(new JTextField(8)); 
        add(new JLabel("Last Name")); 
        add(new JTextField(8)); 
        }
 
    public static void main(String[] args) { 
        ShowFlowLayout frame = new ShowFlowLayout(); 
        frame.setTitle("Show FlowLayout"); 
        frame.setSize(200, 200); 
        frame.setLocationRelativeTo(null); 
        
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);frame.setVisible(true);
        }
}