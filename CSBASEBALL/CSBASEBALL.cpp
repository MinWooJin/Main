#include <cstdio>

int main() {
	int testcase;
	scanf("%d",&testcase);
	
	for(int i=0; i<testcase; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if(a<b)
			printf("%d\n",4+(b-a));
		else if(a>b)
			printf("0\n");
		else
			printf("4\n");
	}
	
	return 0;
}
