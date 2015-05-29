#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int p;
	int q;
} Data;

int main() {
	int casenum, pnum, sum, people, i, j, k, check, subnum;

	scanf("%d",&casenum);

	for(i=0; i<casenum; i++) {
		scanf("%d",&pnum);
		Data *data = (Data*)malloc(sizeof(Data)*pnum);

		for(j=0; j<pnum; j++) {
			scanf("%d %d",&data[j].p,&data[j].q);

			if(j==0) {
				people=1;
				sum=1;
			}
			else {
				subnum=0;
				check=0;
				for(k=0; k<j; k++) {
					if(data[k].p == -1 && data[k].q == -1);
					else {
						if(data[j].p > data[k].p && data[j].q > data[k].q) {
							data[k].p=data[k].q=-1;
							check=0;
							subnum++;
						}
						else if(data[j].p < data[k].p && data[j].q < data[k].q) {
							check=1;
							break;
						}
						else
							check=2;
					}
				}
				if(check==0 || subnum!=0) {
					people = people -  subnum + 1;
					sum += people;
				}
				else if(check==1) {
					data[j].p=data[j].q=-1;
					sum += people;
				}
				else  {
					data[j] = data[j];
					people++;
					sum += people;
				}
			}
		}
		free(data);
		printf("%d\n",sum);
	}
	return 0;
}
