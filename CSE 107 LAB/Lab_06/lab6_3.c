#include<stdio.h>
#include <stdbool.h>
#include <conio.h>

int main()
{
 int i,number,count=0 ;

 printf("Enter a number: ");
 scanf("%d", &number);
 
 for(i=1 ; i<number ; i++)
  {
   if(number%i==0)
     count=count+i;
  }

 if (count==number)
 {
   printf("\n %d is a perfect number",number);}
   
 else
 {
   printf("\n %d is not a perfect number",number);}
    return 0;
}
