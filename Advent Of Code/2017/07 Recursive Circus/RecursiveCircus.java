import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Scanner;
import java.io.File;

class RecursiveCircus
{
    private final static int DATA_SIZE = 2000;
    private final static boolean isDebug = true;

    private static class RootedTree {
        String name;
        RootedTree next;
        RootedTree child;
        int weight;
        int totalWeight;
        int hierarchy;
    }
    private static RootedTree[] data;
    private static HashMap<String, RootedTree> dataMap = new HashMap<String, RootedTree>(); 

    public static void hiearchialProcess(RootedTree root, int level) {
        if (root.hierarchy < level) root.hierarchy = level;

        RootedTree p = root.child;
        while (p != null) {
            hiearchialProcess(p, level + 1);
            p = p.next;
        }
    }

    public static void processTreeWeights(RootedTree root) {
        int total = root.weight;
        RootedTree p = root.child;
        while (p != null) {
            processTreeWeights(p);
            total += p.totalWeight;
            p = p.next;
        }
        root.totalWeight = total;
    }

    public static void printDebugInfo(int dataCounter) {
        // debug
        if (isDebug) {
            System.out.printf("Reading finished, data[%d] contains : \n", dataCounter);
            for (int i = 0; i < dataCounter; i++) System.out.printf("[%s] [%d] <%d> <%d>\n", data[i].name, data[i].weight, data[i].hierarchy, data[i].totalWeight);
            
            System.out.printf("dataMap contains : \n", dataCounter);
            for (String name: dataMap.keySet()) {
                String key = name.toString();
                String val = dataMap.get(name).toString();
                System.out.printf("[%s] - [%s]\n", key, val);
            }
        }
    }

    public static void main(String args[]) throws Exception
	{
		String fileName = "RecursiveCircus.txt"; 
		Scanner sc = new Scanner(new File(fileName));
        //Scanner sc = new Scanner(System.in);

        int dataCounter = 0;
        data = new RootedTree[DATA_SIZE];
        while (sc.hasNextLine()) {
            Scanner parser = new Scanner(sc.nextLine());

            // check if this KEY is already in HashMap
            String name = parser.next();                        
            int weight = parser.nextInt();                              if (isDebug) System.out.printf("Reading : [%s] [%d]", name, weight);
            RootedTree pointer = dataMap.get(name);               
            if (pointer == null) {
                data[dataCounter] = new RootedTree();
                data[dataCounter].name = name;
                data[dataCounter].weight = weight;
                pointer = data[dataCounter];
                dataCounter++;                
                dataMap.put(name, pointer);                             if (isDebug) System.out.printf(" ++ ");
            } else  {                                                   if (isDebug) System.out.printf("    ");                               
                pointer.weight = weight;
            }

            // check if the data contains relationship info
            boolean firstChild = true;
            RootedTree root = pointer;                                  if (isDebug && parser.hasNext()) System.out.printf("--> ");
            while (parser.hasNext()) {
                String childrenName = parser.next();
                RootedTree childPointer = dataMap.get(childrenName);    if (isDebug) System.out.printf("[%s]", childrenName);  

                if (childPointer == null) {
                    data[dataCounter] = new RootedTree();
                    data[dataCounter].name = childrenName;
                    childPointer = data[dataCounter];
                    dataCounter++;
                    dataMap.put(childrenName, childPointer);            if (isDebug) System.out.printf("+ ");                       
                } else                                                  if (isDebug) System.out.printf("  ");

                if (firstChild) {
                    root.child = childPointer;
                    firstChild = false;
                } else {
                    RootedTree p = root.child;
                    while (p.next != null) p = p.next;
                    p.next = childPointer;
                }
            }
            parser.close();                                             if (isDebug) System.out.printf("\n");
        }
        sc.close();

        // process all the element in the tree, giving each a hierarchial degree
        for (int i = 0; i < dataCounter; i++) {
            hiearchialProcess(data[i], 0);
        }

        // day 01 answer : 
        RootedTree root = null;
        for (int i = 0; i < dataCounter; i++) if (data[i].hierarchy == 0) root = data[i];
        System.out.println("root : [" + root.name + "]");

        printDebugInfo(dataCounter);

        // day 02
        processTreeWeights(root);
        int counter = 0;
        ArrayList<RootedTree> bfs = new ArrayList<>();
        bfs.add(root);
        bfs.add(null);
        while (counter != bfs.size()) {
            RootedTree pointer = bfs.get(counter);
            if (pointer != null) {
                pointer = pointer.child;
                boolean hadChild = false;
                while (pointer != null) {
                    hadChild = true;
                    bfs.add(pointer);
                    pointer = pointer.next;
                }
                if (hadChild) bfs.add(null);
            }
            counter++;
        }

        if (isDebug) {
            System.out.printf("bfs contains : \n");
            for (int i = 0; i < bfs.size(); i++) {
                RootedTree p = bfs.get(i);
                if (p != null)
                    System.out.printf("[%s|%d] ", p.name, p.totalWeight);
                else 
                    System.out.println();
            }
            System.out.println();
        }

        // now that we got the bfs sequence of the data, analyze it and find the anomaly!
        int start = 0;
        boolean anomalyDetected = false;
        while (start < bfs.size()) {
            int stop = start + 1;
            //if (anomalyDetected) break;
            if (anomalyDetected) anomalyDetected = false;
            while(bfs.get(stop) != null) stop++;

            int total = 0;
            for (int i = start; i < stop; i++) total += bfs.get(i).totalWeight;
            for (int i = start; i < stop; i++) if (total % bfs.get(i).totalWeight != 0) anomalyDetected = true;
            if (anomalyDetected) {
                System.out.printf("anomaly detected : \n");
                for (int i = start; i < stop; i++) {
                    RootedTree p = bfs.get(i);
                    System.out.printf("[%s|%d|%d] ", p.name, p.weight, p.totalWeight);
                } System.out.println();
            }
            start = stop + 1;
        }
        
    }
}