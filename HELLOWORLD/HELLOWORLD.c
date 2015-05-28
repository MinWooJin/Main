#include <stdio.h>

int main() {
    int c, i;
    char input[51];
    
    scanf("%d",&c);
    
    for(i=0; i<c; i++)  {
             scanf("%s", input);
             printf("Hello, %s!\n",input);
    }

    return 0;
}
