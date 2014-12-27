#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  double a;
  int b;
  scanf("%lf %d", &a, &b);
  double addresult=a/b;
  printf("%.32lf",addresult);

  system("PAUSE");	
  return 0;

}
