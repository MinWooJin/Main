#include <stdio.h>
#include <malloc.h>

int main() {
	int i, j, k, m, n, testcase, temp, tempmath, arylen[51];
	int *input[51] = {0, }, *match[51], *result[51];
	for(i=0; i<51; i++) {
		input[i] = (int *)malloc(50001);
		result[i] = (int *)malloc(50001);
		match[i] = (int *)malloc(50001);
	}
	scanf("%d",&testcase);
	for(i=0; i<testcase; i++) {
		scanf("%d",&arylen[i]);
		for(j=0; j<arylen[i]; j++) {
			scanf("%d",&input[i][j]);
			match[i][j] = j;
		}
	}
	for(i=0; i<testcase; i++) {
		n=0;
		for(j=0; j<arylen[i]; j++) {
			temp = input[i][j];
			tempmath = match[i][j];
			for(k=0; k<temp; k++) {
				input[i][j-k] = input[i][j-k-1];
				match[i][j-k] = match[i][j-k-1];
			}
			input[i][j-temp] = temp;
			match[i][j-temp] = tempmath;
		}
		for(m=1; m<arylen[i]+1; m++) {
			temp = match[i][n];
			result[i][temp] = m;
			n++;
		}	
	}
	for(i=0; i<testcase; i++) {
		for(j=0; j<arylen[i]; j++)
			printf("%d ",result[i][j]);
		printf("\n");
	}

	for(i=0; i<51; i++) {
		free(input[i]);
		free(result[i]);
		free(match[i]);
	}
	
	return 0;
}
