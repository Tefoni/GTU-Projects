package src;

import java.util.LinkedList;
import java.util.Scanner;

/**
 * Street class is a class that keeps the data of many buildings and performs
 * some special operations for these buildings.
 * It also has a menu that interacts with the user.
 * 
 * @author Atacan Başaran
 * @version 1.0
 * @since 06-03-2022
 */
public class StreetLinkedList {
    private LinkedList<Buildings> leftSide; // This data stored for the left side of the street

    private LinkedList<Buildings> rightSide; // This data stored for the right side of the street

    private int length; // Length of street(same on both sides of the street)

    public StreetLinkedList(int streetLength) throws Exception {
        if (streetLength <= 0)
            throw new Exception("Street length is not valid");

        leftSide = new LinkedList<Buildings>();
        rightSide = new LinkedList<Buildings>();

        length = streetLength;
    }

    public StreetLinkedList() {
        leftSide = new LinkedList<Buildings>();
        rightSide = new LinkedList<Buildings>();

        length = 100;
    }

    public int getLength() {
        return length;
    }

    public void editMode() {
        try {
            Scanner scan = new Scanner(System.in);

            int choice, side;
            System.out.print("\n(1)Adding new building to street");
            System.out.print("\n(2)Removing building in street");
            System.out.print("\nEnter the INPUT:");
            choice = scan.nextInt();

            System.out.print("\nChoose the side you want to do the operation:");
            System.out.print("\n(1)Left Side");
            System.out.print("\n(2)Right Side");
            System.out.print("\nEnter the INPUT:");
            side = scan.nextInt();

            switch (choice) {
                case 1:
                    int buildingType;
                    System.out.print("\n-----BUILDING TYPE-----");
                    System.out.print("\n(1)House");
                    System.out.print("\n(2)Market");
                    System.out.print("\n(3)Office");
                    System.out.print("\n(4)Playground");
                    System.out.print("\nEnter the INPUT:");
                    buildingType = scan.nextInt();

                    switch (buildingType) {
                        case 1:
                            House home = createHouse();
                            if (side == 1)
                                addLeftSide(home);
                            else if (side == 2)
                                addRightSide(home);
                            else
                                System.out.print("\nWrong INPUT!!!");

                            break;

                        case 2:
                            Market shop = createMarket();
                            if (side == 1)
                                addLeftSide(shop);
                            else if (side == 2)
                                addRightSide(shop);
                            else
                                System.out.print("\nWrong INPUT!!!");

                            break;

                        case 3:
                            Office office = createOffice();
                            if (side == 1)
                                addLeftSide(office);
                            else if (side == 2)
                                addRightSide(office);
                            else
                                System.out.print("\nWrong INPUT!!!");

                            break;

                        case 4:
                            Playground playground = createPlayGround();
                            if (side == 1)
                                addLeftSide(playground);
                            else if (side == 2)
                                addRightSide(playground);
                            else
                                System.out.print("\nWrong INPUT!!!");

                            break;

                        default:
                            System.out.print("\nWrong INPUT!!!");
                    }

                    break;

                case 2:
                    int removablePosition;
                    System.out.print("\nEnter the position of the building you want to remove:");
                    removablePosition = scan.nextInt();

                    if (side == 1)
                        removeLeftSide(removablePosition);
                    else if (side == 2)
                        removeRightSide(removablePosition);
                    else
                        System.out.print("\nWrong INPUT!!!");

                    break;

                default:
                    System.out.print("\nWrong INPUT!!!");
            }
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }

    public void viewMode() {
        Scanner scan = new Scanner(System.in);

        System.out.print("\n(1)Total remainig length of street");
        System.out.print("\n(2)List of buildings(number and details)");
        System.out.print("\n(3)Number and Ratio Length of Playgrounds");
        System.out.print("\n(4)Total length of different buildings");
        System.out.print("\n(5)Skyline silhouette");
        System.out.print("\n(6)Focusing a building with starting position");
        System.out.print("\nEnter the INPUT: ");
        int choice = scan.nextInt();

        switch (choice) {
            case 1:
                System.out.printf("\nTotal remainig length of street: %d", remainingLength());
                break;

            case 2:
                System.out.println(buildingList());
                break;

            case 3:
                System.out.println(playgroundNumberRatio());
                break;

            case 4:
                System.out.println(totalLengthBuildings());
                break;

            case 5:
                System.out.println(skylineSilhouette());
                break;

            case 6:
                callingFocusing();
                break;

            default:
                System.out.print("\nWrong INPUT!!!");
        }

    }

    /**
     * Creates a home object with the menu and the data received from the user.
     *
     * @return A house arranged according to the user's request
     */
    public static House createHouse() throws Exception {
        int positionHouse, lengthHouse, heightHouse, roomHouse;
        Scanner scan = new Scanner(System.in);

        System.out.print("\nEnter starting position of house: ");
        positionHouse = scan.nextInt();
        System.out.print("\nEnter length of house: ");
        lengthHouse = scan.nextInt();
        System.out.print("\nEnter height of house: ");
        heightHouse = scan.nextInt();
        System.out.print("\nEnter room number of house: "); // Creating House object with user inputs
        roomHouse = scan.nextInt();
        System.out.print("\nEnter color of house: ");
        String colorHouse = scan.next();
        System.out.print("\nEnter owner of house: ");
        String ownerHouse = scan.next();

        return new House(positionHouse, lengthHouse, heightHouse, roomHouse, colorHouse, ownerHouse);
    }

    /**
     * Creates a market object with the menu and the data received from the user.
     *
     * @return A market arranged according to the user's request
     */
    public static Market createMarket() throws Exception {
        int positionMarket, lengthMarket, heightMarket;
        Scanner scan = new Scanner(System.in);

        System.out.print("\nEnter starting position of market: ");
        positionMarket = scan.nextInt();
        System.out.print("\nEnter length of market: ");
        lengthMarket = scan.nextInt();
        System.out.print("\nEnter height of market: ");
        heightMarket = scan.nextInt();
        System.out.print("\nEnter owner of market: "); // Creating Market object with user inputs
        String ownerMarket = scan.next();
        System.out.print("\nEnter opening time of market: ");
        String openingTime = scan.next();
        System.out.print("\nEnter closing time of market: ");
        String closingTime = scan.next();

        return new Market(positionMarket, lengthMarket, heightMarket, ownerMarket, openingTime, closingTime);
    }

    /**
     * Creates a office object with the menu and the data received from the user.
     *
     * @return A office arranged according to the user's request
     */
    public static Office createOffice() throws Exception {
        int positionOffice, lengthOffice, heightOffice;
        Scanner scan = new Scanner(System.in);

        System.out.print("\nEnter starting position of office: ");
        positionOffice = scan.nextInt();
        System.out.print("\nEnter length of office: ");
        lengthOffice = scan.nextInt();
        System.out.print("\nEnter height of office: "); // Creating Office object with user inputs
        heightOffice = scan.nextInt();
        System.out.print("\nEnter job of office: ");
        String jobOffice = scan.next();
        System.out.print("\nEnter owner of office: ");
        String ownerOffice = scan.next();
        return new Office(positionOffice, lengthOffice, heightOffice, jobOffice, ownerOffice);
    }

    /**
     * Creates a playground object with the menu and the data received from the
     * user.
     *
     * @return A playground arranged according to the user's request
     */
    public static Playground createPlayGround() throws Exception {
        int positionPlayground, lengthPlayground;
        Scanner scan = new Scanner(System.in);

        System.out.print("\nEnter starting position of playground: "); // Creating Playground object with user inputs
        positionPlayground = scan.nextInt();
        System.out.print("\nEnter length of playground: ");
        lengthPlayground = scan.nextInt();

        return new Playground(positionPlayground, lengthPlayground);
    }

    /**
     * In order to add the new building to the left of the street, it first makes
     * some checks (ex. ground control, capacity control...).
     * After these checks, it adds the building to the left of the street in the
     * correct order according to the location.
     *
     * @param Building Any building type desired to be added to the left of the
     *                 street
     */
    public void addLeftSide(Buildings Building) {
        if (Building.getPosition() + Building.getLength() > getLength()) {
            System.out.println("\nThere is not enough space to add the building");
            return; // If the location of the building to be added does not match the length of the
                    // street, it gives an error.
        }

        for (int i = 0; i < leftSide.size(); i++) {
            for (int j = leftSide.get(i).getPosition(); j <= leftSide.get(i).getPosition()
                    + leftSide.get(i).getLength(); j++) {
                for (int k = Building.getPosition(); k <= Building.getPosition() + Building.getLength(); k++) {
                    if (j == k) {
                        System.out.println("\nThere is not enough space to add the building");
                        return;
                    }
                } // It checks if there is another building at the location of the building to be
                  // added, if there is, an error is given and the method is terminated.
            }
        }

        int BuildingIndex = 0;
        for (int i = 0; i < leftSide.size(); i++) {
            if (leftSide.get(i).getPosition() < Building.getPosition()) // I store buildings in order according to their
                                                                        // location
                BuildingIndex++; // Here, the index where the building will be stored is calculated
        }

        leftSide.add(BuildingIndex, Building);
    }

    /**
     * In order to add the new building to the right of the street, it first makes
     * some checks (ex. ground control, capacity control...).
     * After these checks, it adds the building to the left of the street in the
     * correct order according to the location.
     *
     * @param Building Any building type desired to be added to the right of the
     *                 street
     */
    public void addRightSide(Buildings Building) { // Everything is the same with adding to the left
        if (Building.getPosition() + Building.getLength() > getLength()) {
            System.out.println("\nThere is not enough space to add the building");
            return;
        }
        for (int i = 0; i < rightSide.size(); i++) {
            for (int j = rightSide.get(i).getPosition(); j <= rightSide.get(i).getPosition()
                    + rightSide.get(i).getLength(); j++) {
                for (int k = Building.getPosition(); k <= Building.getPosition() + Building.getLength(); k++) {
                    if (j == k) {
                        System.out.println("\nThere is not enough space to add the building");
                        return;
                    }
                }
            }
        }

        int BuildingIndex = 0;
        for (int i = 0; i < rightSide.size(); i++) {
            if (rightSide.get(i).getPosition() < Building.getPosition())
                BuildingIndex++;
        }

        rightSide.add(BuildingIndex, Building);
    }

    /**
     * First of all, it checks the building on the left of the street whose location
     * is given.
     * Then it removes the appropriate building from the array and creates a deleted
     * copy.
     *
     * @param removePosition The location of the building to be removed from the
     *                       left side of the street
     */
    public void removeLeftSide(int removePosition) throws Exception {
        if (removePosition < 0 || removePosition > getLength()) // If the given position is not valid, an error is given
                                                                // and the program is terminated.
            throw new Exception("The position to be removed is not valid!!!");

        int removableIndex = -1;
        for (int i = 0; i < leftSide.size(); i++) {
            if (leftSide.get(i).getPosition() <= removePosition
                    && leftSide.get(i).getPosition() + leftSide.get(i).getLength() >= removePosition)
                removableIndex = i; // Calculating where the building at the given position is stored in the array

        }
        if (removableIndex != -1)
            leftSide.remove(removableIndex);
        else
            System.out.println("\nThere is no building at this position");
    }

    /**
     * First of all, it checks the building on the right of the street whose
     * location is given.
     * Then it removes the appropriate building from the array and creates a deleted
     * copy.
     *
     * @param removePosition The location of the building to be removed from the
     *                       right side of the street
     */
    public void removeRightSide(int removePosition) throws Exception { // Everything is the same with adding to the left
        if (removePosition < 0 || removePosition > getLength())
            throw new Exception("The position to be removed is not valid!!!");

        int removableIndex = -1;
        for (int i = 0; i < rightSide.size(); i++) {
            if (rightSide.get(i).getPosition() <= removePosition
                    && rightSide.get(i).getPosition() + rightSide.get(i).getLength() >= removePosition)
                removableIndex = i;

        }
        if (removableIndex != -1)
            rightSide.remove(removableIndex);
        else
            System.out.println("\nThere is no building at this position");
    }

    /**
     * Calculates the length of all buildings on the street and subtracts it from
     * the length of the street to find the remaining space.
     * 
     *
     * @return Area where the remaining building will be placed
     */
    public int remainingLength() {
        int result = 0;
        for (int i = 0; i < leftSide.size(); i++) {
            result += leftSide.get(i).getLength();
        } // The length of the buildings is subtracted from the entire length of the
          // street.
        for (int i = 0; i < rightSide.size(); i++) { // Including both sides
            result += rightSide.get(i).getLength();
        }

        return getLength() * 2 - result;
    }

    /**
     * It calculates how many building types are on the street and adds all the
     * information of those buildings after this information.
     * 
     *
     * @return Number of different building types and their details
     */
    public String buildingList() {
        int numberofHouse = 0, numberofMarket = 0, numberofOffice = 0, numberofPlayground = 0;
        for (int i = 0; i < leftSide.size(); i++) {
            if (leftSide.get(i) instanceof House)
                numberofHouse++;
            else if (leftSide.get(i) instanceof Market)
                numberofMarket++;
            else if (leftSide.get(i) instanceof Office)
                numberofOffice++;
            else if (leftSide.get(i) instanceof Playground)
                numberofPlayground++;
        }
        for (int i = 0; i < rightSide.size(); i++) { // Calculating how many of each building type
            if (rightSide.get(i) instanceof House)
                numberofHouse++;
            else if (rightSide.get(i) instanceof Market)
                numberofMarket++;
            else if (rightSide.get(i) instanceof Office)
                numberofOffice++;
            else if (rightSide.get(i) instanceof Playground)
                numberofPlayground++;
        }
        String buildList = "\nThere are " + Integer.toString(numberofHouse) + " House,"
                + Integer.toString(numberofMarket) + " Market,"
                + Integer.toString(numberofOffice) + " Office,"
                + Integer.toString(numberofPlayground) + " Playground in street";

        buildList += "\n-----Building details-----";
        for (int i = 0; i < leftSide.size(); i++) {
            buildList += leftSide.get(i).toString();
            buildList += "\n------------------------";
        }

        for (int i = 0; i < rightSide.size(); i++) {
            buildList += leftSide.get(i).toString();
            buildList += "\n------------------------";
        }

        return buildList;
    }

    /**
     * Display the number and ratio of lenth of playgrounds in the street
     * 
     *
     * @return Number and ratio of lenth of playgrounds in the street.
     */
    public String playgroundNumberRatio() {
        int lengthofPlaygrounds = 0;
        double ratio;

        for (int i = 0; i < leftSide.size(); i++) {
            if (leftSide.get(i) instanceof Playground)
                lengthofPlaygrounds += leftSide.get(i).getLength();

        } // Calculating the area occupied by the playground and the ratio of this area to
          // the street
        for (int i = 0; i < rightSide.size(); i++) {
            if (rightSide.get(i) instanceof Playground)
                lengthofPlaygrounds += rightSide.get(i).getLength();
        }
        ratio = ((double) lengthofPlaygrounds / (getLength() * 2)) * 100;
        String information = "\nOccupied length by Playgrounds: " + Integer.toString(lengthofPlaygrounds);
        information += "\nRatio of length of Playgrounds in street: %" + Double.toString(ratio);

        return information;
    }

    /**
     * Calculate the total length of street occupied by the markets, houses or
     * offices
     * 
     *
     * @return Total length of street occupied by the markets,houses or offices
     */
    public String totalLengthBuildings() {
        String lengthList;
        int lengthofHouse = 0, lenghtofMarket = 0, lengthofOffice = 0;

        for (int i = 0; i < leftSide.size(); i++) {
            if (leftSide.get(i) instanceof House)
                lengthofHouse += leftSide.get(i).getLength();
            else if (leftSide.get(i) instanceof Market)
                lenghtofMarket += leftSide.get(i).getLength();
            else if (leftSide.get(i) instanceof Office)
                lengthofOffice += leftSide.get(i).getLength();
        } // The area occupied by different building types is calculated separately
        for (int i = 0; i < rightSide.size(); i++) {
            if (rightSide.get(i) instanceof House)
                lengthofHouse += rightSide.get(i).getLength();
            else if (rightSide.get(i) instanceof Market)
                lenghtofMarket += rightSide.get(i).getLength();
            else if (rightSide.get(i) instanceof Office)
                lengthofOffice += rightSide.get(i).getLength();
        }
        lengthList = "\nOccupied length by House: " + Integer.toString(lengthofHouse);
        lengthList += "\nOccupied length by Market: " + Integer.toString(lenghtofMarket);
        lengthList += "\nOccupied length by Office: " + Integer.toString(lengthofOffice);

        return lengthList;
    }

    /**
     * Looking at the buildings on the street and creating a silhouette suitable for
     * their location and height
     *
     * @return Silhouette of the street which includes both sides
     */
    public String skylineSilhouette() {
        int maxHeight = 0, maxLength = 0;
        String silhouette = "\n";

        for (int i = 0; i < leftSide.size(); i++) {
            if (leftSide.get(i).getHeight() > maxHeight)
                maxHeight = leftSide.get(i).getHeight();
            if (leftSide.get(i).getLength() + leftSide.get(i).getPosition() > maxLength)
                maxLength = leftSide.get(i).getLength() + leftSide.get(i).getPosition();
        }
        /*
         * Finding the greatest height of buildings and the position of the last
         * building instead of making the number of elements street length to reduce the
         * number of elements of loops (on upper and above loop)
         */
        for (int i = 0; i < rightSide.size(); i++) {
            if (rightSide.get(i).getHeight() > maxHeight)
                maxHeight = rightSide.get(i).getHeight();
            if (rightSide.get(i).getLength() + rightSide.get(i).getPosition() > maxLength)
                maxLength = rightSide.get(i).getLength() + rightSide.get(i).getPosition();
        }

        for (int i = maxHeight; i >= 0; i--) {
            for (int j = 0; j < maxLength + 1; j++) {
                silhouette += characterForSilhouette(j, i);
            }
            silhouette += "\n";
        }
        /*
         * Adding the appropriate character that will come to each point in the minimum
         * area we
         * have determined with characterForSilhouette to string silhouette
         */
        for (int i = 0; i < maxLength + 1; i++) {
            silhouette += "-";
        }
        silhouette += "\n";

        return silhouette;
    }

    /**
     * Looking at the buildings on the street and deciding the right character for
     * their location and height
     *
     * @param length Horizontal position of a particular point
     * @param height Vertical position of a particular point
     * @return Appropriate character for a particular spot on the street
     */
    public String characterForSilhouette(int length, int height) {
        String symbol = " ";

        for (int i = 0; i < leftSide.size(); i++) {
            if (leftSide.get(i).getHeight() == height && (length > leftSide.get(i).getPosition()
                    && length < leftSide.get(i).getPosition() + leftSide.get(i).getLength()))
                symbol = "_"; // If position and height represent a building roof assigning _ to symbol

            else if (leftSide.get(i).getPosition() == length && height < leftSide.get(i).getHeight())
                symbol = "|"; // If position and height represent a building left side assigning | to symbol

            else if (leftSide.get(i).getPosition() + leftSide.get(i).getLength() == length
                    && height < leftSide.get(i).getHeight())
                symbol = "|"; // If position and height represent a building right side assigning | to symbol

        }

        for (int i = 0; i < rightSide.size(); i++) {
            if (rightSide.get(i).getHeight() == height && (length > rightSide.get(i).getPosition()
                    && length < rightSide.get(i).getPosition() + rightSide.get(i).getLength()))
                symbol = "_";
            else if (rightSide.get(i).getPosition() == length && height < rightSide.get(i).getHeight())
                symbol = "|";
            else if (rightSide.get(i).getPosition() + rightSide.get(i).getLength() == length
                    && height < rightSide.get(i).getHeight())
                symbol = "|";

        }

        if (symbol.equals("|")) {
            // If there is a bigger height building which includes lower inside it change |
            // to " "
            for (int i = 0; i < leftSide.size(); i++) {
                if (length > leftSide.get(i).getPosition()
                        && length < (leftSide.get(i).getPosition() + leftSide.get(i).getLength())
                        && leftSide.get(i).getHeight() > height)
                    symbol = " ";
            }
            // Looking at both side for height comparison
            for (int i = 0; i < rightSide.size(); i++) {
                if (length > rightSide.get(i).getPosition()
                        && length < (rightSide.get(i).getPosition() + rightSide.get(i).getLength())
                        && rightSide.get(i).getHeight() > height)
                    symbol = " ";
            }

        }
        if (symbol.equals("_")) {
            // If there is a bigger height building which includes lower inside it change |
            // to " "
            for (int i = 0; i < leftSide.size(); i++) {
                if (length > leftSide.get(i).getPosition()
                        && length < (leftSide.get(i).getPosition() + leftSide.get(i).getLength())
                        && leftSide.get(i).getHeight() > height)
                    symbol = " ";
            }
            // Looking at both side for height comparison
            for (int i = 0; i < rightSide.size(); i++) {
                if (length > rightSide.get(i).getPosition()
                        && length < (rightSide.get(i).getPosition() + rightSide.get(i).getLength())
                        && rightSide.get(i).getHeight() > height)
                    symbol = " ";
            }
        }

        return symbol;
    }

    /**
     * It calls the function that focuses on a specific information of the building
     * and print this information and all the details of the building.
     * 
     *
     */
    public void callingFocusing() {
        Scanner scan = new Scanner(System.in);

        System.out.print("\nEnter the position of the building you want to focus on: ");
        int wantedPosition = scan.nextInt();
        int flag = 0;

        for (int i = 0; i < leftSide.size(); i++) { // Checking whether there is a building in the place to be focused
                                                    // on the left of the street
            for (int j = leftSide.get(i).getPosition(); j <= leftSide.get(i).getPosition()
                    + leftSide.get(i).getLength(); j++) {
                if (j == wantedPosition) {
                    flag++;
                    System.out.println("\nBuilding details on left side: " + leftSide.get(i).toString());
                    System.out.print("\nFocusing results on left side: " + leftSide.get(i).focus());
                    break;
                }

            }
        }
        for (int i = 0; i < rightSide.size(); i++) { // Checking whether there is a building in the place to be focused
                                                     // on the left of the street
            for (int j = rightSide.get(i).getPosition(); j <= rightSide.get(i).getPosition()
                    + rightSide.get(i).getLength(); j++) {
                if (j == wantedPosition) {
                    flag++;
                    System.out.println("\nBuilding details on right side: " + rightSide.get(i).toString());
                    System.out.print("\nFocusing results on right side: " + rightSide.get(i).focus());
                    break;
                }
            }
        }
        if (flag == 0) {
            System.out.println("\nThere is no building to focus on in this position");
        }
    }

    /**
     * It calls the function that focuses on a specific information of the building
     * and print this information and all the details of the building.
     * 
     * @param wantedPosition Location of the building whose specific information is
     *                       expected
     */
    public void callingFocusing(int wantedPosition) { // Same as no parameter callingFocusin() but this is for driver
                                                      // function
        int flag = 0;

        for (int i = 0; i < leftSide.size(); i++) {
            for (int j = leftSide.get(i).getPosition(); j <= leftSide.get(i).getPosition()
                    + leftSide.get(i).getLength(); j++) {
                if (j == wantedPosition) {
                    flag++;
                    System.out.println("\nBuilding details on left side: " + leftSide.get(i).toString());
                    System.out.print("\nFocusing results on left side: " + leftSide.get(i).focus() + "\n");
                    break;
                }

            }
        }
        for (int i = 0; i < rightSide.size(); i++) {
            for (int j = rightSide.get(i).getPosition(); j <= rightSide.get(i).getPosition()
                    + rightSide.get(i).getLength(); j++) {
                if (j == wantedPosition) {
                    flag++;
                    System.out.println("\nBuilding details on right side: " + rightSide.get(i).toString());
                    System.out.print("\nFocusing results on right side: " + rightSide.get(i).focus() + "\n");
                    break;
                }

            }
        }
        if (flag == 0) {
            System.out.println("\nThere is no building to focus on in this position");
        }
    }

}
