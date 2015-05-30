#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int solve(int n, int a, int b);

int main() {
	int tcase;
	int n, a, b;
	scanf("%d",&tcase);
	for(int i=0; i<tcase; i++) {
		scanf("%d %d %d",&n,&a,&b);
		printf("%d\n",solve(n-1,a,b));
	}
	return 0;
}

int solve(int n, int a, int b) {
	int m = 1983, base = 1983, def, tmp;
	int rsum = 1983;

	priority_queue<int, vector<int>, less<int> > left;
	priority_queue<int, vector<int>, greater<int> > right;

	for(int i=0; i<n; i++) {
		base = (static_cast<long long>(base) * a + b) % 20090711;
		if(base > m) right.push(base);
		else left.push(base);
		def = left.size() - right.size();
		while (def != 0 && def != -1) {
			if (def > 0) {
				right.push(m);
				m = left.top();
				left.pop();
			}
			else {
				left.push(m);
				m = right.top();
				right.pop();
			}
			def = left.size() - right.size();
		}
		rsum = (rsum + m) % 20090711;
	}
	return rsum;
}
