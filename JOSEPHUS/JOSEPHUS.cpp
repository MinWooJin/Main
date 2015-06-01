#include <cstdio>

void solve(int,int);
void init(int);

int check[1001];

int main() {
	int testcase;
	scanf("%d",&testcase);
	
	for(int i=0; i<testcase; i++) {
		int n, k;
		scanf("%d %d",&n,&k);
		init(n);
		solve(n,k);
	}
	return 0;
}

void init(int n) {
	for(int i=1; i<=n; i++) {
		check[i]=1;
	}
}

void solve(int n, int k) {
	int people=n;
	int i=1, s;
	while(people!=2) {		
		if(check[i]==1) {
			check[i]=0;
			people--;
			for(int j=1; j<=k; j++) {
				i=i%n;
				if(check[i+1]==0) {
					i++;
					j--;
				}
				else
					i++;
			}
		}
	}

	for(int j=1; j<=n; j++) {
		if(check[j]==1)
			printf("%d ",j);
	}
	printf("\n");
}
