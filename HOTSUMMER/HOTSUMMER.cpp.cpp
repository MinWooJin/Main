#include <cstdio>

int main() {
	int testcase;
	scanf("%d",&testcase);
	
	for(int i=0; i<testcase; i++) {
		int w, wi, sum=0;
		scanf("%d",&w);
		for(int j=0; j<9; j++) {
			scanf("%d",&wi);
			sum += wi;
		}
		sum <= w ? printf("YES\n") : printf("NO\n");
	}
	return 0;
}
