package src;

/**
 * The House is a class that represents a custom building type extended from the
 * Buildings class.
 * 
 * @author Atacan Başaran
 * @version 1.0
 * @since 06-03-2022
 */
public class House extends Buildings {
    private int room;
    private String color;
    private String owner;

    public House(int housePosition, int houseLength, int houseHeight, int roomNumber, String houseColor,
            String houseOwner) throws Exception {
        super(housePosition, houseLength, houseHeight);

        if (roomNumber <= 0)
            throw new Exception("INVALID House inputs");

        setRoom(roomNumber);
        setColor(houseColor);
        setOwner(houseOwner);
    }

    public void setRoom(int roomNumber) {
        room = roomNumber;
    }

    public void setColor(String houseColor) {
        color = houseColor;
    }

    public void setOwner(String houseOwner) {
        owner = houseOwner;
    }

    public int getRoom() {
        return room;
    }

    public String getColor() {
        return color;
    }

    public String getOwner() {
        return owner;
    }

    /**
     * This method gives all information of House
     *
     * @return All the details of the House
     */
    @Override
    public String toString() {
        String details = super.toString();
        details += "\nHouse room number: " + getRoom();
        details += "\nHouse color: " + getColor();
        details += "\nHouse owner: " + getOwner();

        return details;
    }

    public boolean equals(House other) {
        if (!super.equals(other) || getRoom() != other.getRoom() || !(getColor().equals(other.getColor()))
                || !(getOwner().equals(other.getOwner())))
            return false;

        else
            return true;
    }

    /**
     * Creates a copy house with the same market data
     *
     * @return Clone of existing House
     */
    @Override
    protected Object clone() {
        House copyClone = null;

        try {
            copyClone = new House(getPosition(), getLength(), getHeight(), getRoom(), getColor(), getOwner());
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }

        return copyClone;
    }

    /**
     * Allows creation of a special number for each house object
     *
     * @return A unique number for House
     */
    @Override
    public int hashCode() {
        int result = super.hashCode();

        result = 31 * result + getRoom();
        result = 31 * result + getOwner().hashCode();
        result = 31 * result + getColor().hashCode();

        return result;
    }

    /**
     * This method gives some specific properties of House
     *
     * @return Some specific information of the House
     */
    @Override
    public String focus() {
        String information = getOwner();

        return information;
    }

}
