import java.awt.*;
import java.awt.Event.*;

class Swap{
    public static void main(String[] args){
    	Frame f = new Frame("My Frame");
    	Label l1 = new Label("First");
    	Label l2 = new Label("Second");

    	f.add(l1);
    	f.add(l2);

    	f.setLayout(new FlowLayout());
    	f.setSize(300, 300);
    	f.setVisible(true);
    }
}