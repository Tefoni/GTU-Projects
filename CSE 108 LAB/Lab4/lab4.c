#include <stdio.h>

void russian_multiplication(unsigned int* multiplicand, unsigned int* multiplier);
void multiply_polynomials (double* a3, double* a2, double* a1, double* a0, double* b3,double* b2, double* b1, double b0);


int main(){
	double a3,a2,a1,a0;
	double b3,b2,b1,b0;
	unsigned int multiplicand,multiplier;

	printf("Enter the multiplicand and multiplier(multiplicand multiplier):");     /* Getting first function inputs */
	scanf("%u %u",&multiplicand,&multiplier);

	russian_multiplication(&multiplicand,&multiplier);
	printf("Result of multiplication=%u\n",multiplicand);     /* Getting result in function and printing the result */
	printf("Multiplier =%u\n",multiplier);

	printf("Enter the coefficients of the first polynomial(3 5 7 9...):");
	scanf("%lf %lf %lf %lf",&a3,&a2,&a1,&a0);
	printf("Enter the coefficients of the second polynomial(3 5 7 9...):");     /* Getting second function coefficient inputs */
	scanf("%lf %lf %lf %lf",&b3,&b2,&b1,&b0);

	multiply_polynomials(&a3,&a2,&a1,&a0,&b3,&b2,&b1,b0);
	printf("%.1fx^6 %.1fx^5 %.1fx^4 %.1fx^3 %.1fx^2 %.1fx^1 %.1f",a3,a2,a1,a0,b3,b2,b1);     /* Getting result in function and printing the result */
}

void russian_multiplication (unsigned int* multiplicand, unsigned int* multiplier){
	unsigned int sum=0;

	while(*multiplier!=1){
		if( (*multiplier%2)==1){
			sum += *multiplicand;     /* Doing the Russian Peasant Multiplication Algorithm */
		}
		
		*multiplicand *= 2;
		*multiplier /= 2;

	}

	if(*multiplier==1)
		sum += *multiplicand;

	*multiplicand = sum;


}

void multiply_polynomials (double* a3, double* a2, double* a1, double* a0, double* b3,double* b2, double* b1, double b0){
	double k6=0,k5=0,k4=0,k3=0,k2=0,k1=0,k0=0;

	k6 += *a3 * *b3;
	k5 += (*a3 * *b2) + (*a2 * *b3);
	k4 += (*a3 * *b1) + (*a2 * *b2) + (*a1 * *b3); 
	k3 += (*a3 *  b0) + (*a2 * *b1) + (*a1 * *b2) + (*a0 * *b3);
	k2 += (*a2 *  b0) + (*a1 * *b1) + (*a0 * *b2);     /* Multiplication stages */
	k1 += (*a1 *  b0) + (*a0 * *b1);
	k0 += (*a0 *  b0);

	*a3 = k6;
	*a2 = k5;
	*a1 = k4;
	*a0 = k3;     /* Assigning results to pointers */
	*b3 = k2;
	*b2 = k1;
	*b1 = k0;
}
