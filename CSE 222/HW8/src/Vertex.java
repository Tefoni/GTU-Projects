package src;

import java.util.HashMap;
import java.util.Map;

public class Vertex {
    private int ID;
    private double weight;
    private String label;
    private Map<String, String> properties = new HashMap<>();

    public Vertex(String _label, double _weight, int _ID) {
        label = _label;
        weight = _weight;
        ID = _ID;
    }

    public Vertex(double _weight, int _ID) {
        label = "edge";
        weight = _weight;
        ID = _ID;
    }

    /**
     * It returns the ID of the vertex;
     * 
     * @return The ID of the vertex.
     */
    public int getID() {
        return ID;
    }

    /**
     * It returns the weight of the object.
     * 
     * @return The weight of the object.
     */
    public double getWeight() {
        return weight;
    }

    /**
     * It returns the label of the node.
     * 
     * @return The label of the node.
     */
    public String getLabel() {
        return label;
    }

    /**
     * > This function returns a map of properties
     * 
     * @return A map of properties.
     */
    public Map<String, String> getProperties() {
        return properties;
    }

    /**
     * This function sets the weight of the object to the value of the parameter
     * 
     * @param _weight The weight of the edge.
     */
    public void setWeight(double _weight) {
        weight = _weight;
    }

    @Override
    public int hashCode() {
        int hashValue = 7;
        hashValue = hashValue + 31 * ID;
        hashValue = hashValue + 31 * ((int) weight);
        hashValue = hashValue + 31 * label.hashCode();
        return hashValue;
    }

    @Override
    public boolean equals(Object obj) {
        if (obj instanceof Vertex) {
            Vertex vertex = (Vertex) obj;
            return (ID == vertex.getID() && weight == vertex.getWeight() && label == vertex.getLabel());
        } else
            return false;
    }

    /**
     * This function adds a key-value pair to the properties map
     * 
     * @param key   The name of the property.
     * @param value The value of the property.
     */
    public void addProperties(String key, String value) {
        properties.put(key, value);
    }
}
