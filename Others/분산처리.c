#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int testcase;
  int i,j,k;
  scanf("%d",&testcase);
  int a[testcase], b[testcase], result[testcase];
  for (i=0; i<testcase; i++) {
      result[i]=1;
      scanf("%d %d", &a[i], &b[i]);
      if (a[i] < 1 || a[i] > 100 || b[i] < 1 || b[i] > 1000000) exit(1);
      int bnum=b[i];
      if (a[i]%10 == 0) result[i]=10;
      else if (bnum == 1)
         result[i] = a[i] % 10;
      else
          result[i] = a[i];

      for (j=0; j<bnum-1; j++) {
          if (result[i]==10) break;
          result[i] = (a[i] * result[i])%10;
      }
  }
  for (k=0; k<testcase; k++)
      printf("%d\n",result[k]);
 
  system("PAUSE");	
  return 0;
}
