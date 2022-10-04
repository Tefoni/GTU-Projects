package src;

/**
 * An Edge represents a relationship between two
 * vertices.
 */
public class Edge {
  private int source;
  private int dest;
  private double weight;

  public Edge(int source, int dest) {
    this.source = source;
    this.dest = dest;
    weight = 1.0;
  }

  public Edge(int source, int dest, double w) {
    this.source = source;
    this.dest = dest;
    weight = w;
  }

  /**
   * This function returns the source of the edge
   * 
   * @return The source of the edge.
   */
  public int getSource() {
    return source;
  }

  /**
   * It returns the destination of the edge.
   * 
   * @return The destination of the edge.
   */
  public int getDest() {
    return dest;
  }

  /**
   * This function returns the weight of the object
   * 
   * @return The weight of the object.
   */
  public double getWeight() {
    return weight;
  }

  /**
   * Return a String representation of the edge
   * 
   * @return A String representation of the edge
   */
  public String toString() {
    StringBuffer sb = new StringBuffer("[(");
    sb.append(Integer.toString(source));
    sb.append(", ");
    sb.append(Integer.toString(dest));
    sb.append("): ");
    sb.append(Double.toString(weight));
    sb.append("]");
    return sb.toString();
  }

  /**
   * Return true if two edges are equal. Edges
   * are equal if the source and destination
   * are equal. Weight is not conidered.
   * 
   * @param obj The object to compare to
   * @return true if the edges have the same source
   *         and destination
   */
  public boolean equals(Object obj) {
    if (obj instanceof Edge) {
      Edge edge = (Edge) obj;
      return (source == edge.source
          && dest == edge.dest);
    } else {
      return false;
    }
  }

  /**
   * Return a hash code for an edge. The hash
   * code is the source shifted left 16 bits
   * exclusive or with the dest
   * 
   * @return a hash code for an edge
   */
  public int hashCode() {
    return (source << 16) ^ dest;
  }

}
