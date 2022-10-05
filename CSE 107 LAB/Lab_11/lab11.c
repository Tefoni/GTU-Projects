#include <stdio.h>
#include <stdlib.h>
#define N 15
#define filename "TASK.txt"

typedef struct Student{
	int id;
	float gpa;
	char name[50],surname[50];	
}student;

void read(){
	FILE *fptr;
	fptr = fopen(filename,"r");
	if(fptr == NULL){
		printf("Couldn't open text file.\n");
		exit(1);
	}
	student studen[15];
	int i=0;
	while(!feof(fptr)){
		fscanf(fptr,"%s %s %d %f",studen[i].name,studen[i].surname,&studen[i].id,&studen[i].gpa);
		i++;	
	}
	fclose(fptr);
	int h=0,m=0;
	float temph=studen[0].gpa;
	float tempm=studen[0].gpa;
	for(i=0;i<15;i++){
		if(studen[i].gpa>temph){
			temph=studen[i].gpa;
			h=i;}
		if(studen[i].gpa<tempm){
			tempm=studen[i].gpa;
			m=i;}
	}
	printf("The student with the highest GPA:\n");
	printf("name: %s   surname: %s   id: %d   gpa: %0.1f\n",studen[h].name,studen[h].surname,studen[h].id,studen[h].gpa);
	printf("The student with the lowest GPA:\n");
	printf("name: %s surname: %s id: %d gpa: %0.1f",studen[m].name,studen[m].surname,studen[m].id,studen[m].gpa);	
}

int main(){
	read();

}
