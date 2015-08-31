#include <cstdio>
#define M 200000000

int map[9][9]={ 
    { 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
{ 0, M, 37, 96,150, M, M, M, M}, 
{ 0, M, M, M, M,155, M, M, M}, 
{ 0, M, M, M, 39, 88,134, M, M}, 
{ 0, M, M, M, M, M,172, 42, M}, 
{ 0, M, M, M, M, M, M, M, M}, 
{ 0, M, M, M, M, M, M, M,114}, 
{ 0, M, M, M, M, M, M, M, M}, 
{ 0, M, M, M, M, M, M, M, M}}; 

/*
A : 1
B : 2
C : 3
D : 4
E : 5
F : 6
G : 7
H : 8
1 -> 2 : 37
1 -> 3 : 96
1 -> 4 : 150
2 -> 5 : 155
3 -> 4 : 39
3 -> 5 : 88
3 -> 6 : 134
4 -> 6 : 172
4 -> 7 : 42
6 -> 8 : 114
*/

int dis[9] = {0, 0, M, M, M, M, M, M, M}, pos, min;
bool check[9];

int main()
{
	for(int i=1; i<=8; i++) //node 수만큼 확정 
	{
		min = M;
		for(int j=1; j<=8; j++) 
		{
			if(!check[j] && dis[j] < min)
			{
				min = dis[j];
				pos = j;
			}
		}
		check[pos] = true;
		for(int j=1; j<=8; j++)
		{
			if(!check[j] && dis[j] > dis[pos] + map[pos][j])
				dis[j] = dis[pos] + map[pos][j];
		}
	}
	for(int i=1; i<=8; i++)
		printf(" 1 -> %d : %d\n",i,dis[i]);
	
	return 0;
}
