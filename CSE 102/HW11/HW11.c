#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct M_budget{
	int budget,year;
	char *name;
	struct M_budget *next;
}Movie_Budget;				

typedef struct M_name{
	double score;
	char *genre,*name;
	struct M_name *next;
}Movie_Name;

void reading_file(FILE *fp , Movie_Budget **mbudget_head , Movie_Name **mname_head , int numof_lines);

Movie_Budget* newnode_movie_budget(char *budget , char *name , char *year);
void same_Movie_Budget_node(Movie_Budget **mbudget_head , Movie_Budget *new_node);
void insert_movie_budget(Movie_Budget **mbudget_head , Movie_Budget *new_node);

Movie_Name* newnode_movie_name(char *genre,char *name, char *score);
void same_Movie_Name_node(Movie_Name **mname_head , Movie_Name *new_node2);
void insert_movie_name(Movie_Name **mname_head,Movie_Name *new_node2);

int line_count(FILE *fp);
int line_lenght_count(FILE*fp);

void Menu_option1(Movie_Name **mname_head , Movie_Budget **mbudget_head);
void Menu_option2_7(Movie_Name **mname_head , int choice);
void Menu_option3(Movie_Budget **mbudget_head);
void Menu_option4(Movie_Name **mname_head);
void Menu_option5(Movie_Name **mname_head , Movie_Budget **mbudget_head);
void Menu_option6(Movie_Name **mname_head);


int main(){
	FILE *fp;
	Movie_Budget *mbudget_head = NULL;
	Movie_Name *mname_head = NULL;
	int numof_lines , choice;
	
	fp = fopen("Movies.txt","r");
	if(fp==NULL){
		printf("File can not opened!\n");	/* Opening the file,If can not printing error message */
		exit(1);
	}

	numof_lines = line_count(fp);	/* Calculate the amount of lines in file */
	reading_file(fp,&mbudget_head,&mname_head,numof_lines);	/* Read the file in right format and sort the movie_name,movie_budget */

	do{
		printf("1. List of the Sorted Data\n");
		printf("2. List of the Genres\n");
		printf("3. List of the Movie Through the Years\n");
		printf("4. List of the Movie Through the Scores\n");
		printf("5. All Informations of a Single Movie\n");	/* Printing right format of menu */
		printf("6. Average of the IMDB Scores\n");
		printf("7. Frequence of the Genres\n");
		printf("8. Exit\n\n");
		printf("Please Select an operation: ");
		scanf("%d",&choice);
		printf("\n");
		switch(choice)
		{

			case 1:
				Menu_option1(&mname_head,&mbudget_head);
				break;

			case 2:
				Menu_option2_7(&mname_head,choice);
				break;

			case 3:
				Menu_option3(&mbudget_head);
				break;

			case 4:
				Menu_option4(&mname_head);
				break;
																	/* Getting user choice input and rotate the program to right function */
			case 5:
				Menu_option5(&mname_head , &mbudget_head);
				break;

			case 6:
				Menu_option6(&mname_head);
				break;

			case 7:
				Menu_option2_7(&mname_head,choice);
				break;

			case 8:
				printf("\nProgram is closing...");
				break;

			default:
				printf("TRY AGAIN.\n\n\n");

		}				/* If user enter wrong number i get input again or user want to leave program i terminate it */

	}while(choice!=8);
}

void Menu_option1(Movie_Name **mname_head , Movie_Budget **mbudget_head){
	int choice,choice2,found=0,i=1;
	/*
	Movie_Name *current_namelist = *mname_head , **sorted_currentnamelist_head , *sorted_current_namelist;
	Movie_Budget *current_budgetlist = *mbudget_head , **sorted_currentbudgetlist_head , *sorted_current_budgetlist;


	while(current_namelist!=NULL){
		current_namelist->next = *sorted_currentnamelist_head;
		*sorted_currentnamelist_head = current_namelist;

		current_namelist = current_namelist->next;
	}

	sorted_current_namelist = *sorted_currentnamelist_head;

	while(*sorted_currentnamelist_head!=NULL){
		printf("(%d) %f %s\n",i,(*sorted_currentnamelist_head)->score,(*sorted_currentnamelist_head)->name);
		i++;
		(*sorted_currentnamelist_head)= (*sorted_currentnamelist_head)->next;
	}
	*/
	do{
		printf("1.Budget\n");
		printf("2.Genre\n");
		printf("3.Name\n");
		printf("4.Score\n");
		printf("5.Year\n\n");
		printf("Please Select an operation: ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				printf("1.Single Selection\n2.Multiple Selection\n\n");
				printf("Please Select an operation: ");
				scanf("%d",&choice2);

				switch(choice2)
				{
					case 1:

						break;

					case 2:

						break;

					default:
						printf("TRY AGAIN\n\n\n");
				}

				break;

			case 2:
				printf("1.Single Selection\n\n");
				printf("Please Select an operation: ");
				scanf("%d",&choice2);

				switch(choice2)
				{
					case 1:
						
						break;

					default:
						printf("TRY AGAIN\n\n\n");
				}

				break;

			case 3:
				printf("1.Single Selection\n\n");
				printf("Please Select an operation: ");
				scanf("%d",&choice2);

				switch(choice2)
				{
					case 1:

						break;

					default:
						printf("TRY AGAIN\n\n\n");
				}

				break;

			case 4:
				printf("1.Single Selection\n2.Multiple Selection\n\n");
				printf("Please Select an operation: ");
				scanf("%d",&choice2);

				switch(choice2)
				{
					case 1:
						
						break;

					case 2:
						
						break;

					default:
						printf("TRY AGAIN\n\n\n");
				}

				break;

			case 5:
				printf("1.Single Selection\n2.Multiple Selection\n\n");
				printf("Please Select an operation: ");
				scanf("%d",&choice2);

				switch(choice2)
				{
					case 1:
						
						break;

					case 2:
						
						break;

					default:
						printf("TRY AGAIN\n\n\n");
				}

				break;

			default:
				printf("TRY AGAIN\n\n\n");



		}
		found++;
		printf("\nI could not do the Part 1\n\n");

	}while(found==0);


}

void Menu_option2_7(Movie_Name **mname_head,int choice){
	char **genres,**genres_cp=NULL;
	int *genres_amount=NULL,*genres_amount_cp=NULL,counter=1,i,j=0,found;
	Movie_Name *current = *mname_head;

	printf("\n");
	while(current!=NULL){
		found=0;
		for(i=0;i<j;i++){
			if(strcmp(genres[i],current->genre)==0){
				genres_amount[i]++;	/* If there is same genre in before elements in linked list,Frequency of genre is increasing */
				found++;	/* And found is flag for below process */
			}		
		}
		if(found==0){
			genres = (char**)calloc(counter,sizeof(char*));
			genres[j] = (char*)calloc(strlen(current->genre)+1,sizeof(char));
			strcpy(genres[j],current->genre);	/* If i could not find same genre before(mean found==0) i create new element of genres and genres_amount in dynamic way */

			genres_amount = (int*)calloc(counter,sizeof(int));

			for(i=0;i<counter-1;i++){
				genres[i]=genres_cp[i];
				genres_amount[i]=genres_amount_cp[i];
			}

			if(genres_cp!=NULL)	free(genres_cp);
			if(genres_amount_cp!=NULL)	free(genres_amount_cp);

			genres_cp = genres;
			genres_amount_cp = genres_amount;

			counter++;
			j++;

		}
		current = current->next;
	}

	if(choice==2){
		for(i=0;i<counter-1;i++){
			printf("%s\n",genres[i]);	/* If user want to list of the genres i print it */
		}
	}
	else if(choice==7){
		for(i=0;i<counter-1;i++){
			printf("%-20s%d\n",genres[i],genres_amount[i]+1);	/* If user want to frequency of the genres i print it */
		}
	}

	printf("\n");
}

void Menu_option3(Movie_Budget **mbudget_head){
	int wanted_year,found,untilor_since;
	Movie_Budget *current;

	do{
		found=0 , current = *mbudget_head;
		printf("\nEnter a year:\n");
		scanf("%d",&wanted_year);
		printf("Until (0) or Since (1)  %d:",wanted_year);	/* I'm getting the necessary inputs for output */ 
		scanf("%d",&untilor_since);


		while(current!=NULL){
			if(current->year==wanted_year)	found++;	/* Found is a flag for find the wanted_year an element in the linked list range or not */
			current = current->next;
		}
		current = *mbudget_head;

		if(untilor_since==0){
			while(current!=NULL && found!=0){	/* Example linked list years range 1986-2020 */
				if(current->year <= wanted_year){	/* If user input 2010 until i print like that 2010-...-1986 */
					printf("%s\n",current->name);	/* Pdf don't say output must in an order */
				}									/* so i do that way for not to reduce the efficiency of the program ,Also I could not decide */
				current = current->next;
			}
		}										/* I also write the cases where it is equal to the wanted year */
		else if(untilor_since==1){
			while(current!=NULL && found!=0){
				if(current->year >= wanted_year){	/* If user input 2010 since i print like that 2016-...-2010*/
					printf("%s\n",current->name);	/* Pdf don't say output must in an order */
				}									/* so i do that way for not to reduce the efficiency of the program ,Also I could not decide */
				current = current->next;
			}
		}
		else	printf("\nTRY AGAIN\n");

		if(found==0)	printf("\nTRY AGAIN\n");	/* If user enter wrong option i get input again */

		printf("\n\n");

	}while(found==0);
}

void Menu_option4(Movie_Name **mname_head){
	int found,leesor_greater;
	double wanted_score;
	Movie_Name *current;

	do{
		found=0 , current = *mname_head;
		printf("\nEnter a score:\n");
		scanf("%lf",&wanted_score);
		printf("Less (0) or Greater (1)  %.2f:",wanted_score);	/* I'm getting the necessary inputs for output */ 
		scanf("%d",&leesor_greater);

		if(leesor_greater==0){
			while(current!=NULL){
				if(current->score < wanted_score){
					printf("%s\n",current->name);	/* If the current score smaller than wanted_score i print it */
					found++;						/* I print in descending order because pdf dont say anything about for order */
				}
				current = current->next;
			}
		}
		else if(leesor_greater==1){
			while(current!=NULL){
				if(current->score > wanted_score){
					printf("%s\n",current->name);	/* If the current score bigger than wanted_score i print it */
					found++;						/* I print in descending order because pdf dont say anything about for order */
				}
				current = current->next;
			}
		}
		else	printf("\nTRY AGAINx\n");

		if(found==0)	printf("\nTRY AGAIN\n");	/* If user enter wrong option i get input again */

		printf("\n\n");

	}while(found==0);
}

void Menu_option5(Movie_Name **mname_head , Movie_Budget **mbudget_head){
	char choice_name[100],genre[100];
	int budget,year,find=0;
	double score;
	Movie_Name *current_namelist = *mname_head;
	Movie_Budget *current_budgetlist = *mbudget_head;

	fflush(stdin);
	printf("Please Enter the name of the movie:\n");	/* I get the name of the movie the user wants */
	scanf(" %[^\n]s",choice_name);

	while(current_budgetlist!=NULL || current_namelist!=NULL){
		if(strcmp(choice_name,current_budgetlist->name)==0){
			budget = current_budgetlist->budget;
			year = current_budgetlist->year;
			find++;
		}
												/* I search both of linked list and if i find i get all information of movie */
		if(strcmp(choice_name,current_namelist->name)==0){
			score = current_namelist->score;
			strcpy(genre,current_namelist->genre);
			find++;
		}
		current_budgetlist = current_budgetlist->next;
		current_namelist = current_namelist->next;
	}
	if(find==2){
		if(budget==-1)	printf("Budget: Unknown\n");
		else	printf("\nBudget: %d\n",budget);
		printf("Genre:  %s\n",genre);
		printf("Name:   %s\n",choice_name);		/* And i print in right format */
		printf("Score:  %.1f\n",score);
		printf("Year:   %d\n\n",year);
	}
	else{
		printf("There is no movie by this name!\n\n");	/* If i cant found movie i print error message */
	}
}

void Menu_option6(Movie_Name **mname_head){
	double result=0;
	int counter=0;
	Movie_Name *current = *mname_head;

	while(current!=NULL){
		result+= current->score;	/* I'm adding the scores in the result */
		counter++;

		current = current->next;
	}
	printf("Average: %f\n\n",result/counter);	/* I calculate the average and print it */

}

void reading_file(FILE *fp , Movie_Budget **mbudget_head , Movie_Name **mname_head , int numof_lines){
	int i , j , line_lenght , is_firstrow = 1;
	char *line=NULL , *first=NULL , *second=NULL , *third=NULL , *fourth=NULL , *fiveth=NULL , *temp;
	Movie_Budget *new_node;
	Movie_Name * new_node2;

	for(i=0;i<numof_lines;i++){
		line_lenght = line_lenght_count(fp);	/* Calculate the lenght of line */

		line = (char*)calloc(line_lenght+1,sizeof(char));	/* Allocate the memory for a line */
		fgets(line,line_lenght+1,fp);	/* Reading the line in file */
		fseek(fp,1,SEEK_CUR);

		if(first!=NULL || second!=NULL || third!=NULL || fourth!=NULL || fiveth!=NULL)		/* If it is not first row cleaning the memory */
			free(first) , free(second) , free(third) , free(fourth) , free(fiveth), is_firstrow = 0;	
		
		temp = strtok(line,",");
		first = (char*)calloc(strlen(temp)+1,sizeof(char));
		strcpy(first,temp);

		temp = strtok(NULL,",");
		second = (char*)calloc(strlen(temp)+1,sizeof(char));
		strcpy(second,temp);

		temp = strtok(NULL,",");
		third = (char*)calloc(strlen(temp)+1,sizeof(char));
		strcpy(third,temp);										/* I split the line by commas */

		temp = strtok(NULL,",");
		fourth = (char*)calloc(strlen(temp)+1,sizeof(char));
		strcpy(fourth,temp);

		temp = strtok(NULL,",");
		fiveth = (char*)calloc(strlen(temp)+1,sizeof(char));
		strcpy(fiveth,temp);

		if(is_firstrow==0){
			new_node = newnode_movie_budget(first , third , fiveth);
			same_Movie_Budget_node(mbudget_head , new_node);
			insert_movie_budget(mbudget_head , new_node);
																		/* If line is not first row i create a new node both of linked lists */
			new_node2 = newnode_movie_name(second , third , fourth);	/* And delete the same name movies and update them */
			same_Movie_Name_node(mname_head , new_node2);				/* After that I'm sorting the elements in descending order */
			insert_movie_name(mname_head , new_node2);	

		}

		free(line);
		}

	fseek(fp,0,SEEK_SET);
}

/**********************************************************************************************/
Movie_Budget *newnode_movie_budget(char *budget , char *name , char *year){
	char *trash;
	int budget_real,year_real;
	Movie_Budget *new = (Movie_Budget*)calloc(1,sizeof(Movie_Budget));
	new->name = (char*)calloc((strlen(name)+1),sizeof(char));			/* Allocate the enough memory for movie information */
	
	budget_real = strtod(budget,&trash);
	if(strcmp(trash,"unknown")==0)budget_real=-1;
	year_real = strtod(year,&trash);
												/* If it necessary i convert them to int,double */
	new->budget = budget_real;					/* And fill the linked list node and return it */
	new->year = year_real;
	strcpy(new->name,name);

	return new;

}

void same_Movie_Budget_node(Movie_Budget **mbudget_head , Movie_Budget *new_node){
	Movie_Budget *temp,*current = *mbudget_head;
	if(current!=NULL){
		while(current->next!= NULL){
			if(strcmp(current->next->name,new_node->name)==0){
				temp = current->next;
				current->next = temp->next;						/* If i found same movie name i delete the old version and sort,insert the updated version */
				free(temp);
			}
		current = current->next;
		}
	}
}

void insert_movie_budget(Movie_Budget **mbudget_head , Movie_Budget *new_node){
	Movie_Budget *current= *mbudget_head;

	if(*mbudget_head==NULL ||((*mbudget_head)->year < new_node->year)){
		new_node->next = *mbudget_head;		/* If new node year bigger than header,new node will be header */
		*mbudget_head = new_node;
		return;
	}
	if((*mbudget_head)->year == new_node->year){
		if((*mbudget_head)->budget < new_node->budget){
			new_node->next = *mbudget_head;
			*mbudget_head = new_node;
			return;
		}													/* If new node year equal to header look the budgets */
		if((*mbudget_head)->budget > new_node->budget){		/* If new node budget bigger than header,new node will be header */
			new_node->next = (*mbudget_head)->next;			/* If new node budget smaller than header,new node will be placed in the next element of header*/
			(*mbudget_head)->next = new_node;
			return;
		}
	}

	while(current->next!=NULL){
		if(current->next->year < new_node->year){
			new_node->next =  current->next;		/*Loop finding where to put the new element in descending order of years*/
			current->next = new_node;				 
			return;
		}	/* If there is an equality in years */
		if(current->next->year == new_node->year){
			if(current->next->budget <= new_node->budget){
				new_node->next = current->next;		/* Loop finding where to put the new element in descending order of budgets */
				current->next = new_node;
				return;
			}
		}
		current = current->next;
	}
	current->next = new_node;

}

/**********************************************************************************************/
Movie_Name* newnode_movie_name(char *genre,char *name, char *score){
	char *trash;
	double score_real;
	Movie_Name *new = (Movie_Name*)calloc(1,sizeof(Movie_Name));

	new->name = (char*)calloc((strlen(name)+1),sizeof(char));
	new->genre = (char*)calloc((strlen(genre)+1),sizeof(char));	/* Allocate the enough memory for movie information */

	score_real = strtod(score,&trash);
												/* If it necessary i convert them to int,double */
	new->score = score_real;					/* And fill the linked list node and return it */
	strcpy(new->genre,genre);
	strcpy(new->name,name);

	return new;
}

void same_Movie_Name_node(Movie_Name **mname_head , Movie_Name *new_node2){
	Movie_Name *temp,*current = *mname_head;
	if(current!=NULL){
		while(current->next!= NULL){
			if(strcmp(current->next->name,new_node2->name)==0){
				temp = current->next;
				current->next = temp->next;			/* If i found same movie name i delete the old version and sort,insert the updated version */
				free(temp);
			}
		current = current->next;
		}
	}

}

void insert_movie_name(Movie_Name **mname_head, Movie_Name *new_node2){/* I'm sorting the scores in descending order for make other parts easier and to make the program more efficient */
	Movie_Name *current= *mname_head;

	if(*mname_head==NULL ||((*mname_head)->score <= new_node2->score)){
		new_node2->next = *mname_head;
		*mname_head = new_node2;
		return;
	}
	while(current->next!=NULL){								/* If newnode score is bigger than current,it inserted in left to current node */
		if(new_node2->score >= current->next->score){		/* If newnode score is smaller than current,it inserted in right to current node */
			new_node2->next =  current->next;
			current->next = new_node2;
			return;
		}	
		current = current->next;
	}
	current->next = new_node2;

}

/**********************************************************************************************/
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
	fseek(fp,-line_lenght_count-1,SEEK_CUR);

	return line_lenght_count;
}