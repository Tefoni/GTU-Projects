#include <stdio.h>

void print_line(char c, int num_of_chars);

void print_histogram(char c, int vals[]);

int len(int arr[]);

int main(){
	int values[100], val=1, count=0;
	printf("Enter positive integer(s), to print an histogram.\nEnter a non-positive integer to stop.\n\n");
	do{
		printf("Enter a value: ");
		scanf("%d", &val);
		values[count] = val;
		count++;
	}while(val > 0);
	print_histogram('*', values);
	
	return 0;
}

void print_histogram(char c, int vals[]){
	int i,j,lenght;
	lenght=len(vals);
	
	for(j=0;j<lenght;j++){
		for(i=0;i<vals[j];i++)
			printf("%c", c);
		
	print_line('\n', lenght);
	}
}

void print_line(char c, int num_of_chars){
	printf("%c", c);
}

int len(int arr[]){
	int k=0, counter=0;
	while(arr[k] > 0){
		k++;
		counter++;
	}
	
	return counter;
}

