
import java.awt.*;
import java.awt.event.*;
import java.applet.*;
import java.lang.Math;
/*
	<applet code="MathApp" width="600" height="600"> </applet>
 */
public class MathApp extends Applet implements ActionListener {
	TextField t_sq, t_sqrt, t_cu, t_curt;
	Button b_sq, b_sqrt, b_cu, b_curt;
	Label l_sq, l_sqrt, l_cu, l_curt;
	
	public void init() {
		setLayout(null);
		
		t_sq = new TextField();
		t_sqrt = new TextField();
		t_cu = new TextField();
		t_curt = new TextField();
		
		t_sq.setBounds(50, 50, 70, 20);
		add(t_sq);
		t_sqrt.setBounds(50, 100, 70, 20);
		add(t_sqrt);
		t_cu.setBounds(50, 150, 70, 20);
		add(t_cu);
		t_curt.setBounds(50, 200, 70, 20);
		add(t_curt);
		
		b_sq = new Button("Square");
		b_sqrt = new Button("Sq. root");
		b_cu = new Button("Cube");
		b_curt = new Button("Cu. root");
		
		b_sq.setBounds(100, 50, 80, 20);
		add(b_sq);
		b_sq.addActionListener(this);
		b_sqrt.setBounds(100, 100, 80, 20);
		add(b_sqrt);
		b_sqrt.addActionListener(this);
		b_cu.setBounds(100, 150, 80, 20);
		add(b_cu);
		b_cu.addActionListener(this);
		b_curt.setBounds(100, 200, 80, 20);
		add(b_curt);
		b_curt.addActionListener(this);
		
		l_sq = new Label();
		l_sqrt = new Label();
		l_cu = new Label();
		l_curt = new Label();
		
		l_sq.setBounds(250, 50, 150, 20);
		add(l_sq);
		l_sqrt.setBounds(250, 100, 150, 20);
		add(l_sqrt);
		l_cu.setBounds(250, 150, 150, 20);
		add(l_cu);
		l_curt.setBounds(250, 200, 150, 20);
		add(l_curt);

	}

	public void actionPerformed(ActionEvent ae) {
		int ch = 0;
		if (ae.getSource() == b_sq)
			ch = 1;
		else if (ae.getSource() == b_sqrt)
			ch = 2;
		else if (ae.getSource() == b_cu)
			ch = 3;
		else if (ae.getSource() == b_curt)
			ch = 4;
		else
			l_curt.setText("Wrong Button");
		
		try {
			switch (ch) {
				case 1:
					int n_sq = Integer.parseInt(t_sq.getText());
					l_sq.setText("Square : " + (n_sq*n_sq));
				break;
				
				case 2:
					int n_sqrt = Integer.parseInt(t_sqrt.getText());
					l_sqrt.setText("Sq. root: " + (Math.sqrt(n_sqrt)));
				break;
				
				case 3:
					int n_cu = Integer.parseInt(t_cu.getText());
					l_cu.setText("Cube : " + (n_cu * n_cu * n_cu));
				break;
				
				case 4:
					int n_curt = Integer.parseInt(t_curt.getText());
					l_curt.setText("cu. root : " + (Math.cbrt(n_curt)));
				break;
			}
		}
		catch (NumberFormatException ne) {
			l_sq.setText("Please enter a number");
		}
	}
}
