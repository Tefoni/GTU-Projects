import java.util.Arrays;

import src.*;

public class Driver {
    
    public static void main(String[] args) {

        System.out.println("-----Question 1-----");
        MyGraph aGraph = new MyGraph(true);

        Vertex target = aGraph.newVertex("zero", 10);
        aGraph.addVertex(target);
        target.addProperties("drink", "coffee");
        target.addProperties("food", "burger");

        target = aGraph.newVertex("one", 20);
        aGraph.addVertex(target);
        target.addProperties("drink", "milk");
        target.addProperties("food", "sausage");

        target = aGraph.newVertex("two", 50);
        aGraph.addVertex(target);
        target.addProperties("drink", "tea");
        target.addProperties("food", "fish");

        target = aGraph.newVertex("three", 100);
        aGraph.addVertex(target);
        target.addProperties("drink", "tea");
        target.addProperties("food", "lahmacun");

        target = aGraph.newVertex("four", 500);
        aGraph.addVertex(target);
        target.addProperties("drink", "tea");
        target.addProperties("food", "meatball");

        target = aGraph.newVertex("five",1);
        aGraph.addVertex(target);
        target.addProperties("drink", "tea");
        target.addProperties("food", "bread");

        target = aGraph.newVertex("six", 30);
        aGraph.addVertex(target);

        aGraph.addEdge(0, 3, 5);
        aGraph.addEdge(0, 1, 3);
        aGraph.addEdge(3, 2, 1);
        aGraph.addEdge(1, 2, 7);
        aGraph.addEdge(2, 4, 4);
        aGraph.addEdge(2, 5, 10);
        aGraph.addEdge(5, 6, 5);
        aGraph.addEdge(1, 5, 20);

        aGraph.removeEdge(1, 5);
        aGraph.removeVertex("seven");


        System.out.println("\nExport matrix edges printing : \n");
        for (Double[] matrixEdges : aGraph.exportMatrix())
         System.out.print(Arrays.deepToString(matrixEdges) + "\n");

        System.out.println("\nOriginal graph printing: \n");
        aGraph.printGraph();


        MyGraph filteredGraph = aGraph.filterVertices("drink", "tea");

        System.out.println("\nFiltered graph printing: \n");
        filteredGraph.printGraph();
        
        System.out.println("\n-----Question 2-----");
        Double[] result = BreadthFirstSearch.breadthFirstSearch(aGraph,0);

        System.out.println("-----------BFS----- DFS");
        for(int i=0;i<result.length;i++) 
            System.out.printf("vertex  %d :  %3.1f       ?\n",i,result[i]);
        

    }
}
