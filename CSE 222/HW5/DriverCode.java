import src.*;

public class DriverCode {
    public static void main(String[] args) {
        ArrayBST<Integer> myobject = new ArrayBST<Integer>();

        System.out.print("Tree: ");
        myobject.print();

        myobject.add(8);
        myobject.add(3);
        myobject.add(10);
        myobject.add(1);
        myobject.add(6);
        myobject.add(7);
        myobject.add(4);
        myobject.add(14);
        myobject.add(13);

        System.out.print("\nTree: ");
        myobject.print();

        System.out.println("\nTree has element of "+ myobject.find(10));
        System.out.println("Tree does not have -1: "+ myobject.find(-1));

        System.out.println("Is tree has -1: "+ myobject.contains(13));
        System.out.println("Is tree has 9: "+ myobject.contains(9));

        System.out.println("Deleting the element "+myobject.delete(1)+"...");
        System.out.println("Deleting the element "+myobject.delete(-1)+"...");
        System.out.println("Has element 7 been deleted from the tree: "+myobject.delete(7));
        System.out.println("Has element 9 been deleted from the tree: "+myobject.delete(9));

        System.out.print("Tree: ");
        myobject.print();
    }
}
