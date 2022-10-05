#include <stdio.h>
#include <math.h>

void calculate_fibonacci_sequence();
int fibonacci_calculator(int number);

void decide_perfect_harmonic_number();

void difference_max_min();

void bmi_calculation();



int main(){

	calculate_fibonacci_sequence();
	printf("\n\n\n");

	decide_perfect_harmonic_number();
	printf("\n\n\n");

	difference_max_min();
	printf("\n\n\n");

	bmi_calculation();

}

void calculate_fibonacci_sequence(){
	int fibonacci,test,i,result;
	char word;


	printf("Please enter term(s) number :");
	test = scanf("%d",&fibonacci);
	word = getchar();                  /* These provide get first input */
	
	while(word != '*'){     /* Function continues until get input '*' */
			
		if(fibonacci >0 && test==1 && word=='\n'){
			printf("Fibonacci Sequence:\n");

			for(i=0;i<fibonacci;i++){
				result = fibonacci_calculator(i+1);     /* If input a positive numerical number,function get right outputs */   
				printf("%d\n",result);     
			}
			printf("Please enter term(s) number :");	
		}

		else if(test==0)
			printf("Please enter “numeric” term(s) number:");     /* If input a character,function says enter right input */

		else if(fibonacci<=0 && test==1 && word=='\n')
			printf("Please enter “positive” term(s) number:");     /* If input a negative number,function says enter right input */

		test = scanf("%d",&fibonacci); 
		word = getchar();                  /* These provide get input again and again until input '*' */
	}

}


int fibonacci_calculator(int number){
	int a=1,b=1,c;

	if(number==1)
		return a;
                      /* If input first two fibonacci numbers function returns constant number */
	if(number==2)
		return b;

	while(number-2 != 0){     /* An classical fibonacci formula without recursion.It continues until input goes 0 */
		c = a+b;
		a = b;
		b = c;
		number--;
	}
		return c;
}

void decide_perfect_harmonic_number(){
	int num,i,perfect_sum,divisor_counter;
	float harmonic_denominator,result;
	char word;
	

	printf("Please enter input number : ");
	scanf("%d",&num);
	word = getchar();                           /* Getting first number */

	while(word != '*'){
		perfect_sum=1,divisor_counter =1,harmonic_denominator =1; /* These are not 0 because i dont want divide  my number 1 .Because of line 95 printf output */

		printf("Natural Number Divisors: 1");     /* This provides last number does not have (,) */
		for(i=2;i<=num;i++){     /* I divide my number 2 to my number */
		
			if( (num%i)==0){
				printf(", %d",i);
				divisor_counter++;
				harmonic_denominator += (1.0/(float)i); /* I get what i want for perfect number and harmonic number, variable names are showing what are they */

				if(num!=i)
					perfect_sum += i;
			}
		}
		printf("\n");

		if(perfect_sum == num && perfect_sum != 1)
			printf("Is Perfect Number? : Yes\n");
                                                         /* Because of counters=1 function says 1 is perfect number.I want block it so that's happened */
		else if(perfect_sum != num || perfect_sum == 1)
			printf("Is Perfect Number? : No\n");

		result = (float)divisor_counter / (float)harmonic_denominator;


		if( fmod(result,1.0)<=0.000001 || fmod(result,1.0) > 0.99999)
			printf("Is Harmonic Divisor Number? : Yes\n");
                                                                     /* fmod results seem like 0 but they are not.They are so close 0  like 0.000001 */
		else if( fmod(result,1.0)!=0 )
			printf("Is Harmonic Divisor Number? : No\n");

		printf("Please enter input number : ");
		scanf("%d",&num);
		word = getchar();                       /* Get input until input is '*' character */
	}

}


void difference_max_min(){
	double max_num,min_num,num;
	int i;

	printf("Please enter 5 numbers: ");  
	scanf("%lf",&num);                      /* Getting inputs one by one with for loop */  
	max_num = num , min_num = num;

	for(i=1;i<5;i++){
		scanf("%lf",&num);

		if(num>max_num)
			max_num = num;     /* Comparing numbers with max_num and if there is bigger number,max_num changing */
		if(min_num>num)
			min_num = num;     /* Comparing numbers with min_num and if there is smaller number,min_num changing */

	}

	printf("Maximum number is: %.2f\n",max_num);
	printf("Minimum number is: %.2f\n",min_num);
	printf("Difference between maximum and minimum is %.2f\n",max_num - min_num);     /* Printing output results */
}

void bmi_calculation(){
    double weight,height,BMI;

    printf("Please enter weight(kg):");
    scanf("%lf",&weight);
    printf("Please enter height(m):");     /* Getting weight(kg) and height(m) inputs */
    scanf("%lf",&height); 
    BMI = weight/(height*height);     /* Calculating BMI */

    if(BMI < 16.0)
        printf("Your category: Severely Underweight");
    
    if(BMI < 18.5 && BMI >= 16.0)
         printf("Your category: Underweight");
    
    if(BMI < 25.0 && BMI >= 18.5)
         printf("Your category: Normal");
    
    if(BMI < 30.0 && BMI >= 25.0)
         printf("Your category: Overweight");

    if(BMI >= 30.0)
         printf("Your category: Obese");     /* Printing your category which suitable your BMI */
}