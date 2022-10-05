#include <stdio.h>

int main(){
    int k,i,j; 
    printf("Dik Ucgenin kenar uzunlugunu giriniz:");	
	scanf("%d",&k);
	for(i=1 ; i<=k ; i++){
	    for(j=1 ; j<=i  ;j++){
	    	printf("*");
		}
		printf("\n");
	}
	return 0;	
}
