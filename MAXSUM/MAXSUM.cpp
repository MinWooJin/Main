#include <stdio.h>
#include <stdlib.h>

int main() {

	int testcase, i, j, linenum[100], contisum, maxsum[100];
	int ary[100][1000];
	scanf("%d",&testcase);

	for(i=0; i<testcase; i++) {
		scanf("%d",&linenum[i]);
		for(j=0; j<linenum[i]; j++)
			scanf("%d",&ary[i][j]);
	}

	for(i=0; i<testcase; i++) {
		contisum=0;
		if(ary[i][0]>0)
			maxsum[i]=0;
		else
			maxsum[i]=-1;
		for(j=0; j<linenum[i]; j++) {
			if(ary[i][j] >= 0) {
				if(ary[i][j] == ary[i][j+1]-1 && ary[i][j+1] == ary[i][j+2]-1) {
					contisum=contisum+ary[i][j];
					if(maxsum[i] < contisum)
						maxsum[i] = contisum;
				}
				else if(ary[i][j] == ary[i][j+1]-1 ) {
					contisum=contisum+ary[i][j]+ary[i][j+1];
					if(maxsum[i] < contisum)
						maxsum[i] = contisum;
				}
			}
			else {
				if(ary[i][j]-1 == ary[i][j+1] && ary[i][j+1]-1 != ary[i][j+2]) {
					contisum=contisum+ary[i][j]+ary[i][j+1];
					if(maxsum[i] < contisum)
						maxsum[i] = contisum;
				}
				else if(ary[i][j]-1 == ary[i][j+1]) {
					contisum=contisum+ary[i][j];
					if(maxsum[i] < contisum)
						maxsum[i] = contisum;
				}
			}
		}
	}
	for(i=0; i<testcase; i++)
		printf("%d\n",maxsum[i]);

	system("pause");
	return 0;
}