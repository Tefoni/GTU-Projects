#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
 
int main()
{
	
 int number,i,x,y,temp;
  x=0;
  y=1;
 printf("Please enter how many terms you would like to print: ");
 scanf("%d",&number);

 for(i=1;i<=number;i++)
 {
 printf("%d ",x);
 temp = x + y;
 x = y;
 y = temp;
 }
return 0;
} 
 
