package src;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.LinkedList;

public class MyGraph implements DynamicGraph {
    private int numVertex; // graphdaki halihazırda bulunan vertex sayısı
    private boolean directed;
    private ArrayList<Vertex> vertexs;
    private ArrayList<LinkedList<Vertex>> edges;

    public MyGraph(boolean _directed) {
        directed = _directed;
        numVertex = 0;
        edges = new ArrayList<LinkedList<Vertex>>();
        vertexs = new ArrayList<>();
    }

    /**
     * Returns the number of vertices in the graph.
     * 
     * @return The number of vertices in the graph.
     */
    public int getNumV() {
        return numVertex;
    }

    /**
     * Returns true if the graph is directed, false otherwise.
     * 
     * @return The boolean value of the directed variable.
     */
    public boolean isDirected() {
        return directed;
    }

    /**
     * Insert a new edge into the graph.
     * 
     * @param edge The new edge
     */
    @Override
    public void insert(Edge edge) {
        edges.get(edge.getSource()).add(new Vertex(edge.getWeight(), edge.getDest()));

        if (!isDirected())
            edges.get(edge.getDest()).add(new Vertex(edge.getWeight(), edge.getSource()));

    }

    /**
     * Determine whether an edge exists.
     * 
     * @param source The source vertex
     * @param dest   The destination vertex
     * @return true if there is an edge from source to dest
     */
    @Override
    public boolean isEdge(int source, int dest) {
        for (Vertex target : edges.get(source)) {
            if (target.getID() == dest)
                return true;
        }
        return false;
    }

    /**
     * Get the edge between two vertices.
     * 
     * @param source The source vertex
     * @param dest   The destination vertex
     * @return The Edge between these two vertices
     *         or an Edge with a weight of
     *         Double.POSITIVE_INFINITY if there is no edge
     */
    @Override
    public Edge getEdge(int source, int dest) {
        for (Vertex target : edges.get(source)) {
            if (target.getID() == dest)
                return new Edge(source, target.getID(), target.getWeight());
        }
        return null;
    }

    /**
     * Return an iterator to the edges connected
     * to a given vertex.
     * 
     * @param source The source vertex
     * @return An Iterator<Vertex> to the vertices
     *         connected to source
     */
    @Override
    public Iterator<Vertex> edgeIterator(int source) {
        return edges.get(source).iterator();
    }

    /**
     * This function creates a new vertex with the given label and weight and
     * returns it
     * 
     * @param label  The name of the vertex.
     * @param weight the weight of the vertex
     * @return A new vertex with the label, weight, and numVertex.
     */
    public Vertex newVertex(String label, double weight) {
        return new Vertex(label, weight, numVertex);
    }

    /**
     * It adds a vertex to the graph
     * 
     * @param new_vertex The vertex to be added to the graph
     */
    public void addVertex(Vertex new_vertex) {
        numVertex++;
        edges.add(new LinkedList<Vertex>());
        vertexs.add(new_vertex);
    }

    /**
     * It adds an edge between two vertices
     * 
     * @param vertexID1 The ID of the first vertex.
     * @param vertexID2 The ID of the vertex that the edge will be connected to.
     * @param weight    the weight of the edge
     */
    public boolean addEdge(int vertexID1, int vertexID2, double weight) {
        boolean flag = false;
        if (!(vertexID1 >= 0 && vertexID1 < vertexs.size()) || !(vertexID2 >= 0 && vertexID2 < vertexs.size()))
            return false; // out of bounds control

        if (vertexs.get(vertexID1) == null || vertexs.get(vertexID2) == null)
            return false; // Controls graph has vertexID1 and vertexID2 or not

        if (!isDirected()) {
            for (Vertex target : edges.get(vertexID2)) { // Controls that edge already exists or not
                if (target.getID() == vertexID1) {
                    target.setWeight(weight);
                    flag = true;
                }
            }

            if (!flag)
                edges.get(vertexID2).add(new Vertex(weight, vertexID1));
            // If edge is not already exists and if graph is not directed
            // method add reverse edge

        }

        for (Vertex target : edges.get(vertexID1)) {
            if (target.getID() == vertexID2) {
                target.setWeight(weight);
                return false;
            }
        }

        edges.get(vertexID1).add(new Vertex(weight, vertexID2));

        return true;
    }

    /**
     * It removes the given edge on graph
     * 
     * @param vertexID1 The ID of the first vertex.
     * @param vertexID2 The ID of the vertex that is the destination of the edge.
     * @return The method returns true if edge deleted,returns false otherwise
     */
    public boolean removeEdge(int vertexID1, int vertexID2) {
        if (!isDirected()) {
            for (Vertex anEdge : edges.get(vertexID2)) {
                if (anEdge.getID() == vertexID1) {
                    edges.get(vertexID2).remove(anEdge); // If graph undirected and finds given edge remove the reverse
                                                         // of edge.
                    break;
                }
            }
        }

        for (Vertex anEdge : edges.get(vertexID1)) {
            if (anEdge.getID() == vertexID2) {
                edges.get(vertexID1).remove(anEdge); // If finds the given edge remove it
                return true;
            }
        }

        return false;
    }

    /**
     * It removes a vertex from the graph by setting the vertex to null and removing
     * all edges that point
     * to the vertex
     * 
     * @param vertexID The ID of the vertex to be removed.
     * @return The removed vertex.
     */
    public Vertex removeVertex(int vertexID) {
        Vertex removedVertex = null;
        for (Vertex anVertex : vertexs) {
            if (anVertex.getID() == vertexID) {
                removedVertex = anVertex;
                vertexs.set(anVertex.getID(), null);
                // If finds the target ID,set position to null
            }
        }

        if (removedVertex != null) {
            edges.set(vertexID, null);
            for (LinkedList<Vertex> edgesforaVertex : edges) {
                for (Vertex anEdge : edgesforaVertex) {
                    if (anEdge.getID() == vertexID)
                        edgesforaVertex.remove(anEdge); // Remove all edges that point to target vertex
                }
            }
        }
        return removedVertex;
    }

    /**
     * It removes a vertex from the graph by removing it from the vertexs list and
     * then removing all edges
     * that are connected to it
     * 
     * @param label the label of the vertex to be removed
     * @return The removed vertex.
     */
    public Vertex removeVertex(String label) {
        Vertex removedVertex = null;
        int removedVertexID = -1;

        for (Vertex anVertex : vertexs) {
            if (anVertex.getLabel().equals(label)) {
                removedVertex = anVertex;
                removedVertexID = anVertex.getID();
                vertexs.remove(anVertex);
                // If finds the target vertex,remove it
            }
        }

        if (removedVertexID != -1) {
            edges.set(removedVertexID, null);
            for (LinkedList<Vertex> edgesforaVertex : edges) {
                for (Vertex anEdge : edgesforaVertex) {
                    if (anEdge.getID() == removedVertexID) {
                        edgesforaVertex.remove(anEdge);
                        // Remove all edges that point to target vertex
                    }
                }

            }

        }
        return removedVertex;
    }

    /**
     * It creates a new graph, and adds the vertices and their edges that have the
     * given property to
     * the new graph
     * 
     * @param key    The key of the property to be filtered.
     * @param filter The value of the property that the vertex must have to be
     *               included in the filtered
     *               graph.
     * @return A new graph with the filtered vertices.
     */
    public MyGraph filterVertices(String key, String filter) {
        MyGraph filteredGraph = new MyGraph(isDirected());

        for (Vertex aVertex : vertexs) {
            filteredGraph.addVertex(null);

            if (aVertex.getProperties().get(key) == filter) {
                filteredGraph.vertexs.set(aVertex.getID(), aVertex);
            }
        }

        int source_vertex_ID = 0;
        for (LinkedList<Vertex> edgesofaVertex : edges) { // Controls all vertexs
            for (Vertex anEdge : edgesofaVertex) // Controls all edges of a vertex
                filteredGraph.addEdge(source_vertex_ID, anEdge.getID(), anEdge.getWeight());
            // If graph has source and destination vertex,adding their edges

            source_vertex_ID++;
        }

        return filteredGraph;
    }

    /**
     * It takes a graph and returns a matrix representation of the graph
     * 
     * @return A 2D array of Edge weights.
     */
    public Double[][] exportMatrix() {
        Double[][] adjacentMatrix = new Double[numVertex][numVertex];

        int i = 0;
        for (LinkedList<Vertex> SourceVertexs : edges) {
            for (Vertex DestinationVertex : SourceVertexs) {
                adjacentMatrix[i][DestinationVertex.getID()] = DestinationVertex.getWeight();
            }
            i++;
        }

        return adjacentMatrix;
    }

    /**
     * It prints the graph in sourceVertex -> destinationVertex  (Weight of edge) format
     * 
     */
    public void printGraph() {
        System.out.println("Source_vertex -> Destination_vertex  (Weight of edge) \n");

        for (int i = 0; i < edges.size(); i++) {
            if (edges.get(i) != null) {
                for (Vertex destinationVertex : edges.get(i)) {
                    System.out.println(i + " -> " + destinationVertex.getID() + "  ("
                            + destinationVertex.getWeight() + ")");
                }
            }
        }
        System.out.println("\n\n");
    }

}
