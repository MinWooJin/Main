#include <cstdio>

char data[1000001];
int check[1000001];

int main() {
	char chval;
	int testcase, num;
	
	scanf("%s",data);
	scanf("%d",&testcase);
	
	for(int i=0; i<1000000; i++) {
		if(data[i]==NULL) break;
		
		if(data[i] != chval) {
			chval=data[i];
			num++;
		}
		
		check[i] = num;
	}
	
	for(int i=0; i<testcase; i++) {
		int n1, n2, tmp, result;
		scanf("%d %d",&n1,&n2);
		
		check[n1] == check[n2] ? printf("Yes\n") : printf("No\n");
	}
	return 0;
}
