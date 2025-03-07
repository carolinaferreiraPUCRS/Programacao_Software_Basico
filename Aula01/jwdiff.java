/**
 * Compara arquivos, palavra por palavra.
 * 
 * @author Roland Teodorowitsch
 * @version 12 abr. 2017
 */

import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

public class jwdiff {
    final static double VERSION = 1.0;
    
    public static void usage() {
        System.err.printf("jwdiff - Vs %.1f\n",VERSION);
        System.err.printf("Usage:\n   jwdiff <file1> file2\n\n");
        
    }
    
    public static void main(String[] args) throws FileNotFoundException {
        if (args.length != 2) {
            usage();
            System.exit(1);
        }
        Scanner f1 = new Scanner(new File(args[0]));
        Scanner f2 = new Scanner(new File(args[1]));
        while (f1.hasNext()) {
            String w1 = f1.next();
            if (!f2.hasNext()) {
                System.out.println("< "+w1);
                System.out.println(">");
                System.exit(1);
            }
            String w2 = f2.next();
            if (!w1.equals(w2)) {
                System.out.println("< "+w1);
                System.out.println("> "+w2);
                System.exit(1);
            }
        }
        if (f2.hasNext()) {
                System.out.println("<");
                System.out.println("> "+f2.next());
                System.exit(1);
        }
        f1.close();
        f2.close();
        System.exit(0);
    }
    
}
