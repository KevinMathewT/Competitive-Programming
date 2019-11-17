import java.io.*;
import java.util.*;

class StartWithJava{
	public static void main(String args[]) throws IOException{
		BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("output.txt")));
        Scanner in = new Scanner(new FileReader("input.txt"));

        String s = in.nextLine();
        System.out.println(s);
        pw.print("Hello!");

        pw.flush();
	}
}