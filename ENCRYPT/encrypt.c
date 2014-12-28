#include <stdio.h>
#include <string.h>

int main() {
	char input[10][101]={{0, }, }, result[10][101]={{0, }, };
	int testcase, i, j, k;
	
	scanf("%d",&testcase);
	for(i=0; i<testcase; i++)
		scanf("%s",&input[i][0]);
	for(i=0; i<testcase; i++) {
		k=0;
		for(j=0; j<strlen(input[i]); j++) {
			if (j%2 == 0) {
				result[i][k] = input[i][j];
				k++;
			}
		}
		for(j=0; j<strlen(input[i]); j++) {
			if (j%2 == 1) {
				result[i][k] = input[i][j];
				k++;
			}
		}
	}
	for(i=0; i<testcase; i++) 
		printf("%s\n",result[i]);

	return 0;
}
