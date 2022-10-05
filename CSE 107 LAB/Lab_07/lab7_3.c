#include <stdio.h>

int main(){
 int number,i,j,count;
  printf("Enter a number:");
  scanf("%d",&number);
  if(number<=3)
    printf("There is not composite number");	
  else if(number>3){
	for(i=4 ; i<=number ; i++){
		for(count=2 ; count<i ; count++){
		if(i%count==0){
		printf("%d is a composite number\n",i);	
		break;
		}
	    else if(i%count!=0){
		}
	}
  } 	
}
	return 0;
}
