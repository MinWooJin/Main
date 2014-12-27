#include <stdio.h>
#include <stdlib.h>

int Msize, big;

typedef struct {
  int copyramp[50][50];
  int checkramp[50][50];
} COPYS;

void change_switch(int n, int m, int k, COPYS copy);

int main(int argc, char *argv[])
{
  int n, m, k, i, j, si, sj, check_all_on=1;
  COPYS copy;
  scanf("%d %d",&n,&m);
  Msize=m;
  int ramp[n][m], copyramp[n][m];
  char set[m], change[1];

  for (i=0; i<n; i++) {
      scanf("%s",&set);
      for (j=0; j<m; j++) {
          change[0]=set[j];
          ramp[i][j]=atoi(change);
      }
  }

  scanf("%d",&k);
  for (i=0; i<n; i++) {
      for (j=0; j<m; j++) {
          if (ramp[i][j]==0) {
             check_all_on=0;
             for (si=0; si<n; si++) {
                 for (sj=0; sj<m; sj++) {
                     copy.copyramp[si][sj]=ramp[si][sj];
                     if (ramp[si][sj]==1) 
                        copy.checkramp[si][sj]=1;
                     else 
                        copy.checkramp[si][sj]=0;
                 }
             }
             change_switch(n, m, k, copy);
          }
      }
  }

  if (check_all_on==1) {
     if (k%2==0) big=m+n;
     else if (k%2==1) big=m+n-2;
  }

  printf("%d\n", big); 
  
  system("PAUSE");	
  return 0;
}

void change_switch(int n, int m, int k, COPYS copy)
{
  int i, j, count;
  for (i=0; i<n; i++) {
     for (j=0; j<m; j++) {
         if (k!=0) {
            if (copy.copyramp[i][j]==0) {
               copy.copyramp[i][j]=1;
               copy.checkramp[i][i]=1;
            }
         }
     }
  }

  //return big;

}
