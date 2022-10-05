#include <stdio.h>
#include <stdlib.h>
#define N 4
#define filename "games.txt"
struct Lobby{
	char name[15];
	char platforms[4][15];
	int platformCounter;	
};

 void write(struct Lobby*games,char platform);

int main(){
	int i,j;
	struct Lobby games[N];
	char platform[4][5];
	printf("Which platforms there are: ");
	for(i=0;i<4;i++)
		scanf("%s",&platform[i]);
	for(i=0;i<N;i++){
		jump:
		printf("%d. Game\nName: ",i+1);
		scanf("%s",games[i].name);
		printf("Platforms (enter '0' to stop):\n");
		for(j=0;j<4;j++){
			scanf("%s",games[i].platforms[j]);
			if(games[i].platforms[j][0]=='0')
				break;	
		}
	void write(struct Lobby*games,char platform);
	}	
}

 write(struct Lobby*games,char platform){
	FILE *fptr;
	fptr = fopen(filename,"w");
	if(fptr == NULL){
		printf("Couldn't open text file.\n");
		exit(1);
	}
	char select[1];
	int i,j;
	printf("Which platform games will be write:");
	scanf("%s",&select[0]);
	fprintf(fptr,"pc games:\n\n");
	for(i=0;i<N;i++){
		for(j=0;j<4;j++){
			if(strcmp(games[i].platforms[j],select)== 0){
				fprintf(fptr,"%s",games[i]);
			}
		}
	}
}

