package src;

public interface DynamicGraph extends Graph {
    /**
     * This function creates a new vertex with the given label and weight and
     * returns it
     * 
     * @param label  The name of the vertex.
     * @param weight the weight of the vertex
     * @return A new vertex with the label, weight, and numVertex.
     */
    public Vertex newVertex(String label, double weight);

    /**
     * It adds a vertex to the graph
     * 
     * @param new_vertex The vertex to be added to the graph
     */
    public void addVertex(Vertex new_vertex);

    /**
     * It adds an edge between two vertices
     * 
     * @param vertexID1 The ID of the first vertex.
     * @param vertexID2 The ID of the vertex that the edge will be connected to.
     * @param weight    the weight of the edge
     */
    public boolean addEdge(int vertexID1, int vertexID2, double weight);

    /**
     * It removes the given edge on graph
     * 
     * @param vertexID1 The ID of the first vertex.
     * @param vertexID2 The ID of the vertex that is the destination of the edge.
     * @return The method returns true if edge deleted,returns false otherwise
     */
    public boolean removeEdge(int vertexID1, int vertexID2);

    /**
     * It removes a vertex from the graph by setting the vertex to null and removing
     * all edges that point
     * to the vertex
     * 
     * @param vertexID The ID of the vertex to be removed.
     * @return The removed vertex.
     */
    public Vertex removeVertex(int vertexID);

    /**
     * It removes a vertex from the graph by removing it from the vertexs list and
     * then removing all edges
     * that are connected to it
     * 
     * @param label the label of the vertex to be removed
     * @return The removed vertex.
     */
    public Vertex removeVertex(String label);

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
    public Graph filterVertices(String key, String filter);

    /**
     * It takes a graph and returns a matrix representation of the graph
     * 
     * @return A 2D array of Edge weights.
     */
    public Double[][] exportMatrix();

    /**
     * It prints the graph in sourceVertex -> destinationVertex (Weight of edge)
     * format
     * 
     */
    public void printGraph();
}
