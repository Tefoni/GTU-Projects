#include <stdio.h>


int find_max_distance(int num_inputs);
void find_odd_average();

int main(){

	int distance_result,num,i,num_inputs=5;

	distance_result = find_max_distance(num_inputs);
	printf("Max dist between two consecutive nums: %d\n",distance_result);
                                                                               /* Calling function and getting results */
	find_odd_average();
}


int find_max_distance(int num_inputs){

	int i,num,temp,difference=0;

	printf("Please enter %d numbers:\n",num_inputs);
	printf("1 : ");
	scanf("%d",&num);     /* Getting first input */

	for(i=1 ; i<num_inputs ; i++){
		temp = num;
		printf("%d : ",i+1);
		scanf("%d",&num);     /* Getting second input and transfer the first input to temp */

		if(temp>num){
			if( (temp-num)>difference)
				difference = (temp-num);     
		}
                                             /* Calculating difference between first and second input */
		if(num>temp){
			if( (num-temp)>difference)
				difference = (num-temp);
		}
	}

	return difference;
}


void find_odd_average(){

	int i=2,num,sum=0,positive_odd_counter=0;
	double result;

	printf("Please enter positive numbers (end -1 to stop entering)\n");
	printf("1: ");
	scanf("%d",&num);     /* Get the first number */

	while(num != -1){    /* End the function when user print -1 */

		if(num>0 && (num%2)==1){
			sum += num;
			positive_odd_counter++;     /* If user print positive odd numbers store it's data */
		}
		printf("%d: ",i);
		scanf("%d",&num);
		i++;     /* Getting inputs again and again */
	}

	result= (double)sum/positive_odd_counter;
	printf("Average off odd numbers: %.2f",result);     /* Calculating average and printing result */
}


