#include <stdio.h>

void func_line();
void func_student(int n);
void func_games(int x);

typedef struct{
	float x1,x2,x3;
	float y1,y2,y3;
	float m;
}line;

typedef struct{
	float midterm,final,homework;
	float aver_m,aver_f,aver_h;
}grades;

typedef struct{
	char name[20],surname[20];
	int id;
	grades notes;
}students;

typedef struct{
	char name[20];
	char platforms[20][20];
	float score;
}games;


int main(){
	int n,x;
	func_line();

	printf("Enter the number of students: ");
	scanf("%d",&n);
	func_student(n);

	printf("Enter the number of games: ");
	scanf("%d",&x);
	func_games(x);

}

void func_line(){
	line d;
	float b;

	printf("Enter x1 and y1(Example:x1 y1) :");
	scanf("%f %f",&d.x1,&d.y1);
	printf("Enter x2 and y2(Example:x2 y2) :");    /* Getting coordinates input */
	scanf("%f %f",&d.x2,&d.y2);
	printf("Enter x3(Example:x3) :");
	scanf("%f",&d.x3);

	d.m=(d.y2-d.y1)/(d.x2-d.x1); /* Doing mathematic calculations */
	b=d.y2 -(d.m*d.x2);

	d.y3=(d.m*d.x3)+b;

	printf("The slope is: %.1f\n",d.m);  /* Printing right output format */
	printf("The y3 is: %.1f",d.y3);


}

void func_student(int n){
	students ar[n];
	int i=0,counter=0,choice,id_check,a=0;

	ar[0].notes.aver_m=0,ar[0].notes.aver_f=0,ar[0].notes.aver_h=0;

	do{	
		printf("Enter %d. student name-surname(Example: name surname): ",i+1);
		scanf("%s %s",ar[i].name,ar[i].surname);
		printf("Enter %d. students id(Example: id): ",i+1);
		scanf("%d",&ar[i].id);
		printf("Enter %d. student grades(Example: midterm final homework): ",i+1);
		scanf("%f %f %f",&ar[i].notes.midterm,&ar[i].notes.final,&ar[i].notes.homework);    /* Getting students information */

		ar[0].notes.aver_m+=ar[i].notes.midterm;
		ar[0].notes.aver_f+=ar[i].notes.final;     /* Calculate the averages */
		ar[0].notes.aver_h+=ar[i].notes.homework;


		printf("If you want continue enter 0 / If you want close the program enter -1: "); /* Asking the user what he want */
		scanf("%d",&choice);

		i++,counter++;
	}while(counter<n && choice!=-1);

	ar[0].notes.aver_m/=counter;
	ar[0].notes.aver_f/=counter;
	ar[0].notes.aver_h/=counter;

	printf("Enter the id number of the user whose information you want to learn: ");
	scanf("%d",&id_check);

	for(i=0;i<counter;i++){
		if(ar[i].id==id_check){
			printf("Name-surname: %s %s\n",ar[i].name,ar[i].surname);
			printf("Id: %d\n",ar[i].id);
			printf("Student grades(midterm final homework): %.1f %.1f %.1f\n",ar[i].notes.midterm,ar[i].notes.final,ar[i].notes.homework);   /* Finding assign id and print the right format */
			a++;
		}
	}
	printf("Average midterm: %.1f\n",ar[0].notes.aver_m);
	printf("Average final: %.1f\n",ar[0].notes.aver_f);
	printf("Average homework: %.1f\n",ar[0].notes.aver_h);
	if(a==0)printf("There are no students with this id.");

}

void func_games(int x){
	games ar[x];
	int i=0,j,p_num,counter=0,choice=0;
	float average=0;

	do{
		printf("Enter %d. game name: ",i+1);
		fflush(stdin);
		scanf(" %[^\n]%*c",ar[i].name);
		printf("How many platforms will you enter for this game: ");
		scanf("%d",&p_num);
		for(j=0;j<p_num;j++){
			printf("Enter %d. platform: ",j+1);
			scanf(" %[^\n]%*c",ar[i].platforms[j]);    /* Gettting input */
		}
		printf("Enter %d. game score: ",i+1);
		scanf("%f",&ar[i].score);
		average+=ar[i].score;





		printf("If you want continue enter 0 / If you want close the program enter -1: ");
		scanf("%d",&choice);

		i++,counter++;
	}while(counter<x && choice!=-1);

	average/=counter;

	printf("Average of the scores of the games: %.1f",average); /* Printing right output format */

}
