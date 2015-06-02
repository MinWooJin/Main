#include <cstdio>

int main() {
	int testcase;
	scanf("%d",&testcase);
	
	for(int i=0; i<testcase; i++) {
		int num, check, result=0;
		int data[12];
		scanf("%d",&num);
		for(int j=0; j<num; j++) {
			scanf("%d",&check);
			if(check==j+1)
				result++;
		}
		printf("%d\n",result);
	}
	return 0;
}
