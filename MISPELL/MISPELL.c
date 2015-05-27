#include <stdio.h>
#include <string.h>

int main() {
    int number, delnum, i, j, k;
    char data[1000][80], result[1000][80];
    
    scanf("%d",&number);
    
    for(i=0; i<number; i++) {
             k=0;
             scanf("%d %s", &delnum, data[i]);
             for(j=0; j<strlen(data[i]); j++) {
                      if(j==delnum-1);
                      else {
                           result[i][k] = data[i][j];
                           k++;
                      }
             }
             printf("%d %s\n",i+1,result[i]);
    }
    return 0;
}
