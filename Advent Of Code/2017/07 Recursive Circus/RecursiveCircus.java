import java.util.Scanner;
import java.io.File;

class RecursiveCircus
{
    private final static int DATA_SIZE = 1200;
    class RootedTree {
        String name;
        RootedTree next;
        RootedTree child;
        int weight;
    }

    private static RootedTree[] data;

    public static void main(String args[]) throws Exception
	{
		String fileName = "RecursiveCircus.in"; 
		Scanner sc = new Scanner(new File(fileName));
        //Scanner sc = new Scanner(System.in);

        data = new RootedTree[DATA_SIZE];
        while (sc.hasNextLine()) {
            Scanner parser = new Scanner(sc.nextLine());
            data[i].name = parser.next();
            data[i].weight = parser.nextInt();

            boolean firstChild = true;
            RootedTree pointer;
            while (parser.hasNext()) {
                if (firstChild) {
                    data[i].child = 
                }
            }
        }
        
        sc.close();
    }
}