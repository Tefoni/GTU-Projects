#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	srand(time(NULL));
	int i,j,r;
	int my2DArray[10][10];
	int mysumArray[10];
	int sum;
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
		
			r=rand()%80 +20;
			my2DArray[i][j]=r;	
			
		}	
	}
	for(i=0;i<10;i++){
		mysumArray[i]=0;
		for(j=0;j<10;j++){
			printf("%d",my2DArray[i][j]);
			printf("  ");
				mysumArray[i]+=my2DArray[i][j];			
			}
				printf(" %d ",mysumArray);
			printf("\n");
		}
		
	printf("\n");

}
