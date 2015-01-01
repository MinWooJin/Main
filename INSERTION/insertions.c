#include <stdio.h>
#include <malloc.h>

int main() {
	int i, j, k, m, n, testcase, temp, tempmath, arylen;
	int input[500001] , match[500001], result[500001];
	scanf("%d",&testcase);
	for(i=0; i<testcase; i++) {
		scanf("%d",&arylen);
		for(j=0; j<arylen; j++) {
			scanf("%d",&input[j]);
			match[j] = j;
		}
		n=0;
		for(j=0; j<arylen; j++) {
			temp = input[j];
			tempmath = match[j];
			for(k=0; k<temp; k++) {
				input[j-k] = input[j-k-1];
				match[j-k] = match[j-k-1];
			}
			input[j-temp] = temp;
			match[j-temp] = tempmath;
		}
		for(m=1; m<arylen+1; m++) {
			temp = match[n];
			result[temp] = m;
			n++;
		}	
		for(j=0; j<arylen; j++)
			printf("%d ",result[j]);
		printf("\n");
	}
	
	return 0;
}
