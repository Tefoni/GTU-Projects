/* 

The variable names that used in this file have no relation with the ones in the pdf file. 

<?> in the functions means something other than void, you should find the correct type for these functions.

*/

#include <stdio.h>

void age(int x);
int age_calculation(int x);
double trigonometry_calculation(int a, int b, int c);

void trigonometry(int a, int b, int c)
{	double sinx,cosx,tanx;
 	sinx,cosx,tanx=trigonometry_calculation(a,b,c);
 	printf("sinx:%lf ",sinx);
 	printf("cosx:%lf ",cosx);
 	printf("tanx:%lf ",tanx);

    return;
}

double trigonometry_calculation(int a, int b, int c)
{
    double sinx=(double)a/c;
    double cosx=(double)b/c;
    double tanx=(double)a/b;
    return sinx,cosx,tanx;
}

void age(int x)
{
	int result = age_calculation(x);
	printf("You are %d seconds",result);
    return;
}


int age_calculation(int x)
{
    int result;
    result=(365*24*60*60)*x;
    return result;
}


int main()
{	
	int a,b,c,ages;

	printf("Type your triangle lenghts\n");
	printf("a:");
	scanf("%d",&a);
	printf("b:");
	scanf("%d",&b);
	printf("c:");
	scanf("%d",&c);

	trigonometry(a,b,c);
    /*---------------------*/
	printf("\nYour age:");
	scanf("%d",&ages);
	age(ages);


    return 0;
}
