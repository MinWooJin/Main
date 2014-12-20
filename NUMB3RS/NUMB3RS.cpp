#include <stdio.h>
#include <stdlib.h>

void main()
{
	int casenum, contrynum, daynum, startnum;
	int path[51][51], sumpath[51][51]={0};
	int resultnum[51], reconnum[51];
	int k, i, j, a, b, setcontry, countpath;
	float result[51][51];
	//scan and processing
	scanf("%d", &casenum);
	for(k=0; k<casenum; k++) {
		scanf("%d %d %d", &contrynum, &daynum, &startnum);
		for(i=0; i<contrynum; i++) {
			for(j=0; j<contrynum; j++) {
				scanf("%d", &path[i][j]);
			}
		}
		scanf("%d",&resultnum[k]);
		for(i=0; i<resultnum[k]; i++)
			scanf("%d", &reconnum[i]);
		setcontry = startnum;
		for(i=0; i<daynum; i++) {
			for(j=0; j<contrynum; j++) {
				countpath=0;
				for(a=0; a<contrynum; a++)
					if (path[j][a]==1)
						countpath++;
				for(a=0; a<contrynum; a++) {
					if(path[j][a]==1)
						sumpath[j][a]=countpath;
				}
			}
		}
		result[k][51];
	}

	for(k=0; k<casenum; k++) {
		for(i=0; i<resultnum[k]; i++) {
			printf("%.10f ", result[k][i]);
			if (i==resultnum[k]-1)
				printf("\n");
		}
	}

	system("pause");
}