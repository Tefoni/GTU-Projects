import src.Recursions;

public class DriverCode {
    public static void main(String[] args) {
        String bigString = "GTUdenemeGTUdenemeGTUdenemeGTUdeneme";
        String smallString = "GTU";
        String smallString2 = "deneme";
        System.out.println("Big String:  " + bigString);
        System.out.println("Small string1:  " + smallString);
        System.out.println("Small string2:  " + smallString2);
        System.out.println("Search for smallstring1 in bigstring(occurrence 3):  "+Recursions.question1(smallString, bigString,3));
        System.out.println("Search for smallstring1 in bigstring(occurrence 50):  "+Recursions.question1(smallString, bigString,50));
        System.out.println("Search for Atacan in bigstring(occurrence 1):  "+ Recursions.question1("Atacan", bigString,1));
        System.out.println("Search for smallstring2 in bigstring(occurrence 1):  "+Recursions.question1(smallString2, bigString,1));
        System.out.println("Search for smallstring2 in bigstring(occurrence -5):  "+Recursions.question1(smallString2, bigString,-5) + "\n\n\n");


    
        int[] myarray = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
        int[] myarray2 = {};

        System.out.print("myarray for Question2: ");
        for (int i = 0; i < myarray.length; i++)
            System.out.printf("%d ", myarray[i]);

        System.out.println("\nQuestion 1 for myarray(Bound 4,10):" + Recursions.question2(myarray, 4, 10));
        System.out.println("Question 1 for myarray(Bound 15,25):" + Recursions.question2(myarray, 15, 25));
        System.out.println("Question 1 for myarray(Bound -5,0):" + Recursions.question2(myarray, -5, 0));
        System.out.println("Question 1 for myarray(Bound 25,50):" + Recursions.question2(myarray, 25, 50));
        System.out.println("Question 1 for empty array:" + Recursions.question2(myarray2, 0, 10)+ "\n\n\n");

         int[] myarray3 = {1,5,2,9,3,4,3,2,5};
         int[] myarray4 = {};

         System.out.print("myarray for Question3: ");
         for (int i = 0; i < myarray3.length; i++)
             System.out.printf("%d ", myarray3[i]);

        System.out.println("\nQuestion 3 for myarray(Target 7):  "+ Recursions.question3(myarray3,7));
        System.out.println("Question 3 for myarray(Target 0):  "+ Recursions.question3(myarray3,0));
        System.out.println("Question 3 for myarray(Target 5):  "+ Recursions.question3(myarray3,5));
        System.out.println("Question 3 for empty array(Target 5):  "+ Recursions.question3(myarray4,5));

    }
}
