#include <stdio.h>
#include <string.h>
void reverse_string(char str[]);

int main(){
	char str_arr[100];
	printf("Enter a string:");
	scanf("%s",str_arr);
	reverse_string(str_arr);
	printf("Reversed string is: %s \n",str_arr);
	return 0;	
}

void reverse_string(char str[]){
	char rev[100];
	int i,k;
	k=strlen(str);
	for(i=0;i<100;i++){
		if(k>=1){
		rev[k-1]=str[i];
		k--;}
	}
	for(i=0;i<100;i++)
		str[i]=rev[i];
	
}


