#include <stdio.h>
#include <stdlib.h>

int zero_count, one_count;

int fibonacci(int n);

int main(int argc, char *argv[])
{
  int number, i, j, set, k;
  scanf("%d",&number);
  int testcase[number];
  for (i=0; i<number; i++) {
      scanf("%d",&testcase[i]);
      if (testcase[i]>40 || testcase[i]<0)
         exit(1);
  }
  for (j=0; j<number; j++) {
      zero_count=0, one_count=0;
      set=testcase[j];
      k = fibonacci(set);
      printf("%d %d\n", zero_count, one_count);
  }

  system("PAUSE");	
  return 0;
}

int fibonacci(int n) {
    if (n==0) {
       zero_count++;
       return 0;
    } else if (n==1) {
       one_count++;
       return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}
