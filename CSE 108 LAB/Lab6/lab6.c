#include <stdio.h>
#include <string.h>


void matrix_filler(int matrix1[][5],int matrix2[][9]);
void average_finder (int matrix1[][5],int matrix2[][9],double *result1,double *result2);


int main(){
	int matrix1[3][5],matrix2[4][9],i,j;
	double result1,result2;

	matrix_filler(matrix1,matrix2);
	average_finder(matrix1,matrix2,&result1,&result2); /* Calling first part functions */

	printf("Average Finder\n\n");
	printf("Matrix1:\n");
	for(i=0;i<3;i++){
		for(j=0;j<5;j++){
			printf("%-10d     ",matrix1[i][j]);
		}
		printf("\n");
	}
	printf("\nResult matrix1 = %f\n",result1);			/* Printing right output format */

	printf("Matrix2:\n");
	for(i=0;i<4;i++){
		for(j=0;j<9;j++){
			printf("%-10d     ",matrix2[i][j]);
		}
		printf("\n");
	}
	printf("\nResult matrix2 = %f",result2);

}

void matrix_filler(int matrix1[][5],int matrix2[][9]){
	int i,j,x=1;

	for(i=0;i<3;i++){
		for(j=0;j<5;j++){
			matrix1[i][j] = (2*x*x) -3;     /* Filling first matrix with right number */
			x++;
		}
	}
	x=1;

	for(i=0;i<4;i++){
		for(j=0;j<9;j++){
			matrix2[i][j] = 2*x*x -3;     /* Filling second matrix with right number */
			x++;
		}
	}

}	

void average_finder (int matrix1[][5],int matrix2[][9],double *result1,double *result2){
	int i,j,even_counter,sum=0,sum_counter=0;

	for(i=0;i<3;i++){
		for(j=0;j<5;j++){
			even_counter=i+j;
			if(even_counter%2==0){
				sum+= matrix1[i][j];     /* I process and average the elements that meet the requirement */
				sum_counter++;
			}
	
		}
	}
	*result1 = (double)sum/sum_counter;
	sum = 0 , sum_counter =0;

	for(i=0;i<4;i++){
		for(j=0;j<9;j++){
			even_counter= i+j;
			if(even_counter%2==0){
				sum+= matrix2[i][j];     /*I process and average the elements that meet the requirement*/
				sum_counter++;
			}
		}
	}
	*result2 = (double)sum/sum_counter;
}

