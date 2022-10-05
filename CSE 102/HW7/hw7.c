#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void fix_spelling_error(char const files1[],char const files2[]);
void find_best_correction(char str[],FILE *fw,FILE *fr,int punctuation);

int main(){
	char files1[50]="text.txt";
	char files2[50]="dictionary.txt";

	fix_spelling_error(files1,files2);     /* Create the strings containing filenames  and sending them to function */
}

void fix_spelling_error(char const files1[],char const files2[]){
	char str[50],temp;
	int i,j,punctuation;


	FILE *fw;
	FILE *fr;
	fw=fopen(files1,"r+");
	fr=fopen(files2,"r+");
												/* Open the two files and controlling did it open */
	if(fw==NULL||fr==NULL){
    	printf("Error while opening the file\n");
        exit(1);
    }

	while(fscanf(fw,"%s",str)!=EOF){     /* Getting words until end of file */
		punctuation=0;
		for(i=0;i<50;i++){
			if(!(str[i] >= 'a' && str[i] <= 'z') && !(str[i] >= 'A' && str[i] <= 'Z') && str[i]>32 && str[i]!=64 && !(str[i]>= '0' && str[i]<='9')){
				punctuation++;
				for(j=i;j<strlen(str)-1;j++){    /* If there is a non-alphabet character,move it to end of string and send the word to function without punctuations */
					temp=str[j+1];
					str[j+1]=str[j];
					str[j]=temp;
				}
				str[strlen(str)-1] = '\0';
			}
		}
		for(i=0;i<50;i++){
			if(str[i]>='A' && str[i]<='Z')	str[i]+= 'a'-'A';}    /* If there is a capital character change to it a normal character because in dictionart.txt there shouldn't be any capital character(Yakup teacher said) */

		find_best_correction(str,fw,fr,punctuation);

		for(i=0;i<50;i++){
			str[i] = '\0';} /* Reset the string for any memorial issue */
		
	}
	fclose(fw);
	fclose(fr);  /* Close the two files after the all process */
}

void find_best_correction(char str[],FILE *fw,FILE *fr,int punctuation){
	char dic[50];
	int i,counter,sum=0;

	while(fscanf(fr,"%s",dic)!=EOF){
		if(strcmp(str,dic)==0)	sum++;     /* If the dictionary contains the same word in the text sum++ and next process will not change  the text file for this word */
	}

	fseek(fr,0,SEEK_SET);     /* Reset the dictionary file cursor for no match above */

	while(fscanf(fr,"%s",dic)!=EOF && sum==0){
			counter=0;
			for(i=0;i<strlen(str);i++){
				if(str[i]==dic[i])	counter++;}     /* Increment the counter for each character match */
			
			if(strlen(str)-1==counter){
				fseek(fw,-strlen(str)-punctuation,SEEK_CUR);
				fprintf(fw,"%s",dic);
				fseek(fw,+punctuation,SEEK_CUR);      /* If there is a only one character error, fprintf the word in the dictionary according to punctuation */
			}	
	}	

	for(i=0;i<50;i++){
		strcpy(dic,"\0");}     /* Reset the string for any memorial issue */

	fseek(fr,0,SEEK_SET);     /* Reset the dictionary file cursor for next word */
}

/**************** BONUS PART *********************/

/* If change the 72th line with -->    if(strlen(str)-2==counter){
	Function can found the 2 letters of mistakes are made in misspelled words */




