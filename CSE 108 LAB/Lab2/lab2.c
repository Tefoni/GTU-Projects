#include <stdio.h>
#include <math.h>


void Standart_calculator();
void Temperature_calculator();

int addition_calculator(int num1,int num2);
int multiplication_calculator(int num1,int num2);
int addition_complex_calculator(int num1,int num2,int num1_complex,int num2_complex);
int multiplication_complex_calculator(int num1,int num2,int num1_complex,int num2_complex);

float fahrenheit_calculator();
float kelvin_calculator();




/* I couldn't the Area&Perimeter Calculator :( */

int main(){
	int choice;

	printf("Enter the calculator type\n");
	printf(" 1. Standart Calculator\n");
	printf(" 2. Area&Perimeter Calculator\n");
	printf(" 3. Temperature Calculator\n");
	printf(" -------------------------\n");     
	scanf("%d",&choice);

	if(choice==1)
		Standart_calculator();
                                     /* Choice the First Menu */
	if(choice==3)
		Temperature_calculator(); 
}

void Standart_calculator(){

	int choice_2;
	int choice_3;
	int num1,num2;
	int num1_complex,num2_complex;
	int result_integer;


	printf("Enter the number type\n");
	printf(" 1. Integer\n");
	printf(" 2. Complex\n");
	printf(" ---------------------\n");
	scanf("%d",&choice_2);

	printf("Enter the calculation type\n");
	printf(" 1. Addition\n");
	printf(" 2. Multiplication\n");
	printf(" --------------------------\n");     /* Choice the Second Menu */
	scanf("%d",&choice_3);

	if(choice_2==1){
		printf("Please enter the first Integer number:\n");
		scanf("%d",&num1);
		printf("Please enter the second Integer number:\n");     /* Getting Input values */
		scanf("%d",&num2);

		if(choice_3==1){
			result_integer = addition_calculator(num1,num2);
			printf("Addition of numbers = %d",result_integer);}

		if(choice_3==2){
			result_integer = multiplication_calculator(num1,num2);
			printf("Multiplication of numbers = %d",result_integer); }     /* Values go to the calculators and get output */
		}

	if(choice_2==2){
		printf("Please enter the first complex number (real part first)\n");
		scanf("%d",&num1);
		scanf("%d",&num1_complex);
		printf("Please enter the second complex number (real part first)\n");
		scanf("%d",&num2);
		scanf("%d",&num2_complex);

		if(choice_3==1)
			addition_complex_calculator(num1,num2,num1_complex,num2_complex);
                                                                                        /* Values go to the calculators and get output */
		if(choice_3==2)
			multiplication_complex_calculator(num1,num2,num1_complex,num2_complex);
		}

	}

void Temperature_calculator(){
	int choice_2;
	double resultof_temperature;
	double temperature;

	printf("Enter the calculation type\n");
	printf(" 1. Fahrenheit to Kelvin\n");
	printf(" 2. Kelvin to Fahrenheit\n");
	printf(" --------------------------\n");     /* Choice the Second Menu */
	scanf("%d",&choice_2);

	if(choice_2==1)
		resultof_temperature = kelvin_calculator();

	if(choice_2==2)
		resultof_temperature = fahrenheit_calculator();

	printf("Result = %f",resultof_temperature);     /* Values go to the calculators and get output */

}	


int addition_calculator(int num1,int num2){
	return num1+num2;
}

int multiplication_calculator(int num1,int num2){
	return num1*num2;
}

int addition_complex_calculator(int num1,int num2,int num1_complex,int num2_complex){
	int real_part;
	int complex_part;

	real_part = num1+num2;
	complex_part = num1_complex+num2_complex;

	printf("Addition of numbers = %d +(%di)",real_part,complex_part);
}

int multiplication_complex_calculator(int num1,int num2,int num1_complex,int num2_complex){
	int real_part;
	int complex_part;

	real_part = num1*num2;
	complex_part = num1_complex*num2_complex;

	printf("Multiplication of numbers = %d +(%di)",real_part,complex_part);
}



float fahrenheit_calculator(){
	float kelvin;
	float fahrenheit;

	printf("Please enter the temperature in Kelvin:\n");
	scanf("%f",&kelvin);

	fahrenheit = (1.8 * (kelvin - 273.15)) +32;

	return fahrenheit;
}

float kelvin_calculator(){
	float kelvin;
	float fahrenheit;

	printf("Please enter the temperature in Fahrenheit:\n");
	scanf("%f",&fahrenheit);

	kelvin = ( ((0.555555)*(fahrenheit-32))+ 273.15);

	return kelvin;
}



