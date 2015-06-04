#include <cstdio>

int main() {
	int testcase;
	scanf("%d",&testcase);
	
	while(testcase--) {
		int n,l, sum, count;
		int data[1000];
		double result=0, mid;
		
		scanf("%d %d",&n,&l);
		for(int i=0; i<n; i++) scanf("%d",&data[i]);
		if(n==l)
		{
			sum=0;
			for(int i=0; i<n; i++)
			{
				sum+=data[i];
				result = (double)sum/l;
			}
		}
		else
		{
			result = (double)1001;
			for(int i=0; i<=n-l; i++)
			{
				int j;
				sum=data[i];
				count=1;
			
				for(j=i+1; j<=l+i-1; j++)
				{
					sum+=data[j];
					count++;
				}
				mid = (double)sum/count;
				mid < result ? result = mid : result = result;
				for(int j=l+i; j<n; j++)
				{
					sum+=data[j];
					count++;
					mid = (double)sum/count;
					mid < result ? result = mid : result = result;
				}
			}
		}
		printf("%.12lf\n",result);
	}
	return 0;
}
