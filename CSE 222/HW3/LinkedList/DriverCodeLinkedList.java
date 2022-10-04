import java.util.Scanner;

import src.*;

public class DriverCodeLinkedList {
    /**
     * A menu that creates a street, applies the designed methods and guides the
     * user.
     *
     */
    public static void menu() throws Exception {
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter the length of street: ");
        int lengthStreet = scan.nextInt();
        StreetLinkedList street = new StreetLinkedList(lengthStreet);

        int choice = 0;
        do {
            System.out.print("\n-----MENU-----");
            System.out.print("\n(1) Editing mode");
            System.out.print("\n(2) View mode");
            System.out.print("\n(0) EXIT");
            System.out.print("\nEnter the INPUT:");
            choice = scan.nextInt();

            switch (choice) {
                case 1:
                    street.editMode();
                    break;

                case 2:
                    street.viewMode();
                    break;

                case 0:
                    break;

                default:
                    System.out.println("\nWrong INPUT!!!");
            }

        } while (choice != 0);
    }

    /**
     * A driver function which tries all created methods
     *
     */
    public static void driverFunction() throws Exception {
        StreetLinkedList testStreet = new StreetLinkedList(100);
        testStreet.addLeftSide(new House(0, 5, 3, 4, "mavi", "Atacan"));
        testStreet.addLeftSide(new Market(7, 10, 5, "Mehmet", "08.00", "19.00"));
        testStreet.addLeftSide(new Office(20, 4, 20, "Textile", "Nurettin"));
        testStreet.addLeftSide(new Playground(40, 30));
        testStreet.addLeftSide(new House(15, 5, 5, 3, "pembe", "Ayşe"));
        System.out.println(
                "\nBuildings with suitable information have been added to the LEFT side of the street. An error message is given for those that do not.");

        testStreet.addRightSide(new House(0, 5, 3, 4, "mor", "Elif"));
        testStreet.addRightSide(new Market(7, 10, 5, "Hikmet", "06.00", "21.00"));
        testStreet.addRightSide(new Office(20, 4, 20, "Freelancer", "Bedirhan"));
        testStreet.addRightSide(new Playground(40, 30));
        testStreet.addRightSide(new House(15, 5, 5, 3, "pembe", "Ayşe"));
        System.out.println(
                "\nBuildings with suitable information have been added to the RIGHT side of the street. An error message is given for those that do not.");

        System.out.printf("\nTotal remainig length of street: %d", testStreet.remainingLength());

        System.out.println(testStreet.buildingList());

        System.out.println(testStreet.playgroundNumberRatio());

        System.out.println(testStreet.totalLengthBuildings());

        System.out.println(testStreet.skylineSilhouette());

        testStreet.callingFocusing(3);
        testStreet.callingFocusing(150);

        testStreet.removeLeftSide(15);
        testStreet.removeLeftSide(90);

        testStreet.removeRightSide(50);
        testStreet.removeRightSide(80);
        System.out.println(
                "\nThe buildings in the given position on the left side of the street have been removed. An error message is given when there is no building in the given position.");

        System.out.printf("\nTotal remainig length of street: %d", testStreet.remainingLength());

        System.out.println(testStreet.buildingList());

        System.out.println(testStreet.playgroundNumberRatio());

        System.out.println(testStreet.totalLengthBuildings());

        System.out.println(testStreet.skylineSilhouette());

        testStreet.callingFocusing(20);
        testStreet.callingFocusing(-5);

        House testing1 = new House(0, 5, 5, 3, "gri", "Emre");
        House testing2 = new House(0, 5, 5, 3, "gri", "Emre");
        House testing3 = new House(5, 10, 10, 3, "kahverengi", "Salih");
        System.out.println("\nTesting equals method");
        if (testing1.equals(testing2))
            System.out.println("Testing1 and testing2 house are equal each other");
        if (!(testing1.equals(testing3)))
            System.out.println("Testing1 and testing3 house are not equal each other");

        System.out.println("\nTesting hashcode method");
        System.out.print("\nTesting1 hashcode: " + testing1.hashCode());
        System.out.print("\nTesting2 hashcode: " + testing2.hashCode());
        System.out.print("\nTesting3 hashcode: " + testing3.hashCode());

    }

    public static void main(String[] args) {
        try {
            driverFunction();
            System.out.println("\nDriver function finished, going to the menu...");
            menu();
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }

    }
}
