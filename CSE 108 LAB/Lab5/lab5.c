#include <stdio.h>
#include <stdlib.h>

void expression0 (int x, int *result);
void expression1 (int x, int *result);
void expression2 (int x, int *result);
void addition (void (*func)(int, int *), int *sum, int n);

void createArray(int (*array)[10]);


int main(){
	int sumArray[3],n,sum=0;
	int array[10][10],i,j;

	printf("n: ");
	scanf("%d",&n);

	addition (expression0,&sum,n);
	sumArray[0]= sum;
	sum = 0;

	addition (expression1,&sum,n);     /* Sending function adress,variable and getting result */
	sumArray[1]= sum;				   /* Assign the result in sumArray */
	sum = 0;

	addition (expression2,&sum,n);
	sumArray[2]= sum;

	for(i=0;i<3;i++){
		printf("Sum of expression%d: %d\n",i,sumArray[i]);     /* Printing the results */
	}
	
    /***************************************************************************************************************/
	createArray(array);     /* Sending array */
	printf("Matrix:\n\n");

	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			printf("%d ",array[i][j]);     /* Printing array */
		}
		printf("\n");
	}
	do{
	printf("\nWhich element of the matrix do you want to reach?\n");
	printf("i: ");
	scanf("%d",&i);                                                 /* Getting the desired row and column input */
	printf("j: ");
	scanf("%d",&j);

	if(i<10 && i>=0 && j<10 && j>=0)
		printf("%d. row %d. column of the matrix is %d\n",i,j,array[i][j]);     /* Printing the desired number */
	}while(i<10 && i>=0 && j<10 && j>=0);

	printf("Invalid input. Terminating...");
}

void addition (void (*func)(int, int *), int *sum, int n){
	int result,i;
	for(i=0;i<=n;i++){
	func(i,&result);
	*sum+= result;
	}

}
void expression0 (int x, int *result){
/* calculation of the expression0 for the value of x*/ 
	*result = x*x +5;
}
void expression1 (int x, int *result){
/* calculation of the expression1 for the value of x*/ 
	*result = 2*x +1;
}
void expression2 (int x, int *result){
/* calculation of the expression2 for the value of x*/ 
	*result = x*x;
}


void createArray(int (*array)[10]){     /*Getting array with adress */
	int i,j,rand_num;

	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			rand_num = (rand()%90)+10;     /* Filling array with random numbers */
			array[i][j]= rand_num;
		}
	}
}