#include <stdio.h>
#include <stdlib.h>

int main() {

	int testcase, i, j, linenum, contisum, maxsum;
	int ary[1000];
	scanf("%d",&testcase);

	for(i=0; i<testcase; i++) {
		scanf("%d",&linenum);
		for(j=0; j<linenum; j++)
			scanf("%d",&ary[j]);
		contisum=0;
		if(ary[0]>0)
			maxsum=0;
		else
			maxsum=-1;
		for(j=0; j<linenum; j++) {
			if(ary[j] >= 0) {
				if(ary[j] == ary[j+1]-1 && ary[j+1] == ary[j+2]-1) {
					contisum=contisum+ary[j];
					if(maxsum < contisum)
						maxsum = contisum;
				}
				else if(ary[j] == ary[j+1]-1 ) {
					contisum=contisum+ary[j]+ary[j+1];
					if(maxsum < contisum)
						maxsum = contisum;
				}
			}
			else {
				if(ary[j]-1 == ary[j+1] && ary[j+1]-1 != ary[j+2]) {
					contisum=contisum+ary[j]+ary[j+1];
					if(maxsum < contisum)
						maxsum = contisum;
				}
				else if(ary[j]-1 == ary[j+1]) {
					contisum=contisum+ary[j];
					if(maxsum < contisum)
						maxsum = contisum;
				}
			}
		}
		printf("%d\n",maxsum);
	}

	system("pause");
	return 0;
}