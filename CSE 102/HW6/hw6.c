#include <stdio.h>
#include <stdlib.h>

#define N 2

void move_up(int puzzle[][N],int k,int l);
void move_down(int puzzle[][N],int k,int l);
void move_left(int puzzle[][N],int k,int l);
void move_right(int puzzle[][N],int k,int l);
void printing_puzzle(int puzzle[][N]);
int checking_puzzle(int puzzle[][N]);

enum operation{left,right,up,down,give_up};


int main(){
	int puzzle[N][N],result_puzzle[N][N],i,j,c,d,a=0,temp,k,l,seed,finish=-1;
	enum operation towards;

	srand((unsigned long)&seed);     /* Get a random seed with using memory */

	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			puzzle[i][j]=a;     /* Creating an N*N puzzle array with 0 to N-1 number */
			a++;
		}
	}

    for(i=0;i<N;i++){
    	for(j=0;j<N;j++){
    		c = rand()%N;
    		d = rand()%N;
    		temp = puzzle[i][j];
    		puzzle[i][j]= puzzle[c][d];     /* Shuffling and randomize our puzzle array so we get random puzzle */
    		puzzle[c][d] = temp;
    	}
    }

    printing_puzzle(puzzle);     /* Printing the current puzzle */

    do{
    	printf("\nMovements --> ( left:0,right:1,up:2,down:3,for give_up the game:4 ) :");
		scanf("%u",&towards);

		if(towards!=give_up && finish!=1){												/* Direct the user for process */
			printf("\nMovement start location(Example: dimension1 dimension2) --> : "); 
			scanf("%d %d",&k,&l);	
		}			/*and get movement and location input if user does not give up or does not finished the puzzle */

		switch(towards)
    	{
    		case left:
    			move_left(puzzle,k,l);
    			break; 

    		case right:
    			move_right(puzzle,k,l);     /* Doing the required  movement process */
    			break;

    		case up:
    			move_up(puzzle,k,l);
    			break;

    		case down:
    			move_down(puzzle,k,l);
    			break;
    	}
    	printing_puzzle(puzzle);     /* Printing the current puzzle */    	

    	finish = checking_puzzle(puzzle); /* Checking if the current puzzle is the correct solution(1 means finished,-1 means not finished) */

    }while(towards!=give_up && finish!=1);     /* Doing movement process until game finished or user gives up */


    if(towards==give_up)	printf("\nYou gave up and failed :( ");
    if(finish==1)	printf("\nYou succeeded,Congratulations :) ");     /* Printing the right result message */
   
}

void move_up(int puzzle[][N],int k,int l){
	int i,a,temp;

	for(i=k;i>=0;i--){
		if(puzzle[i][l]==0){
			for(a=i;a<k;a++){
				temp = puzzle[a][l];
				puzzle[a][l] = puzzle[a+1][l];     /* Doing up movement by shuffling elements */
				puzzle[a+1][l] = temp;
			}
		}
	}
}

void move_down(int puzzle[][N],int k,int l){
	int i,a,temp;

	for(i=k; i<=N-1 ;i++){
		if(puzzle[i][l]==0){
			for(a=i;a>k;a--){
				temp = puzzle[a][l];
				puzzle[a][l] = puzzle[a-1][l];     /* Doing down movement by shuffling elements */
				puzzle[a-1][l] = temp;
			}
		}
	}
}

void move_left(int puzzle[][N],int k,int l){
	int j,a,temp;

	for(j=l;j>=0;j--){
		if(puzzle[k][j]==0){
			for(a=j;a<l;a++){
				temp = puzzle[k][a];
				puzzle[k][a] = puzzle[k][a+1];     /* Doing left movement by shuffling elements */
				puzzle[k][a+1] = temp;
			}
		}
	}
}

void move_right(int puzzle[][N],int k,int l){
	int j,a,temp;

	for(j=l; j<=N-1 ;j++){
		if(puzzle[k][j]==0){
			for(a=j;a>l;a--){
				temp = puzzle[k][a];
				puzzle[k][a] = puzzle[k][a-1];     /* Doing right movement by shuffling elements */
				puzzle[k][a-1] = temp;
			}
		}
	}
}

void printing_puzzle(int puzzle[][N]){
	int i,j,a;

	printf("       ");
	for(i=0;i<N;i++){
		printf("(%d)   ",i);
	}
	printf("\n     ");

	for(i=0; i<(N*3)+1;i++){
		printf("* ");
	}

	for(i=0;i<N;i++){
		if(i==9)		printf("\n(%d) *",i);     /* Printing the right format of current puzzle */
		else if(i<9)	printf("\n(%d)  *",i);
		for(j=0;j<N;j++){
			if(puzzle[i][j]>=10)	printf(" %3d *",puzzle[i][j]);
			else if(puzzle[i][j]==0)	printf("     *");
			else if(puzzle[i][j]>0)	printf("  %d  *",puzzle[i][j]);
		}
		printf("\n     ");
		for(a=0; a<(N*3)+1;a++){
			printf("* ");
		}
	}
}

int checking_puzzle(int puzzle[][N]){
	int i,j,a=1,result_puzzle[N][N],counter=0;

	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(a==(N*N)) result_puzzle[i][j]=0;

			else{
				result_puzzle[i][j]=a;     /* Creating the correct solution to the puzzle */
				a++;
			}	
		}
	}

	for(i=0;i<N;i++){
    	for(j=0;j<N;j++)
    		if(puzzle[i][j] != result_puzzle[i][j]) counter++;	
    	}

    if(counter==0) return 1;
    else	return -1;
}
	

