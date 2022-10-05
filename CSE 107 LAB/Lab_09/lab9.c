#include <stdio.h>
#include <time.h>
int find_number_of_x(int x,int n,int arr[]);

int find_mode(int n,int arr[]);

int main(){
	int arr[100],i,n,count[10],x,mode;
	srand(time(NULL));
	printf("How many elements have you:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		arr[i]=rand()%10+1;
	for(i=0;i<10;i++){
		x = i+1;
		count[i]=find_number_of_x( x , n , arr );
	}
	for(i=0;i<10;i++){
		printf("%d --> %d\n",i+1,count[i]);
	}
	mode=find_mode(10,count);
	printf("The mode is %d",mode);		
}

int find_number_of_x(int x,int n,int arr[]){
	int i,local_count=0;
	for(i=0;i<n;i++){
		if(arr[i]==x)
			local_count++;
	}
	return local_count;	
}

int find_mode(int n,int count[]){
	int i,temp=count[0],a=1;
	for(i=0;i<n;i++){
		if(count[i]>temp){
			temp=count[i];
			a=i+1;
		}
	}
			return a;	
		
	
	
}
