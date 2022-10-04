package src;

import java.util.*;

public class BreadthFirstSearch {

  private static Double[] parentWeight;

  /**
   * Perform a breadth-first search of a graph and calculate total distance path for each vertex during traversal
   * 
   * @param graph The graph to be searched
   * @param start The start vertex
   * @return The total distances of the path for accessing each vertex during the
   *         traversal,
   */
  public static Double[] breadthFirstSearch(Graph graph, int start) {
    Queue<Integer> theQueue = new LinkedList<Integer>();

    // Declare array parent and initialize its elements to -1.
    // Declare arrat parentWeight for calculate total distance for a path
    int[] parent = new int[graph.getNumV()];
    parentWeight = new Double[graph.getNumV()];
    for (int i = 0; i < graph.getNumV(); i++) {
      parent[i] = -1;
      parentWeight[i] = Double.MAX_VALUE;
    }
    // Declare array identified and
    // initialize its elements to false.
    boolean[] identified = new boolean[graph.getNumV()];
    /*
     * Mark the start vertex as identified and insert it
     * into the queue
     */
    identified[start] = true;
    theQueue.offer(start);
    /* While the queue is not empty */
    while (!theQueue.isEmpty()) {
      /*
       * Take a vertex, current, out of the queue.
       * (Begin visiting current).
       */
      int current = theQueue.remove();
      /* Examine each vertex, neighbor, adjacent to current. */
      Iterator<Vertex> itr = graph.edgeIterator(current);
      while (itr.hasNext()) {
        Vertex edge = itr.next();
        int neighbor = edge.getID();
        // If neighbor has not been identified
        if (!identified[neighbor] || parentWeight[neighbor] > edge.getWeight()) {
          // Mark it identified.
          identified[neighbor] = true;
          // Place it into the queue.
          theQueue.offer(neighbor);
          /*
           * Insert the edge (current, neighbor)
           * into the tree.
           */
          parent[neighbor] = current;
          parentWeight[neighbor] = edge.getWeight();
        }
      }
      // Finished visiting current.
    }

    Double[] result = new Double[graph.getNumV()];
    for (int i = 0; i < result.length; i++)
      result[i] = 0.0;

    // After visiting create result array for calculate total distance on each
    // vertex

    for (int i = 0; i < parent.length; i++) {
      int current = i;
      while (parentWeight[current] != Double.MAX_VALUE) {
        result[i] += parentWeight[current];
        current = parent[current];
      }
    }
    return result;
  }
}
