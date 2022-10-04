package src;
import java.io.*;
import java.util.Queue;
import java.util.LinkedList;

/**
 * Class for a binary tree that stores type E objects
 *
 * @param <E> The type of data to be stored
 */
public class BinaryTree<E extends Comparable<E> > {
  protected Node<E> root;
  private int inputArraySize; // This is for convertBinarySearchTree method

  public BinaryTree() {
    root = null;
    inputArraySize = 0;
  }

  protected BinaryTree(Node<E> root) {
    this.root = root;
    inputArraySize = 0;
  }

  public BinaryTree(E data, BinaryTree<E> leftTree, BinaryTree<E> rightTree) {
    root = new Node<E>(data);
    if (leftTree != null)
      root.left = leftTree.root;
    else
      root.left = null;

    if (rightTree != null)
      root.right = rightTree.root;
    else
      root.right = null;
  }

  /**
   * Return the left subtree
   * 
   * @return The left subtree or null if either the root or the left subtree is
   *         null
   */
  public BinaryTree<E> getLeftSubtree() {
    if (root != null && root.left != null) {
      return new BinaryTree<E>(root.left);
    } else {
      return new BinaryTree<E>(null);
    }
  }

  /**
   * Return the right subtree
   * 
   * @return The right subtree or null if either the root or the right subtree is
   *         null
   */
  public BinaryTree<E> getRightSubtree() {
    if (root != null && root.right != null) {
      return new BinaryTree<E>(root.right);
    } else {
      return new BinaryTree<E>(null);
    }
  }

  /**
   * Determine whether this tree is a leaf
   * 
   * @return true if the root has no children
   */
  public boolean isLeaf() {
    return root == null || (root.left == null && root.right == null);
  }

  public String toString() {
    StringBuilder sb = new StringBuilder();
    preOrderTraverse(root, 1, sb);
    return sb.toString();
  }

  /**
   * Inserts element into the binary tree
   * 
   * @param item An element to be inserted binary tree
   */
  public void insert(E item) {
    if (root == null) {
      root = new Node<E>(item);
      return;
    }
    Node<E> temp = root;
    Queue<Node<E>> queue = new LinkedList<Node<E>>();
    queue.add(temp);

    // Do level order traversal until we find
    // an empty place.
    while (!queue.isEmpty()) {
      temp = queue.peek();
      queue.remove();

      if (temp.left == null) {
          temp.left = new Node<E>(item);
          break;
      }
      else
          queue.add(temp.left);

      if (temp.right == null) {
          temp.right = new Node<E>(item);
          break;
      }
      else
          queue.add(temp.right);
    }
  }

/**
 * It converts a binary tree to a binary search tree with using elements of array
 * 
 * @param array The array that contains the elements to be inserted into the tree.
 * @return A tree in binary search tree format
 */
  public BinaryTree<E> convertBinarySearchTree(E[] array) {
    inputArraySize = array.length;
    convertBinarySearchTreeRecursion(root,array);

    return this;
  }

/**
 * It converts a binary tree to a binary search tree with using elements of array
 * 
 * @param current The current node that we are at.
 * @param array The array that contains the elements to be inserted into the tree.
 */
  private void convertBinarySearchTreeRecursion(Node<E> current, E[] array) { 
    if(current == null)
      return;


    convertBinarySearchTreeRecursion(current.right, array);
    current.setData(array[--inputArraySize]);
    convertBinarySearchTreeRecursion(current.left,array);
  }

  /**
   * Perform a preorder traversal
   * 
   * @param node  The local root
   * @param depth The depth
   * @param sb    The string buffer to save the output
   */
  private void preOrderTraverse(Node<E> node, int depth, StringBuilder sb) {
    for (int i = 1; i < depth; i++) {
      sb.append("  ");
    }
    if (node == null) {
      sb.append("null\n");
    } else {
      sb.append(node.toString());
      sb.append("\n");
      preOrderTraverse(node.left, depth + 1, sb);
      preOrderTraverse(node.right, depth + 1, sb);
    }
  }

  public String oneLinePreorder() {
    StringBuilder sb = new StringBuilder();
    preOrderTraverseOneLine(root, sb);
    return sb.toString();
  }

  /**
   * Perform a preorder traversal, returning the tree as one line
   * 
   * @param node The local root
   * @param sb   The string bufer to save the output
   */
  private void preOrderTraverseOneLine(Node<E> node, StringBuilder sb) {
    if (node == null) {
      // do nothing
    } else {
      sb.append(node.toString());
      sb.append(" ");
      preOrderTraverseOneLine(node.left, sb);
      preOrderTraverseOneLine(node.right, sb);
    }
  }

  public String oneLinePostorder() {
    StringBuilder sb = new StringBuilder();
    postOrderTraverse(root, sb);
    return sb.toString();
  }

  /**
   * Perform a postorder traversal, returning the tree as one line
   * 
   * @param node The local root
   * @param sb   The string bufer to save the output
   */
  private void postOrderTraverse(Node<E> node, StringBuilder sb) {
    if (node == null) {
      // do nothing
    } else {
      preOrderTraverseOneLine(node.left, sb);
      preOrderTraverseOneLine(node.right, sb);
      sb.append(node.toString());
      sb.append(" ");
    }
  }

  public String oneLineInorder() {
    StringBuilder sb = new StringBuilder();
    inOrderTraverse(root, sb);
    return sb.toString();
  }

  /**
   * Perform an inorder traversal, returning the tree as one line (with
   * parentheses)
   * 
   * @param node The local root
   * @param sb   The string bufer to save the output
   */
  private void inOrderTraverse(Node<E> node, StringBuilder sb) {
    if (node == null) {
      // do nothing
    } else {
      sb.append("(");
      inOrderTraverse(node.left, sb);
      sb.append(" ");
      sb.append(node.toString());
      sb.append(" ");
      inOrderTraverse(node.right, sb);
      sb.append(")");
    }
  }

  protected static class Node<E extends Comparable<E> > implements Serializable {

    public E data;
    public Node<E> left;
    public Node<E> right;

    public Node(E data) {
      this.data = data;
      left = null;
      right = null;
    }

    public String toString() {
      return data.toString();
    }

    public void setData(E item) {
      data = item;
    }

    public E getData() {
      return data;
    }
  }
}
