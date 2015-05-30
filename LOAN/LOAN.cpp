#include <cstdio>
#include <limits>

using namespace std;

int m;
double n, p;

bool possible(double value) {
	double c=n;
	const double rate = 1.0 + (p/12*0.01);
	for(int i=0; i<m; i++) {
		c = c*rate;
		c -= value;
		if(c <= 0.0) return true;
	}
	return false;
}

void solve() {
	double low(0.0), high(n + (n*(p/12)*0.01)), mid;

	int limit = 100;
	while(limit --> 0) {
		mid = (high + low) / 2;
		if(possible(mid)) {
			high = mid;
		}
		else {
			low = mid;
		}
	}

	printf("%.10f\n",high);
}

int main() {
	int testcase;

	scanf("%d",&testcase);
	for(int i=0; i<testcase; i++) {
		scanf("%lf %d %lf",&n,&m,&p);
		solve();
	}
	return 0;
}
