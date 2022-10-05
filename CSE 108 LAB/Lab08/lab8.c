#include <stdio.h>


typedef struct{
	double array[3][3];
	double determinant;
}matrix;

typedef struct{
	double coefficient3;
	double coefficient2;
	double coefficient1;
	double coefficient0;
}third_order_polynomial;

typedef struct{
	double coefficient6;
	double coefficient5;
	double coefficient4;
	double coefficient3;
	double coefficient2;
	double coefficient1;
	double coefficient0;
	double integral;
}polynomial;


void print_matrix(matrix initial_matrix);
void determinant_of_matrix(matrix* initial_matrix);
void inverse_matrix(matrix* initial_matrix, matrix* inverted_matrix);
polynomial get_integral(third_order_polynomial p1, third_order_polynomial p2, int a, int b);


int main(){
	int i,j,a,b;
	double temp;
	matrix initial_matrix,inverted_matrix;
	third_order_polynomial p1,p2;
	polynomial x;


	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("Enter the %d. row ,%d.column element:",i+1,j+1); /* Filling 3x3 matrix with user input */
			scanf("%lf",&temp);
			initial_matrix.array[i][j] = temp;
		}
	}

	print_matrix(initial_matrix);
	inverse_matrix(&initial_matrix,&inverted_matrix); /* Calling function */

	/*************************************** Part 3 ************************************/
	for(i=0;i<2;i++){
		for(j=3;j>=0;--j){
			printf("Enter %d. third degree polynomial coefficient x^%d :",i+1,j);
			scanf("%lf",&temp);
			if(i==0){
				if(j==3)	p1.coefficient3 = temp;
				else if(j==2)	p1.coefficient2 = temp;
				else if(j==1)	p1.coefficient1 = temp;
				else if(j==0)	p1.coefficient0 = temp;
			}
			else if(i==1){									/* Getting third degree polynoms coefficient inputs */
				if(j==3)	p1.coefficient3 = temp;
				else if(j==2)	p1.coefficient2 = temp;
				else if(j==1)	p1.coefficient1 = temp;
				else if(j==0)	p1.coefficient0 = temp;				
			}
		}
	}
	printf("Enter [a,b] interval like a b :");		/* Getting interval inputs */
	scanf("%d %d",&a,&b);

	x = get_integral(p1,p2,a,b);

	printf("%f %f %f %f %f %f %f",x.coefficient6,x.coefficient5,x.coefficient4,x.coefficient3,x.coefficient2,x.coefficient1,x.coefficient0);



}

void print_matrix(matrix initial_matrix){
	int i,j;

	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("%.4f    ",initial_matrix.array[i][j]);     /* Printing the right format of 3x3 matrix */
		}
		printf("\n");
	}

	printf("The determinant is %f",initial_matrix.determinant);
	printf("\n\n");
}

void determinant_of_matrix(matrix* initial_matrix){
	int i,j;
	float part1,part2,part3;

	part1 = initial_matrix->array[0][0]*(initial_matrix->array[1][1]*initial_matrix->array[2][2] - initial_matrix->array[2][1]*initial_matrix->array[1][2]);
	part2 = initial_matrix->array[0][1]*(initial_matrix->array[1][0]*initial_matrix->array[2][2] - initial_matrix->array[1][2]*initial_matrix->array[2][0]);
	part3 = initial_matrix->array[0][2]*(initial_matrix->array[1][0]*initial_matrix->array[2][1] - initial_matrix->array[1][1]*initial_matrix->array[2][0]); /* Doing determinant finding process */

	initial_matrix->determinant = part1 - part2 + part3; /* Assigning the determinant with values */
}

void inverse_matrix(matrix* initial_matrix, matrix* inverted_matrix){
	determinant_of_matrix(initial_matrix);

	if(initial_matrix->determinant==0){ /* Normally in there, doing inverse matrix :( */

	}
	else	printf("Matrix is not invertible\n");
}

polynomial get_integral(third_order_polynomial p1, third_order_polynomial p2, int a, int b){
	polynomial output;

	output.coefficient6 = p1.coefficient3 * p2.coefficient3;
	output.coefficient5 = (p1.coefficient3 * p2.coefficient2) +(p1.coefficient2* p2.coefficient3);
	output.coefficient4 = (p1.coefficient3 * p2.coefficient1) +(p1.coefficient2 *p2.coefficient2) +(p1.coefficient1*p2.coefficient3);
	output.coefficient3 = (p1.coefficient3*p2.coefficient0) +(p1.coefficient2 * p2.coefficient1) + (p1.coefficient1 * p2.coefficient2) + (p1.coefficient0*p2.coefficient3);
	output.coefficient2 = (p1.coefficient2 * p2.coefficient0) + (p1.coefficient1*p2.coefficient1) + (p1.coefficient0*p2.coefficient2);
	output.coefficient1 = (p1.coefficient1 * p2.coefficient0) + (p1.coefficient0 * p2.coefficient1);
	output.coefficient0 = p1.coefficient0 * p2.coefficient0;			/* Doing polynom multiplication process */

	return output;
}