#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	double budget;
	int genre;
	char *name;
	double score;
	int year;
}Movie;
/*Hocam kolay gelsin ödev esnasında birçok segfault aldım ve compilerda nedenini söylemediğinden ödevden çok hatayı çözmesi vakit alıyordu ki yapamadım zaten.
  Ödevde yapmaya çalıştığım az olan kısmı anlatmaya çalıştım.İyi günler dilerim.*/

int getdatas_tostruct(FILE *fp,Movie *list,char *genres,int *genres_size);
int filling_struct(Movie *list,int list_size,char *genres,int *genres_size,char *budget,char *genre,char *name,char *score,char *year);
int line_count(FILE *fp);
int line_lenght_count(FILE*fp);


int main(){
	FILE *fp;
	Movie *list;
	int list_size,*genres_size=0,i;
	char *genres;

	fp = fopen("Movies.txt","r");
	if(fp==NULL){
		printf("File can not opened!\n");	/* Opening the file,If can not printing error message */
		exit(1);
	}
	list_size = getdatas_tostruct(fp,list,genres,genres_size);

}

int getdatas_tostruct(FILE *fp,Movie *list,char *genres,int *genres_size){
	int numof_lines,line_lenght,i,j,is_first_row=0,new_film=0,list_size=1;
	char *line;
	char *first=NULL,*second=NULL,*third=NULL,*fourth=NULL,*fiveth=NULL,*temp;
	char sequence[5][10];

	numof_lines = line_count(fp);

	for(i=0;i<numof_lines;i++){
		printf("(%d) ",i);

		line_lenght = line_lenght_count(fp);

		line = (char*)calloc(line_lenght+1,sizeof(char));	/* Allocate the memory for a line */
		fseek(fp,-line_lenght-1,SEEK_CUR);
		fgets(line,line_lenght+1,fp);
		fseek(fp,1,SEEK_CUR);

		if(first!=NULL || second!=NULL || third!=NULL || fourth!=NULL || fiveth!=NULL){		/* If it is not first row cleaning the memory */
		free(first);
		free(second);
		free(third);
		free(fourth);
		free(fiveth);
		is_first_row++;
		}

		if(first==NULL && second==NULL && third==NULL && fourth==NULL && fiveth==NULL){ 
		temp = strtok(line,",");
		first = (char*)calloc(strlen(temp)+1,sizeof(char));
		strcpy(first,temp);

		temp = strtok(NULL,",");
		second = (char*)calloc(strlen(temp)+1,sizeof(char));
		strcpy(second,temp);

		temp = strtok(NULL,",");
		third = (char*)calloc(strlen(temp)+1,sizeof(char));		/* If it is first row assiging the values to first,second,third... */
		strcpy(third,temp);

		temp = strtok(NULL,",");
		fourth = (char*)calloc(strlen(temp)+1,sizeof(char));
		strcpy(fourth,temp);

		temp = strtok(NULL,",");
		fiveth = (char*)calloc(strlen(temp)+1,sizeof(char));
		strcpy(fiveth,temp);
		}

		if(is_first_row==0){
			strcpy(sequence[0],first) , strcpy(sequence[1],second) , strcpy(sequence[2],third) , strcpy(sequence[3],fourth) , strcpy(sequence[4],fiveth);
			sequence[4][strlen(sequence[4])-1]='\0'; /* If it is first row creating headers array so if budget,genre,name,score,year change to example year,score,genre,name,budget
			program can know the sequence */
		}
		else {

			for(j=0;j<5;j++){
				if(j==0)	temp = strtok(line,",");
				else temp = strtok(NULL,",");


				if(strcmp(sequence[j],"budget")==0){
					first = (char*)calloc(strlen(temp)+1,sizeof(char));
					strcpy(first,temp);
				}
				else if(strcmp(sequence[j],"genre")==0){
					second = (char*)calloc(strlen(temp)+1,sizeof(char));
					strcpy(second,temp);
				}
				else if(strcmp(sequence[j],"name")==0){
					third = (char*)calloc(strlen(temp)+1,sizeof(char));		/* Reading values in correct order and assigning them into first,two,three ... */
					strcpy(third,temp);
				}
				else if(strcmp(sequence[j],"score")==0){
					fourth = (char*)calloc(strlen(temp)+1,sizeof(char));
					strcpy(fourth,temp);
				}
				else if(strcmp(sequence[j],"year")==0){
					fiveth = (char*)calloc(strlen(temp)+1,sizeof(char));
					strcpy(fiveth,temp);
				}


			}

			new_film=0;
			new_film = filling_struct(list,list_size,genres,genres_size,first,second,third,fourth,fiveth);

			if(new_film==1)list_size++;

		}

		

		free(line);
	}

	return list_size;
}

int line_count(FILE *fp){
	char line_count_c;
	int line_count=0;

	do{
		line_count_c=getc(fp);
		if(line_count_c=='\n')	line_count++;	/* Finding row numbers in file */

	}while(line_count_c!=EOF);

	fseek(fp,0,SEEK_SET);

	return line_count;
}

int line_lenght_count(FILE*fp){
	char line_count_c='x';
	int line_lenght_count=0;

	while(line_count_c!='\n'){
		line_count_c=getc(fp);
		if(line_count_c!='\n')	line_lenght_count++;	/* Finding how many characters in a row */
	}
	return line_lenght_count;
}

int filling_struct(Movie *list,int list_size,char *genres,int *genres_size,char *budget,char *genre,char *name,char *score,char *year){
	printf("%s %s %s %s %s\n",budget,genre,name,score,year); /* I couldn't the tasks wanting because i get so many segfault,I solved some of them but then bought them again :( */
	int i,genre_real,year_real;
	double budget_real,score_real;
	char *trash;
	Movie *list_cp=NULL;

	budget_real = strtod(budget,&trash);
	score_real = strtod(score,&trash);	/* Convert values strings to double or integer */
	year_real = strtod(year,&trash);

	list = (Movie*)calloc(list_size,sizeof(Movie));	/* When new film coming increase the struct size */ 

	//for(i=0;i<list_size-1;i++) list[i] = list_cp[i];

	list[list_size-1].budget = budget_real;
	list[list_size-1].score = score_real;	/* Assigning the values to struct */
	list[list_size-1].year = year_real;

	/*if(list_cp!=NULL)free(list_cp);

	list_cp = list;*/


	return 1;
}


