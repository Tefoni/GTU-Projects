package src;

/**
 * The Buildings is a class to build some building types from a specific base
 * 
 * @author Atacan Başaran
 * @version 1.0
 * @since 06-03-2022
 */
public abstract class Buildings {
    private int length;
    private int height;
    private int position;

    Buildings(int positionValue, int lengthValue, int heightValue) throws Exception {
        if (positionValue < 0 || lengthValue <= 0 || heightValue <= 0)
            throw new Exception("Building inputs are not VALID!!!");

        setLength(lengthValue);
        setHeight(heightValue);
        setPosition(positionValue);
    }

    public void setLength(int lengthValue) {
        length = lengthValue;
    }

    public void setHeight(int heightValue) {
        height = heightValue;
    }

    public void setPosition(int positionValue) {
        position = positionValue;
    }

    public int getLength() {
        return length;
    }

    public int getHeight() {
        return height;
    }

    public int getPosition() {
        return position;
    }

    public String toString() {
        String details;

        details = "\nBuilding starting position: " + Integer.toString(getPosition());
        details += "\nBuilding length: " + Integer.toString(getLength());
        details += "\nBuilding height: " + Integer.toString(getHeight());

        return details;
    }

    public boolean equals(Buildings other) {
        if (getPosition() != other.getPosition() || getHeight() != other.getHeight()
                || getLength() != other.getLength())
            return false;

        else
            return true;
    }

    protected abstract Object clone();

    public int hashCode() {
        int result = 17;
        result = 31 * result + getPosition();
        result = 31 * result + getLength();
        result = 31 * result + getHeight();

        return result;
    }
    /**
     * This method gives some specific properties of the specified building
     *
     * @return Some specific information of the building
     */
    public abstract String focus();
}
