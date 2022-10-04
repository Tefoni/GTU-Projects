package src;

/**
 * The Market is a class that represents a custom building type extended from the Buildings class.
 * 
 * @author Atacan Başaran
 * @version 1.0
 * @since 06-03-2022
 */
public class Market extends Buildings {
    private String owner;
    private String openingTime;
    private String closingTime;

    public Market(int marketPosition, int marketLength, int marketHeight, String marketOwner,
            String marketOpeningTime, String marketClosingTime) throws Exception {
        super(marketPosition, marketLength, marketHeight);

        setOwner(marketOwner);
        setOpeningTime(marketOpeningTime);
        setClosingTime(marketClosingTime);
    }

    public void setOwner(String marketOwner) {
        owner = marketOwner;
    }

    public void setOpeningTime(String marketOpeningTime) {
        openingTime = marketOpeningTime;
    }

    public void setClosingTime(String marketClosingTime) {
        closingTime = marketClosingTime;
    }

    public String getOwner() {
        return owner;
    }

    public String getOpeningTime() {
        return openingTime;
    }

    public String getClosingTime() {
        return closingTime;
    }

    /**
     * This method gives all information of Office
     *
     * @return All the details of the Office
     */
    @Override
    public String toString() {
        String details = super.toString();
        details += "\nMarket owner: " + getOwner();
        details += "\nMarket working times: " + getOpeningTime() + " - " + getClosingTime();

        return details;
    }

    public boolean equals(Market other) {
        if (!super.equals(other) || !(getOwner().equals(other.getOwner()))
                || !(getOpeningTime().equals(other.getOpeningTime()))
                || !(getClosingTime().equals(other.getClosingTime())))
            return false;

        else
            return true;
    }

    /**
     * Creates a copy market with the same market data
     *
     * @return Clone of existing Market
     */
    @Override
    protected Object clone() {
        Market copyClone = null;

        try {
            copyClone = new Market(getPosition(), getLength(), getHeight(), getOwner(), getOpeningTime(),
                    getClosingTime());
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }

        return copyClone;
    }

    /**
     * Allows creation of a special number for each market object
     *
     * @return A unique number for Market
     */
    @Override
    public int hashCode() {
        int result = super.hashCode();
        result = 31 * result + getOwner().hashCode();
        result = 31 * result + getOpeningTime().hashCode();
        result = 31 * result + getClosingTime().hashCode();

        return result;
    }

    /**
     * This method gives some specific properties of Market
     *
     * @return Some specific information of the Market
     */
    @Override
    public String focus() {
        String information = getClosingTime();

        return information;
    }
}
