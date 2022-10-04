import src.BinarySearchTree;
import src.BinaryTree;
import src.QuickSort;
import java.util.Random;

public class Driver {
    
    public static void question1() {
        long startTime,endTime,totalTime;

        BinaryTree<Integer> atree = new BinaryTree<Integer>();
        Random rand = new Random();
        for(int i=0;i<10;i++) {
            int randomInteger = rand.nextInt(50);
            atree.insert(randomInteger);
        }

        Integer[] myarray = new Integer[10];
        for(int i=0;i<myarray.length;i++) {
            int randomInteger = rand.nextInt(50);
            myarray[i] = randomInteger;

            for (int j = 0; j < i; j++) {
                if (myarray[i] == myarray[j]) {
                    i--; //if myarray[i] is a duplicate of myarray[j], then run the outer loop on i again
                    break;
                }
            }
        }


        QuickSort<Integer> sort = new QuickSort<Integer>();
        startTime = System.nanoTime();
        sort.quickSort(myarray);
        endTime = System.nanoTime();

        long totaltimeofSort10 = (endTime-startTime)/100;
        System.out.println("Binary tree Structure(Size 10): \n" + atree.toString());
        System.out.println("*************************");
        System.out.println("Input array(Size 10): ");
        for(int i=0;i<myarray.length;i++) {
            System.out.print(myarray[i] +" ");
        }

        System.out.println("\n\n\nConverted binary search tree:");

        startTime = System.nanoTime();
        atree = atree.convertBinarySearchTree(myarray);
        endTime = System.nanoTime();
        totalTime = (endTime-startTime)/100;

        System.out.println(atree.toString());
        System.out.println("*************************");

        System.out.println("Sorting 10 element with Quicksort Time: " + totaltimeofSort10);
        System.out.println("Converting 10 element BinaryTree to BinarySearchTree Time: " + totalTime);


        BinaryTree<Integer> size100tree = new BinaryTree<Integer>();
        Integer[] size100array = new Integer[100];
        for(int i=0;i<100;i++) {
            int randomInteger = rand.nextInt(500);
            atree.insert(randomInteger);
        }

        for(int i=0;i<size100array.length;i++) {
            int randomInteger = rand.nextInt(500);
            size100array[i] = randomInteger;

            for (int j = 0; j < i; j++) {
                if (size100array[i] == size100array[j]) {
                    i--; //if myarray[i] is a duplicate of myarray[j], then run the outer loop on i again
                    break;
                }
            }
        }
    
    // Printing 100 element tree take so much space so i didnt print them just measure runtime

    startTime = System.nanoTime();
    sort.quickSort(size100array);
    endTime = System.nanoTime();
    totalTime = (endTime-startTime)/100;

    System.out.println("Sorting 100 element with Quicksort Time: " + totalTime);
    
    startTime = System.nanoTime();
    size100tree = size100tree.convertBinarySearchTree(size100array);
    endTime = System.nanoTime();
    totalTime = (endTime-startTime)/100;

    System.out.println("Converting 100 element BinaryTree to BinarySearchTree Time: " + totalTime);

    }

    public static void question2() {
        BinarySearchTree<Integer> asearchtree = new BinarySearchTree<Integer>();
        long startTime,endTime,totalTime;

        asearchtree.add(10);
        asearchtree.add(7);
        asearchtree.add(20);
        asearchtree.add(5);
        asearchtree.add(30);


        System.out.println(asearchtree.toString());
        startTime = System.nanoTime();
        asearchtree = asearchtree.convertBSTtoAVLTree();
        endTime = System.nanoTime();
        totalTime = (endTime-startTime)/100;
        System.out.println("*************************");
        System.out.println(asearchtree.toString());

        System.out.println("Converting 5 element BinarySearchTree to AVLTree Time: " + totalTime);

    }

    public static void main(String[] args) {
    System.out.println("------------ Question 1 ------------\n\n");
    question1();
    System.out.println("\n\n------------ Question 2 ------------\n\n");
    question2(); 
    }

}
