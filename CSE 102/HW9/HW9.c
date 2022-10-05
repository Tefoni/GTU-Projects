#include <stdio.h>
#include <string.h>


typedef struct {
	char name[20];
	char label;
	int age;
}bank;

int main(){
	int i,j,k,choice,sequence_count=0,row_start;
	int zero_count,one_count,two_count,three_count,four_count,row_completed;

	char sequence[50];
	char emptyStr[20]="\0";     /*It ıs an empty string for clean processed customer name */
	bank gtu[50],temp;

	for(i=0;i<50;i++){
		sequence[i]='5';     /* Filling sequence with bigger number than labels for my algorithm */
	}

	printf("***********Banking System***********\n");

	do{
		printf("\nCurrent Sequence: ");
		for(i=0;i<strlen(sequence);i++){     /* Printing current sequence in right format */
			if(sequence[i]!='5'){
				printf("%c",sequence[i]);
				if(i!=sequence_count-1)	printf("-");
			}
		}

		printf("\n\n1-Add customer\n\n");
		printf("2-Process customer\n\n");
		printf("3-Close the program\n\n");
		scanf("%d",&choice);     /* Getting input which user's want */

		if(choice==1){
			if(sequence_count==50)	printf("The bank system sequence is full");     /* If sequence is full,we can't add more customer */

			else{
				printf("Please enter the name of the customer : ");
				scanf("%s",gtu[sequence_count].name);
				printf("Please enter the age of the customer : ");      /* Getting customer information inputs */
				scanf("%d",&gtu[sequence_count].age);
				printf("Please enter the label of the customer : ");
				scanf(" %c",&gtu[sequence_count].label);

				zero_count=0,one_count=0,two_count=0,three_count=0,four_count=0,row_completed=1;

				for(i=0;i<strlen(sequence);i++){
					if(sequence[i]=='0')zero_count++;
					else if(sequence[i]=='1')one_count++;
					else if(sequence[i]=='2')two_count++;     /* Checking how many same labels are there in a row */
					else if(sequence[i]=='3')three_count++;
					else if(sequence[i]=='4')four_count++;					
				}

				if(gtu[sequence_count].label=='0' && zero_count<5)	row_completed=0;
				else if(gtu[sequence_count].label=='1' && one_count<3)	row_completed=0;
				else if(gtu[sequence_count].label=='2' && two_count<3)	row_completed=0;
				else if(gtu[sequence_count].label=='3' && three_count<2)	row_completed=0;     /* Checking which label has a vacant place next to it */
				else if(gtu[sequence_count].label=='4' && four_count<2)	row_completed=0;		 /* If there is not so it means row is completed */

				for(i=0;i<strlen(sequence);i++){
					if(row_completed==0){     /* If row is not completed */
						if(gtu[sequence_count].label<sequence[i]){
							for(j=49;j>i;j--){
								sequence[j]=sequence[j-1];
							}
																	/* Shifting the sequence to the right and put the element in the right place */
							sequence[i]=gtu[sequence_count].label;

							temp = gtu[sequence_count];
							for(j=49;j>i;j--){
								gtu[j]=gtu[j-1];
							}
											/* Shifting the structures to the right and put the structure element in the right place */
							gtu[i]=temp;

							i=strlen(sequence)+1;
						}
					}
				}

				row_start=0;

				if(row_completed==1){     /* If row is completed */
					for(k=49;k>0;k--){
						if(sequence[k]<sequence[k-1])	row_start=k; /*Finding algorithm: if i. element>i-1. element it's row_start */
					}
																	/* Finding row_start starting from the end of the search */
					if(row_start==0)	row_start=sequence_count;	/* Finding algorithm: if the new row has not started, the last element is the start of the new row */

					for(i=row_start;i<strlen(sequence);i++){
						if(gtu[sequence_count].label<sequence[i]){
							for(j=49;j>i;j--){
								sequence[j]=sequence[j-1];
							}
																	/* Shifting the sequence to the right and put the element in the right place */
							sequence[i]=gtu[sequence_count].label;

							temp = gtu[sequence_count];
							for(j=49;j>i;j--){
								gtu[j]=gtu[j-1];
							}
											/* Shifting the structures to the right and put the structure element in the right place */
							gtu[i]=temp;

							i=strlen(sequence)+1;
						}
					}						
				}

			sequence_count++;     /* New customer queued and increased the sequence counter */
			}
		}
		else if(choice==2){
			if(sequence_count==0)	printf("\nThere is not any customer in bank system sequence\n");      /* If sequence is empty,we can't proceed any customer */

			else{
				printf("Proceed customer is %s",gtu[0].name); /* Proceed the leftmost customer */

				for(i=0;i<sequence_count-1;i++){/* Move the sequence and structs one to the left to create the new sequence */
					gtu[i]=gtu[i+1];
					sequence[i]=sequence[i+1];
				}

				strcpy(gtu[sequence_count-1].name,emptyStr); /* Clean the last struct element */
				sequence[sequence_count-1]='5'; /* Clean the last sequence element */

				sequence_count--;     /* Customer has been proceed and decreased the sequence counter */
			}
		}

	}while(choice!=3); /* If user want to close program, program will be closed if choice is 3 */
}