#include <stdio.h>

typedef struct {
	int cost;
	int save;
} Book;

int main() {
	Book data[200][100];
	Book temp;
	int casenum, n, m, i, j, k, l;
	int totalcost, totalsave, result, minsave;

	scanf("%d",&casenum);

	for(i=0; i<casenum; i++) {
		result=10001*200;
		scanf("%d %d",&n,&m);

		for(j=0; j<n; j++)
			for(k=0; k<m; k++)
				scanf("%d %d",&data[j][k].cost,&data[j][k].save);

		//bubble sort by save
		for(k=0; k<m; k++) {
			for(j=0; j<n; j++) {
				for(l=0; l<n-1-j; l++) {
					if(data[l][k].save < data[l+1][k].save) {
						temp = data[l+1][k];
						data[l+1][k] = data[l][k];
						data[l][k] = temp;
					}
				}
			}
		}

		for(k=0; k<m; k++) {
			totalcost = 0;
			totalsave = 0;
			for(j=0; j<n; j++) {
				if(totalsave < data[j][k].cost) {
					totalcost = totalcost + data[j][k].cost - totalsave;
					totalsave = 0;
				}
				else {
					totalsave = totalsave - data[j][k].cost;
				}
				totalsave = totalsave + data[j][k].save;
			}
			if(result > totalcost)
				result = totalcost;
		}
		printf("%d\n",result);
	}
	return 0;
}
