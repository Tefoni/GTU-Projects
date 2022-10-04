package src;

public class ArrayBST<E extends Comparable<E>> implements SearchTree<E> {
    private E[] data;
    private int capacity;

    public ArrayBST() {
        capacity = 10;
        data = (E[]) new Comparable[capacity];
    }

    /**
     * Reallocate the array with x2 size
     * 
     */
    private void reallocate() {
        E[] temp = (E[]) new Comparable[capacity * 2];

        for (int i = 0; i < capacity; i++)
            temp[i] = data[i];

        capacity *= 2;
        data = temp;
    }

    /**
     * Adds the new element to tree
     * pre: The object to insert must implement the
     * Comparable interface.
     * 
     * @param item The object being inserted
     * @return true if the object is inserted, false if the object already exists in the tree
     */
    public boolean add(E item) {
        return add(item, 0);
    }

    /**
     * Adds the new element to tree
     * pre: The object to insert must implement the
     * Comparable interface.
     * 
     * @param item The object being inserted
     * @param index The location in the tree where the insertion can be made or not
     * @return true if the object is inserted, false if the object already exists in the tree
     */
    private boolean add(E item, int index) {
        if (index >= data.length) // If there is not enough space, reallocate the array
            reallocate();

        if (data[index] == null) { // Base case: ıt found the right location with recursively
            data[index] = item;
            return true;
        } else {
            if (item.compareTo(data[index]) < 0)
                return add(item, 2 * index + 1);
            else if (item.compareTo(data[index]) > 0)
                return add(item, 2 * index + 2);
            else
                return false; // Item already exists in tree

        }
    }

    /**
     * Finds the target object in tree
     * 
     * @param target The Comparable object being sought
     * @return If found,true otherwise false
     */
    public boolean contains(E target) {
        return contains(target, 0);
    }

    /**
     * Finds the target object in tree
     * 
     * @param target The Comparable object being sought
     * @param index  the location of the search location in the tree
     * @return If found,true otherwise false
     */
    private boolean contains(E target, int index) {
        if (data[index] == null) // If target is not in tree return false
            return false;

        if (target.compareTo(data[index]) < 0)
            return contains(target, 2 * index + 1);

        else if (target.compareTo(data[index]) > 0)
            return contains(target, 2 * index + 2);

        else
            return true; // Found the target element( target = data[index])

    }

    /**
     * Finds the target object in tree
     * 
     * @param target The Comparable object being sought
     * @return If found,object otherwise null
     */
    public E find(E target) {
        return find(target, 0);
    }

    /**
     * Finds the target object in tree
     * 
     * @param target The Comparable object being sought
     * @param index  the location of the search location in the tree
     * @return If found,object otherwise null
     */
    private E find(E target, int index) {
        if (data[index] == null) // If target is not in tree return null
            return null;

        if (target.compareTo(data[index]) < 0)
            return find(target, 2 * index + 1);

        else if (target.compareTo(data[index]) > 0)
            return find(target, 2 * index + 2);

        else
            return data[index]; // Found the target element( target = data[index])
    }

    /**
     * Deletes the target object from the tree
     * post: The object is not in the tree.
     * 
     * @param target The object to be deleted
     * @return The object deleted from the tree or null if the object was not in the tree
     * @throws ClassCastException if target does not implement Comparable
     */
    public E delete(E target) {
        return delete(target, 0);
    }

    /**
     * Deletes the target object from the tree
     * post: The object is not in the tree.
     * 
     * @param target The object to be deleted
     * @param index The location in the tree where the deleting can be made or not
     * @return The object deleted from the tree or null if the object was not in the tree
     * @throws ClassCastException if target does not implement Comparable
     */
    private E delete(E target, int index) {
        if (index >= data.length || data[index] == null) // If target is not in tree return null
            return null;

        if (target.compareTo(data[index]) < 0)
            return delete(target, 2 * index + 1);
        else if (target.compareTo(data[index]) > 0)
            return delete(target, 2 * index + 2);

        else { // If program goes here, it means data[index] = target
            if (2 * index + 2 >= capacity || (data[2 * index + 1] == null && data[2 * index + 2] == null)) {
                // If found location does not have children
                E temp = data[index];
                data[index] = null;
                return temp;
            } 
            else if (data[2 * index + 1] == null) // If found location has just right child
                data[index] = data[2 * index + 2];

            else if(data[2*index +2] == null) // If found location has just left child
                data[index] = data[2*index+ 1];

            return target;

        }
    }

    /**
     * Deletes the target object from the tree
     * post: The object is not in the tree.
     * 
     * @param target The object to be deleted
     * @return If the target deleted true otherwise false
     * @throws ClassCastException if target does not implement Comparable
     */
    public boolean remove(E target) {
        return remove(target, 0);
    }

    /**
     * Deletes the target object from the tree
     * post: The object is not in the tree.
     * 
     * @param target The object to be deleted
     * @param index The location in the tree where the deleting can be made or not
     * @return If the target deleted true otherwise false
     * @throws ClassCastException if target does not implement Comparable
     */
    private boolean remove(E target, int index) {
        if (index >= data.length || data[index] == null) // If target is not in tree return null
            return false;

        if (target.compareTo(data[index]) < 0)
            return remove(target, 2 * index + 1);
        else if (target.compareTo(data[index]) > 0)
            return remove(target, 2 * index + 2);

        else { // If program goes here, it means data[index] = target
            if (2 * index + 2 >= capacity || (data[2 * index + 1] == null && data[2 * index + 2] == null)) {
                data[index] = null;
                return true;
            } 
            else if (data[2 * index + 1] == null) // If found location has just right child
                data[index] = data[2 * index + 2];

            else if(data[2*index +2] == null) // If found location has just leftt child
                data[index] = data[2*index+ 1];

            return false;

        }
    }

    /**
     * Prints the tree in horizontal form
     */
    public void print() {
        for (int i = 0; i < data.length; i++) {
            if (data[i] != null)
                System.out.print(data[i]);
            else
                System.out.print("-");

            System.out.print(" ");
        }
    }
}
