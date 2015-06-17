//check에 세개씩 넣어서 줄여가면서 count
//queue가 empty면 끝, 입력 3개 아래면 출력하고 끝 
#include <cstdio>
#include <queue>

using namespace std;

int n, result;
int check[3];
priority_queue<int, vector<int>, less<int> > q;

void solve();
int chfull();

int main()
{
	for(;;)
	{
		for(int i=0; i<3; i++)
			check[i] = 1;
		scanf("%d",&n);
		if(n==0) break;
		else if(n==1)
		{
			int tmp;
			scanf("%d",&tmp);
			printf("%d\n",tmp);
		}
		else if(n==2)
		{
			int tmp1, tmp2;
			scanf("%d %d",&tmp1,&tmp2);
			tmp1 > tmp2 ? printf("%d\n",tmp1) : printf("%d\n",tmp2);
		}
		else
		{
			for(int i=0; i<n; i++)
			{
				int tmp;
				scanf("%d",&tmp);
				q.push(tmp);
			}
			n == 3 ? result = 0 : result = 1;
			solve();
		}
	}
	return 0;
}

int chfull()
{
	for(int i=0; i<3; i++)
	{
		if(q.empty()) return 0;
		else if(check[i] == 1)
		{
			int top = q.top();
			check[i] = top;
			q.pop();
			if(q.empty()) return 0;
		}
	}
	return 1;
}

void solve()
{
	int checkempty;
	for(;;)
	{
		checkempty = chfull();
		if(checkempty == 0) break;
		else {
			for(int i=0; i<3; i++)
			{
				check[i]--;
			}
		}
		result++;
	}
	int maxch = check[0];
	for(int i=1; i<3; i++)
		check[i] > maxch ? maxch = check[i] : maxch = maxch;
	printf("%d\n",result + maxch);
}
