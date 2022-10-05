#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
	char title[50];
	char author[50];
	char subject[50];
	int year;

}Book;

int main(){
	int i,choice,choice2,counter=1,a=0;
	char search[50];
	int small_year,big_year;


	Book *ar,*ar2 = NULL;


	do{
		printf("MENU\n");
		printf("        1.Add New Book\n");     /* Printing right output format and getting choice input */
		printf("        2.List Books\n");
		printf("        3.EXIT\n\n"); 
		printf("Choose = ");
		scanf("%d",&choice);
		printf("***********************\n");

		if(choice==1){
			ar = (Book*)calloc(counter,sizeof(Book));


			printf("Please enter book title = ");
			fflush(stdin);
			scanf(" %[^\n]%*c",ar[counter-1].title);

			printf("Please enter book author = ");
			fflush(stdin);
			scanf(" %[^\n]%*c",ar[counter-1].author);     /* If user want to add book getting input and increase dynamic memory size */

			printf("Please enter book subject = ");
			fflush(stdin);
			scanf(" %[^\n]%*c",ar[counter-1].subject);

			printf("Please enter book year = ");
			scanf("%d",&ar[counter-1].year);
			printf("\n***********************\n");

			for(i=0;i<counter-1;i++) ar[i]=ar2[i]; /* Copying old elements to our array */

			if(ar2!=NULL) free(ar2);    /* Delete the copied memory for dont out of memory */

			ar2=ar;
			counter++;     /* We got inputs and increase book counter */
		}
		else if(choice==2){
			a=0;
			printf("SUBMENU\n");
			printf("        1.Get by Title\n");
			printf("        2.Get by Author\n");
			printf("        3.Get by Subject\n");
			printf("        4.Sorted List by Year (DESC)\n");     /* Printing right output format and getting choice2 input */
			printf("        5.List All Books\n");
			printf("        6.EXIT SUBMENU\n\n");
			printf("Choose = ");
			scanf("%d",&choice2);
			printf("***********************\n");

			if(choice2==1){
				printf("Enter a books title = ");
				fflush(stdin);
				scanf(" %[^\n]%*c",search);			/* If user want search a book with title i get its name */

				for(i=0;i<counter;i++){
					if(strcmp(search,ar[i].title)==0){
						printf("Book found\n");
						printf("Title => %s\n",ar[i].title);
						printf("Author => %s\n",ar[i].author);
						printf("Subject => %s\n",ar[i].subject);     /* And searching in array if i find i print it */
						printf("Year => %d",ar[i].year);
						printf("\n***********************\n");
						a++;
					}
				}
				if(a==0)printf("Book could not found\n");     /* If i can't find i print that */


			}

			else if(choice2==2){
				printf("Enter a books Author = ");
				fflush(stdin);
				scanf(" %[^\n]%*c",search);			/* If user want search a book with author i get its name */			

				for(i=0;i<counter;i++){
					if(strcmp(search,ar[i].author)==0){
						printf("Book found\n");
						printf("Title => %s\n",ar[i].title);
						printf("Author => %s\n",ar[i].author);
						printf("Subject => %s\n",ar[i].subject);	/* And searching in array if i find i print it */
						printf("Year => %d",ar[i].year);
						printf("\n***********************\n");
						a++;
					}
				}
				if(a==0)printf("Book could not found\n");	/* If i can't find i print that */


			}

			else if(choice2==3){
				printf("Enter a books subject = ");
				fflush(stdin);
				scanf(" %[^\n]%*c",search);			/* If user want search a book with subject i get its name */

				for(i=0;i<counter;i++){
					if(strcmp(search,ar[i].subject)==0){
						printf("Book found\n");
						printf("Title => %s\n",ar[i].title);
						printf("Author => %s\n",ar[i].author);
						printf("Subject => %s\n",ar[i].subject);	/* And searching in array if i find i print it */
						printf("Year => %d",ar[i].year);
						printf("\n***********************\n");
						a++;
					}
				}
				if(a==0)printf("Book could not found\n");	/* If i can't find i print that */

			}

			else if(choice2==4){
				small_year=99999,big_year=0;

				for(i=0;i<counter;i++){
					if(ar[i].year>big_year)big_year=ar[i].year;
					if(small_year>ar[i].year && ar[i].year>0)small_year=ar[i].year;    /* Find the max and min year */
				}

				a=1;
				for(;small_year<=big_year;small_year++){
					for(i=0;i<counter;i++){
						if(ar[i].year==small_year){
							printf("%d. Book;\n",a);
							printf("Title => %s\n",ar[i].title);
							printf("Author => %s\n",ar[i].author);
							printf("Subject => %s\n",ar[i].subject);	/*searching min to max year in array if i find i print them */
							printf("Year => %d",ar[i].year);
							printf("\n***********************\n");

							a++;
						}
					}
				}

			}

			else if(choice2==5){
				printf("List of Books");
				printf("\n***********************\n");

				for(i=0;i<counter-1;i++){
					printf("%d. Book\n",i+1);
					printf("Title => %s\n",ar[i].title);
					printf("Author => %s\n",ar[i].author);
					printf("Subject => %s\n",ar[i].subject);		/* I print list of books right output format */
					printf("Year => %d",ar[i].year);
					printf("\n***********************\n");
				}				
			}
			else if(choice2==6){}

			else printf("TRY AGAIN");	/* If user enter wrong choice i print it and going menu back */

		}
		else if(choice==3){}

		else printf("TRY AGAIN");	/* If user enter wrong choice i print it and going menu back */






	}while(choice!=3);


}
