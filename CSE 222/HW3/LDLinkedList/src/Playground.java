package src;

/**
 * The Playground is a class that represents a custom building type extended from the Buildings class.
 * 
 * @author Atacan Başaran
 * @version 1.0
 * @since 06-03-2022
 */
public class Playground extends Buildings {
    public Playground(int playgroundPosition, int playgroundLength) throws Exception {
        super(playgroundPosition, playgroundLength, 5);
    }

    /**
     * This method gives all information of Playground
     *
     * @return All the details of the Playground
     */
    @Override
    public String toString() {
        String details = super.toString();
        return details;
    }

    public boolean equals(Playground other) {
        return super.equals(other);
    }

    /**
     * Creates a copy playground with the same market data
     *
     * @return Clone of existing Playground
     */
    @Override
    protected Object clone() {
        Playground copyClone = null;

        try {
            copyClone = new Playground(getPosition(), getLength());
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }

        return copyClone;
    }

    /**
     * Allows creation of a special number for each playground object
     *
     * @return A unique number for Playground
     */
    @Override
    public int hashCode() {
        return super.hashCode();
    }

    /**
     * This method gives some specific properties of Playground
     *
     * @return Some specific information of the Playground
     */
    @Override
    public String focus() {
        String information = Integer.toString(getLength());

        return information;
    }

}
