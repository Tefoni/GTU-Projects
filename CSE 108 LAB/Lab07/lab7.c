#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int check_palindrome(int a[], int n,int i);
int search_element(int arr[],int input_number,int count_size);

int main(){
	int a[50],n=-1,input=0,result1;
	int arr[20],input_number,i=0,result2;


	while(input!=-1){
		printf("Enter a number(-1 to finish):");     /* Filling array and count the how many number entered */  
		scanf("%d",&input);
		a[i]=input;
		i++;
		n++;
	}
	result1 = check_palindrome(a,n,0);
	if(result1==1)	printf("Your input is a palindrome\n\n");
	else if(result1==0)	printf("Your input is not a palindrome\n\n");     /* Calling the function and printing the result */


	for(i=0;i<20;i++){	
		arr[i]=rand()%101;     /* Filling the array between 0-100 */
	}
	input_number =8;

	result2 = search_element(arr,input_number,1);     /* Starting the recursive function and printing the result */
	if(result2==1)	printf("I found this number in array\n");
	else if(result2==0)	printf("I could not found this number in array\n");
}

int search_element(int arr[],int input_number,int count_size){
	if(count_size>20)	return 0;     /* Return 0 if the size of the array is exceeded */

	if(arr[0]==input_number){     /* If found input_number in array return 1 */
		printf("%d\n",arr[0]);
		return 1;
	}

	else if(arr[0]!=input_number){
		printf("%d\n",arr[0]);		
		count_size++;
		search_element(&arr[1],input_number,count_size);     /* If there is not input_number in this array element recursive the function and sent the next element of array */
	}
}

int check_palindrome(int a[], int n,int i){
	if(n==0)	return 1;	/* If function scans all element and didn't return 0,This array is palindrome so i return 1 */

	if(a[i]!=a[n-1]){
		return 0;	/* If rule is not provided return 0 */
	}
	else{
		i++;	
		check_palindrome(a,n-1,i);    /* Increase i for scanning first element and decrease n for scanning last element */
	}
}

