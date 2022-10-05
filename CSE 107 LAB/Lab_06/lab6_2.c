#include<stdio.h>
#include<stdlib.h>

int main()
{
  int i,j,h;
  printf("Piramitin yuksekligini giriniz:");
  scanf("%d",&h);
  for(i=1;i<=h;i++){
  	for(j=1;j<=h;j++)
  	printf(" ");
  	   for(j=1;j<=(2*i)-1;j++)
  	        printf("*");
  	        
  	printf("\n");        
  }
  return 0;
}
