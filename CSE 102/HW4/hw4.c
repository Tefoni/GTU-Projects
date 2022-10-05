#include <stdio.h>
#include <math.h>

void writing_polynom();

void armstrong_palindrome_numbers();
int armstrong(int num);
int palindrome(int num);

void sumof_prime();


int main(){
	
	writing_polynom();

	armstrong_palindrome_numbers();

	sumof_prime();
}

void writing_polynom(){
    int degree,i,j,copy_degree;
    double coefficient;
    
    printf("Enter your polynomial [n a_n a_n-1 a_n-2 ... a_0]: ");
    scanf("%d ",&degree);     /* Getting degree information */
    copy_degree = degree;
    printf("p(x) = ");
    /* All If/Else if/Else blocks below provide apply all conditions */

	for(j=0;j<=degree+1;j++){
        scanf("%lf",&coefficient);     /* Getting coefficients input until function get enough number */

        if(degree==1){     /* 35-44 If/Else if provides dont print x^1 and x^0*/
            if(coefficient==1 && j==0)
                printf("x ");
            else if(coefficient==-1 && j==0)
                printf("-x ");
            else if(coefficient==0 && j==0){}
            else if(coefficient!=0 && j==0)
                printf("%.1fx ",coefficient);  
        }                                         /* Printing greatest degree with coefficient */
        else if(degree!=0){
            if(coefficient==1 && j==0)
                printf("x^%d ",copy_degree);
            else if(coefficient==-1 && j==0)
                printf("-x^%d ",copy_degree);
            else if(coefficient==0 && j==0){}
            else if(j==0)
                printf("%.1fx^%d ",coefficient,copy_degree);
        }
        /******************************************/
      	if(copy_degree==1){     /* 54-64 If/Else provides dont print x^1 */
            	if(coefficient==1 && (j!=0) && (j!=degree))
                	printf("+x ");
            	else if(coefficient==-1 && j!=0 && j!=degree)
                	printf("-x ");
            	else if(coefficient>0 && (j!=0) && (j!=degree))
                	printf("+%.1fx ",coefficient);                     
            	else if(coefficient<0 && j!=0 && j!=degree)
                	printf("%.1fx ",coefficient);     			
      	}                                                           /* Printing degrees between the greatest and lowest degrees with their coefficients */ 
      	else{
            if(coefficient==1 && (j!=0) && (j!=degree))
                printf("+x^%d ",copy_degree);
            else if(coefficient==-1 && j!=0 && j!=degree)
                printf("-x^%d ",copy_degree);
            else if(coefficient>0 && (j!=0) && (j!=degree))
                printf("+%.1fx^%d ",coefficient,copy_degree);                    
            else if(coefficient<0 && j!=0 && j!=degree)
                printf("%.1fx^%d ",coefficient,copy_degree);
        }
        /******************************************/
        if(j==degree){
        	if(coefficient>0)
            	printf("+%.1f \n",coefficient);              
            else if(coefficient<0)                     /* Printing lowest degree with coefficient */
                printf("%.1f \n",coefficient);
        }                         
        /******************************************/
        copy_degree--;
        if(copy_degree==-1)
        	return;
    }
}

void armstrong_palindrome_numbers(){
	int num,result_armstrong,result_palindrome;
	
	do{
	printf("Please enter a non-negative integer number : ");
	scanf("%d",&num);
	if(num<0)
		printf("INVALID NUMBER\n");
	}while(num<0);
	
	result_armstrong = armstrong(num);
	result_palindrome = palindrome(num);

	if(result_armstrong==1 && result_palindrome==1)
		printf("Output > This number is both Palindrome and Armstrong number.\n");

	else if(result_armstrong==1 && result_palindrome==0)
		printf("Output > This number is only Armstrong number.\n");

	else if(result_armstrong==0 && result_palindrome==1)
		printf("Output > This number is only Palindrome number.\n");

	else if(result_armstrong==0 && result_palindrome==0)
		printf("Output > This number does not satisfy any special cases\n");
}

int armstrong(int num){
	int copy_num,sum=0,digit_value;

	copy_num = num;

	while(copy_num>0){
		digit_value = copy_num%10;
		sum += pow(digit_value,3);    /* Finding last digits value and calculate cubes */
		copy_num /= 10;
	}

	if(sum == num)     /* If Calculations equal to num, it is Armstrong number */
		return 1;
	else
		return 0;
}

int palindrome(int num){
	int digit=0,control_digit,left_digit,right_digit,copy_num,i;

	copy_num = num;

	if(num==0)     /* 0 is Palindrome number */
		return 1;

	while(copy_num!=0){     /* Calculating the number of digits of number */
		copy_num /=10;
		digit++;
	}
	
	control_digit = (digit/2)+1;     /* Middle digit of number */

	for(i=0; i<control_digit ;i++){
		right_digit = (fmod(num,pow(10,i+1)))/pow(10,i);     /* Calculating right to left digit of value */
		left_digit = (fmod(num,pow(10,digit)))/pow(10,digit-1);     /* Calculating left to right digit of value */

		if(left_digit != right_digit)     /* If left and right digit value is not equal each other, It is not a Palindrome number */
			return 0;
	
		digit--;
	}
	return 1;
}

void sumof_prime(){
	int num1,num2,big_num,small_num;
	int result=0,counter=0,temp,i;

	do{
		printf("Please enter first integer number : ");
		scanf("%d",&num1);
		printf("Please enter second integer number : ");     /* Getting inputs */
		scanf("%d",&num2);

		if(num1 > num2)
			big_num = num1 , small_num = num2;
		else if(num2 > num1)
			big_num = num2 , small_num = num1;
		else
			big_num = num1 , small_num = num1;     /* Calculating big and small nums */
	
		temp = small_num;
		small_num++;     /* small_num++ because we shouldn't include small_num in calculation */
		for(; small_num<big_num ; small_num++){
			for(i=2;i<small_num;i++){
				if(small_num%i == 0)
					counter++;     /* Counter means, does number has divisor */
				}
			if(counter==0 && small_num > 0 && small_num != 1) /* If number /hasn't divisor / positive / isn't equal to 1 ---> it is prime */ 
				result += small_num; 

			counter = 0;
		}
		if(result==0)
			printf("INVALID INPUT\nPlease enter one or two positive integer.\n");	
	}while(result==0);	
	printf("Output > Sum of prime numbers between %d and %d : %d",temp,big_num,result);
}