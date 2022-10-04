package src;

import java.util.AbstractList;

public class LDLinkedList<T> extends AbstractList<T> {
    private Node<T> head;
    private Node<T> lazyHead;

    private int lazySize;
    private int size;

    public LDLinkedList() {
        head = null;
        lazyHead = null;

        lazySize = 0;
        size = 0;
    }

    /**
     * Get the data at index
     * 
     * @param index The position of the data to return
     * @return The data at index
     * @throws IndexOutOfBoundsException if index is out of range
     */
    @Override
    public T get(int index) {
        if (index < 0 || index >= size())
            throw new IndexOutOfBoundsException(Integer.toString(index));

        Node<T> returningNode = getNode(index);

        return returningNode.building;
    }

    /**
     * Store a new data in the element at position index.
     * 
     * @param index       The position of the item to change
     * @param newBuilding The new building
     * @return The data previously at index
     * @throws IndexOutOfBoundsException if index is out of range
     */
    @Override
    public T set(int index, T newBuilding) {
        if (index < 0 || index >= size())
            throw new IndexOutOfBoundsException(Integer.toString(index));

        Node<T> settableNode = getNode(index);
        T oldValue = settableNode.building;
        settableNode.building = newBuilding;

        return oldValue;
    }

    /**
     * The size of linked list
     * 
     * @return The size of linked list
     */
    @Override
    public int size() {
        return size;
    }

    /**
     * Insert the specified item at index
     * 
     * @param index       The position where item is to be inserted
     * @param newBuilding The item to be inserted
     * @throws IndexOutOfBoundsException if index is out of range
     */
    @Override
    public void add(int index, T newBuilding) {
        if (index < 0 || index > size())
            throw new IndexOutOfBoundsException(Integer.toString(index));

        if (index == 0)
            addFirst(newBuilding);
        else {
            Node<T> addedNode = getNode(index - 1);
            addAfter(newBuilding, addedNode);
        }

    }

    /**
     * Remove the node at a given index
     * 
     * @param index The node position to be deleted
     * @return The data from the removed node, or null if there is no node to remove
     */
    @Override
    public T remove(int index) {
        if (index < 0 || index >= size())
            throw new IndexOutOfBoundsException(Integer.toString(index));

        T removedData;

        if (index == 0)
            removedData = removeFirst();

        else {
            Node<T> node = getNode(index - 1);
            removedData = removeAfter(node);
        }

        return removedData;
    }

    /**
     * Add an item to linked list as a first element
     * 
     * @param newBuilding The item to be added
     */
    private void addFirst(T newBuilding) {
        Node<T> temp = lazyHead;
        int flag = 0;

        for (int i = 0; i < lazySize - 1 && temp != null; i++) {
            if (temp.next.building.equals(newBuilding)) {
                Node<T> temp2 = temp.next; // Temp2 equals parameter newBuilding
                temp.next = temp2.next;
                temp2.next = head;
                lazySize--;
                flag++;
            }
            temp = temp.next;
        }
        // If LazyLinkedList has this building already inside,dont create new node
        // just get referance and put it on original linked list also protect lazyList

        if (flag == 0)
            head = new Node<>(newBuilding, head);
        size++;
    }

    /**
     * Add a node after a given node
     * 
     * @param referance   The node preceding the new item
     * @param newBuilding The item to insert
     */
    private void addAfter(T newBuilding, Node<T> referance) {

        Node<T> temp = lazyHead;
        int flag = 0;

        for (int i = 0; i < lazySize - 1 && temp != null; i++) {
            if (temp.next.building.equals(newBuilding)) {
                Node<T> temp2 = temp.next; // Temp2 equals parameter newBuilding
                temp.next = temp2.next;
                temp2.next = referance.next;
                referance.next = temp2;
                flag++;
                lazySize--;
            }
            temp = temp.next;
        }

        if (flag == 0)
            referance.next = new Node<T>(newBuilding, referance.next);

        size++;
    }

    /**
     * Remove the first node from the list
     * 
     * @return The removed node's data or null if the list is empty
     */
    private T removeFirst() {
        Node<T> temp = head;

        if (head != null) {
            head = head.next;

            temp.next = lazyHead; // Inserting removed node to LazyLinkedList as a first element
            lazyHead = temp;
            lazySize++;

            size--;
            return lazyHead.building;
        } else
            return null;

    }

    /**
     * Remove the node after a given node
     * 
     * @param referance The node before the one to be removed
     * @return The data from the removed node, or null if there is no node to remove
     * 
     */
    private T removeAfter(Node<T> referance) {
        Node<T> temp = referance.next;

        if (temp != null) {
            referance.next = temp.next;

            temp.next = lazyHead; // Inserting removed node to LazyLinkedList as a first element
            lazyHead = temp;
            lazySize++;

            size--;
            return lazyHead.building;
        } else
            return null;
    }

    /**
     * Get the data at index
     * 
     * @param index The position of the data to return
     * @return The data at index
     * @throws IndexOutOfBoundsException if index is out of range
     */
    private Node<T> getNode(int index) {
        if (index < 0 || index >= size())
            throw new IndexOutOfBoundsException(Integer.toString(index));

        Node<T> wantedNode = head;

        for (int i = 0; i < index && wantedNode != null; i++)
            wantedNode = wantedNode.next;

        return wantedNode;
    }

    // Node inner class is a node for a single linked list
    private static class Node<T> {
        private T building; // referance of data
        private Node<T> next; // referance of next node

        /**
         * Creates a new node with a null next node;
         *
         * @param Buildings The building stored
         */
        private Node(T Buildings) {
            building = Buildings;
            next = null;
        }

        /**
         * Creates a new node that referance the next node;
         *
         * @param Buildings The building stored
         * @param referance The next node referenced by new node
         */
        private Node(T Buildings, Node<T> referance) {
            building = Buildings;
            next = referance;
        }
    }
}
