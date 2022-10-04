package src;

import java.util.ArrayList;

public class Recursions {
    /**
     * 
     * @param smallerString String to be found in BiggerString
     * @param biggerString A string with  or without smallstring
     * @param wantedOccurence The order of the smallstring whose index is requested
     * @return The index of requested occurrence smallstring in biggerstring or -1
     */
    public static int question1(String smallerString, String biggerString, int wantedOccurence) {
        if (smallerString.length() >= biggerString.length() || wantedOccurence<= 0) // If small string is not bigger than biggerString return abnormal value.
            return -1;

        return question1Detailed(smallerString, biggerString, wantedOccurence-1, 0); // Call helper method with extra parameters 
    }
    /**
     * 
     * @param smallerString String to be found in BiggerString
     * @param biggerString A string with  or without smallstring
     * @param wantedOccurence The order of the smallstring whose index is requested
     * @param searchingPosition  Means starting position which will be searched 
     * @return The index of requested occurrence smallstring in biggerstring or -1
     */
    private static int question1Detailed(String smallerString, String biggerString, int wantedOccurence,
            int searchingPosition) {

        int index = biggerString.indexOf(smallerString, searchingPosition); // Finding first occurrence smallstring in biggerstring
        if (index == -1) // If there is not smallstring in biggerstring return abnormal value
            return -1;

            
        if (wantedOccurence == 0)   // Base case: If first occurrence is wantedOccurrence return  index of beginning smallstring in biggerstring
            return index;
        else
            return question1Detailed(smallerString, biggerString, wantedOccurence-1, index + smallerString.length());
            // If wantedOccurrence is not first occurrence, find the other occurrence until reach wantedOccurrence
    }

    /**
     * 
     * @param sortedArray A sorted array which will be searched
     * @param lowerBound The lowerbound of elements which will be searched for
     * @param upperBound The upperbound of elements which will be searched for
     * @return The number of elements which will be inside the lowerbound and upperbound
     */
    public static int question2(int sortedArray[], int lowerBound, int upperBound) {
        if (lowerBound > upperBound) // If inputs are false, return -1
            return -1;

        else
            return question2Detailed(sortedArray, lowerBound, upperBound, 0, sortedArray.length - 1);
            // Call helper method with extra needed parameters(first,last)

    }
    /**
     * 
     * @param sortedArray A sorted array which will be searched
     * @param lowerBound The lowerbound of elements which will be searched for
     * @param upperBound The upperbound of elements which will be searched for
     * @param first The index to start for searching
     * @param last The index indicating the end of the search
     * @return The number of elements which will be inside the lowerbound and upperbound
     */
    private static int question2Detailed(int sortedArray[], int lowerBound, int upperBound, int first, int last) {
        if (first > last) // It is for unsuccessful search
            return 0;

        int middle = (first + last) / 2;

        if (sortedArray[middle] >= lowerBound && sortedArray[middle] <= upperBound) {
            // I include lower and upperbound to my output counter                                                    
            int found = 1;
            found += question2Detailed(sortedArray, lowerBound, upperBound, first, middle - 1); 
            // It found the element inside the bounds but need to look leftside and rightside for all elements which inside the bounds                                                                                                                                                                     
            found += question2Detailed(sortedArray, lowerBound, upperBound, middle + 1, last); 
                                                                                                                                                     
            return found;
        }

        else if (sortedArray[middle] < lowerBound)
            return question2Detailed(sortedArray, lowerBound, upperBound, middle + 1, last);
            // Element  smaller than we are looking for so search in rightside

        else
            return question2Detailed(sortedArray, lowerBound, upperBound, first, middle - 1);
            // Element bigger than we are looking for so search in rightside

    }
    /**
     * 
     * @param arr An array which will be found subarrys according to the targetSum
     * @param targetSum A value for the sum of the elements in subarrays
     * @return Indices of the first and last items of sub-array/s in main array
     */
    public static ArrayList<ArrayList<Integer>> question3(int arr[], int targetSum) {
        ArrayList<ArrayList<Integer>> result = new ArrayList<ArrayList<Integer>>();
        // Creating an arraylist for represent the output and calling helper method with needed parameters
        return question3Detailed(arr, targetSum, 0, 0, 0, result);
    }

    /**
     * 
     * @param arr An array which will be found subarrys according to the targetSum
     * @param targetSum A value for the sum of the elements in subarrays
     * @param tempSum The sum of the elements taken into account so far
     * @param startingPosition Starting position of the subarray
     * @param searchingPosition Position of element to be included in subarray
     * @param subArrays 2D Arraylist which include start-end indices of subarrays
     * @return
     */
    private static ArrayList<ArrayList<Integer>> question3Detailed(int arr[], int targetSum, int tempSum,
            int startingPosition,
            int searchingPosition,
            ArrayList<ArrayList<Integer>> subArrays) {

        if (searchingPosition >= arr.length) // If searching position equals array size it means finding subarray is finished
            return subArrays;

        tempSum += arr[searchingPosition];
        if (tempSum == targetSum) { // It means it found a subarray add it into subArrays and continue to finding new subarray
            ArrayList<Integer> subArraysElement = new ArrayList<>();
            subArraysElement.add(startingPosition);
            subArraysElement.add(searchingPosition);
            subArrays.add(subArraysElement);
            question3Detailed(arr, targetSum, 0, startingPosition + 1, startingPosition + 1, subArrays);

        } else if (tempSum < targetSum) // If it could not find subarray yet continue to finding subarray
            question3Detailed(arr, targetSum, tempSum, startingPosition, searchingPosition + 1, subArrays);

        else if (tempSum > targetSum) // It means it could not be a subarray because exceeded the sum,find a new subarray
            question3Detailed(arr, targetSum, 0, startingPosition + 1, startingPosition + 1, subArrays);

        return subArrays;
    }

}
