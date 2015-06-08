#include <cstdio>
#include <cstdlib>
#include <math.h>

using namespace std;

unsigned int seed;
int signal();

int main()
{
	int testcase;
	scanf("%d",&testcase);
	
	while(testcase--)
	{
		unsigned int k, n;
		seed = 1983;
		int sum, count = 0;
		scanf("%d %d", &k, &n);
		int *data = (int *)malloc(sizeof (int)*5000001);
		for(int i=0; i<n; i++)
		{
			data[i] = signal();
		}
		for(int i=0; i<n; i++)
		{
			sum = data[i];
			if(sum == k) count++;
			else {	
				for(int j=i+1; j<n; j++)
				{
					sum+=data[j];
					if(sum == k) {
						count++;
						break;
					}
				}
			}
		}
		printf("%d\n",count);
		free(data);
	}
	return 0;
}

int signal()
{
	unsigned int ret = seed;
	seed = (seed * 214013u) + 2531011u;
	return (ret%10000 + 1);
}
