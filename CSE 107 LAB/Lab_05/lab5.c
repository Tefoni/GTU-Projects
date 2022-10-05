#include <stdio.h>
#include <stdbool.h>
#include <conio.h>

   int main() {
    float weight;
 	float height;
 	
   printf("What's your weight?'");
   scanf("%f",&weight);
   printf("Whats your height?");
   scanf("%f",&height);
   float bodyMass;
   bodyMass=weight/(height*height);
   printf("Your bodymass is %f",bodyMass );
   
   if (bodyMass<18.5){
   	printf("\nYour bodymass category is Underweight");
   }
   else if (bodyMass>18.5 && bodyMass<=24.9){
   	printf("\nYour bodymass category is Healthy Weight");
   }
   else if (bodyMass>24.9 && bodyMass<29.9){
   	printf("\nYour bodymass category is Overweight");
   }
   else if (bodyMass>30 && bodyMass<34.9){
   	printf("\nYour bodymass category is Obese(Class 1)");
   }
   else if (bodyMass>35 && bodyMass<39.9){
   	printf("\nYour bodymass category is Severely Obese(Class 2)");
   }
   else if (bodyMass>40 && bodyMass<49.9){
   	printf("\nYour bodymass category is Morbidly Obese(Class 3)");
   }
   else if (bodyMass>50){
   	printf("\nYour bodymass category is Super Obese(Class 4)");
   }
   	
	return 0;	
}

