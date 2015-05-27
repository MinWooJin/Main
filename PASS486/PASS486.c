#include <stdio.h>
#include <math.h>

void solve(int n, int lo, int hi);

int main() {
	int casenum, i, n, lo, hi;
	scanf("%d",&casenum);

	for(i=0; i<casenum; i++) {
		scanf("%d %d %d",&n,&lo,&hi);
		solve(n,lo,hi);
	}
	return 0;
}

void solve(int n, int lo, int hi) {
	int i,j,k,count,i_sqrt,result=0;
	for(i=lo; i<=hi; i++) {
		count=0;
		if(i==1) count=1;
		else {
			count=2;
			i_sqrt=(int)sqrt((double)i);
			for(j=2; j<=i_sqrt; j++) {
				if(i%j == 0)
					count +=2;
			}
			if(i==i_sqrt*i_sqrt) count--;
		}
		if(n==count)
			result++;
	}
	printf("%d\n",result);
}
