#include <stdio.h>
#include <string.h>
#define max(a,b) a > b ? a : b

int tsize, input[101][101], maxch[101][101];

int msum (int y, int x) {
	if(y==tsize-1) return input[y][x];
	int& ret = maxch[y][x];
	if(ret != -1) return ret;
	return ret = (max(msum(y+1,x), msum(y+1,x+1)))+input[y][x];
}
int main(){
	int testcase, i, j, k;
	scanf("%d",&testcase);
	for(i=0; i<testcase; i++) {
		memset(maxch, -1, sizeof(maxch));
		scanf("%d",&tsize);
		for(j=0; j<tsize; j++)
			for(k=0; k<=j; k++) 
				scanf("%d",&input[j][k]);
		printf("%d\n",msum(0,0));
	}
	return 0;
}
