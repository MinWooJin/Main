#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int number, i, j, k, size;
  int count[10]={0};
  char a[10];
  scanf("%d",&number);
  if (number > 1000000000) exit(1);

  for (i=1; i<number+1; i++) {
      sprintf(a, "%d", i);
      //itoa(i, a, 10);
      size = strlen(a);
      for (j=0; j<size; j++) {
          if (a[j]=='0') count[0]++;
          else if (a[j]=='1') count[1]++;
          else if (a[j]=='2') count[2]++;
          else if (a[j]=='3') count[3]++;
          else if (a[j]=='4') count[4]++;
          else if (a[j]=='5') count[5]++;
          else if (a[j]=='6') count[6]++;
          else if (a[j]=='7') count[7]++;
          else if (a[j]=='8') count[8]++;
          else if (a[j]=='9') count[9]++;
      }
  }
  for (k=0; k<10; k++)
      printf("%d ", count[k]);

  system("PAUSE");	
  return 0;
}
