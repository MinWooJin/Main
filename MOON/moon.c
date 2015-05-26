#include <stdio.h>
#include <math.h>

double pi = acos(-1.0);

double prun(int m, int s, int c);
	

int main() {
	int testcase, m, s, c, i;
	double cir, le, ri;

	scanf("%d",&testcase);
	for(i=0; i<testcase; i++) {
		scanf("%d %d %d",&m,&s,&c);
		
		cir = pi * m * m;
		le = prun(m, s, c);
		ri = prun(s, m, c);

		printf("%.3f\n", cir - le - ri);
	}
		
	return 0;
}

double prun(int m, int s, int c) {
	double x = (m*m + c*c - s*s) / 2.0 / c;
	double y = sqrt(fabs(m*m - x*x));
	double z = 2.0 * acos(x / m);

	double cir = pi * m * m;
	double arh = cir * z / 2 / pi;
	double triangle = x*y;

	return arh - triangle;
}


