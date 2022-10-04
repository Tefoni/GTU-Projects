package src;

interface SearchTree<E> {
    /**
     * Adds the new element to tree
     * pre: The object to insert must implement the
     * Comparable interface.
     * 
     * @param item The object being inserted
     * @return true if the object is inserted, false if the object already exists in the tree
     */
    boolean add(E item);

    /**
     * Finds the target object in tree
     * 
     * @param target The Comparable object being sought
     * @return If found,true otherwise false
     */
    boolean contains(E target);

    /**
     * Finds the target object in tree
     * 
     * @param target The Comparable object being sought
     * @return If found,object otherwise null
     */
    E find(E target);

    /**
     * Deletes the target object from the tree
     * post: The object is not in the tree.
     * 
     * @param target The object to be deleted
     * @return The object deleted from the tree or null if the object was not in the tree
     * @throws ClassCastException if target does not implement Comparable
     */
    E delete(E target);

    /**
     * Deletes the target object from the tree
     * post: The object is not in the tree.
     * 
     * @param target The object to be deleted
     * @return If target deleted true otherwise false
     * @throws ClassCastException if target does not implement Comparable
     */
    boolean remove(E target);
}
