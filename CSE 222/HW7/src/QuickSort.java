package src;

public class QuickSort<E extends Comparable<E>> {
    /**
     * Swap the values of the two elements in the array at the given indices
     * 
     * @param arr The array to be sorted.
     * @param i   the index of the first element to swap
     * @param j   the index of the first element in the subarray
     */
    public void swap(E[] arr, int i, int j) {
        E temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    /**
     * The partition function takes the last element as pivot, places the pivot
     * element at its correct
     * position in sorted array, and places all smaller (smaller than pivot) to left
     * of pivot and all
     * greater elements to right of pivot
     * 
     * @param arr  the array to be sorted
     * @param low  The lowest index of the array to be sorted.
     * @param high the last index of the array
     * @return The index of the pivot.
     */
    public int partition(E[] arr, int low, int high) {

        E pivot = arr[high];

        int i = (low - 1);

        for (int j = low; j <= high - 1; j++) {
            if (arr[j].compareTo(pivot) == -1) {
                i++;
                swap(arr, i, j);
            }
        }
        swap(arr, i + 1, high);
        return (i + 1);
    }

    /**
     * If the array has more than one element, partition the array into two
     * subarrays, sort each subarray,
     * and then merge the two sorted subarrays
     * 
     * @param arr  The array to be sorted
     * @param low  The lower index of the array
     * @param high the last index of the array
     */
    public void quickSort(E[] arr, int low, int high) {
        if (low < high) {

            int pi = partition(arr, low, high);

            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

    /**
     * It sorts the array in ascending order.
     * 
     * @param arr the array to be sorted
     */
    public void quickSort(E[] arr) {
        quickSort(arr, 0, arr.length - 1);
    }
}
