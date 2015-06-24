#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int N,M;
bool areFriends[10][10];

bool taken[10];

int countPairings()
{
	int child;
	for(child=0; child < N; child++)
	{
		if(!taken[child]) break;
	}

	if(child == N) return 1;
	
	int result = 0;

	taken[child] = true;
	for(int otherChild=0;otherChild < N;otherChild++)
	{
		if(!taken[otherChild] && areFriends[child][otherChild])
		{
			taken[otherChild] = true;
			result += countPairings();
			taken[otherChild] = false;
		}
	}
	taken[child] = false;
	return result;
}

int main()
{
	int testcase;
	scanf("%d",&testcase);

	while(testcase--)
	{
		scanf("%d%d",&N,&M);

		memset(areFriends, 0, sizeof(areFriends));
		memset(taken, 0, sizeof(taken));

		for(int i=0;i<M;i++)
		{
			int X,Y;
			scanf("%d%d",&X,&Y);
			areFriends[X][Y]=areFriends[Y][X]=true;
		}

		printf("%d\n",countPairings());
	}
	return 0;
}

