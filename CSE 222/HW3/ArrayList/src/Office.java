package src;

/**
 * The Office is a class that represents a custom building type extended from
 * the Buildings class.
 * 
 * @author Atacan Başaran
 * @version 1.0
 * @since 06-03-2022
 */
public class Office extends Buildings {
    private String job;
    private String owner;

    public Office(int officePosition, int officeLength, int officeHeight, String officeJob, String officeOwner)
            throws Exception {
        super(officePosition, officeLength, officeHeight);

        setJob(officeJob);
        setOwner(officeOwner);

    }

    public void setJob(String officeJob) {
        job = officeJob;
    }

    public void setOwner(String officeOwner) {
        owner = officeOwner;
    }

    public String getJob() {
        return job;
    }

    public String getOwner() {
        return owner;
    }

    /**
     * This method gives all information of Office
     *
     * @return ll the details of the Office
     */
    @Override
    public String toString() {
        String details = super.toString();
        details += "\nOffice job: " + getJob();
        details += "\nOffice owner: " + getOwner();

        return details;
    }

    public boolean equals(Office other) {
        if (!super.equals(other) || !(getJob().equals(other.getJob())) || !(getOwner().equals(other.getOwner())))
            return false;

        else
            return true;
    }

    /**
     * Creates a copy office with the same office data
     *
     * @return Clone of existing Office
     */
    @Override
    protected Object clone() {
        Office copyClone = null;

        try {
            copyClone = new Office(getPosition(), getLength(), getHeight(), getJob(), getOwner());
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }

        return copyClone;
    }

    /**
     * Allows creation of a special number for each office object
     *
     * @return A unique number for Office
     */
    @Override
    public int hashCode() {
        int result = super.hashCode();
        result = 31 * result + getJob().hashCode();
        result = 31 * result + getOwner().hashCode();

        return result;
    }

    /**
     * This method gives some specific properties of Office
     *
     * @return Some specific information of the Office
     */
    @Override
    public String focus() {
        String information = getJob();

        return information;
    }
}
