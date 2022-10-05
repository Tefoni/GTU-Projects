#include <stdio.h>

int main()
{
  int m,n,h;
  printf("Piramitin yuksekligini giriniz:");
  scanf("%d",&h);
  for(m=1;m<=h;m++){
    for(n=1;n<=h-m;n++)
      printf(" ");
        for(n=1; n<=(2*m)-1;n++)
            printf("*");

    printf("\n");
  }
  return 0;
}
