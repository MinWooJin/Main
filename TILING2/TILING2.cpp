#include <cstdio>

#define DIV 1000000007

int main() {
	int testcase, n;
	int data[3];
	scanf("%d",&testcase);
	
	for(int i=0; i<testcase; i++) {
		scanf("%d",&n);
		
		data[0]=data[1]=data[2]=1;
		
		for(int j=0; j<n-1; j++) {
			data[0] = data[1];
			data[1] = data[2];
			data[2] = ((data[1]%DIV) + (data[0]%DIV))%DIV;
		}
		
		printf("%d\n",data[2]);
	}
	
	return 0;
}
