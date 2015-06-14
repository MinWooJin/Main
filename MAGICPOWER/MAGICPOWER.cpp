#include <cstdio>
#include <queue>

using namespace std;

int main()
{
	int testcase;
	scanf("%d",&testcase);
	
	while(testcase--)
	{
		int n, m, result=0;
		priority_queue<int, vector<int>, less<int> > q;
		scanf("%d %d", &n, &m);
		
		for(int i=0; i<n; i++)
		{
			int a;
			scanf("%d",&a);
			q.push(a);
		}
		for(int i=0; i<m; i++)
		{
			int temp = q.top();
			result+=temp;
			q.pop();
			if(temp > 0)
				q.push(temp-1);
		}
		printf("%d\n",result);
	}
	return 0;
}
