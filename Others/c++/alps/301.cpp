#include <iostream>
#include <memory.h>
using namespace std;

int station[8];

typedef struct order{
	int from;
	int to;
	int passenger;
	int price;
}order;

order T[22];
int n, m, r;
int _max;

bool isAbleToAccept(int i)
{
	for(int j = T[i].from; j<T[i].to; j++)
		if(station[j] + T[i].passenger > n) return false;
	return true;
}

void Accumulate(int i)
{
	for(int j = T[i].from; j<T[i].to; j++)
		station[j] = station[j] + T[i].passenger;
}
void Decumulate(int i)
{
	for(int j = T[i].from; j<T[i].to; j++)
		station[j] = station[j] - T[i].passenger;
}

void DFS(int i, int total)
{
	if(i == r){
		_max = max(_max, total);
		return;
	}

	//i번째 티켓에 대해서
	//수용 가능한 경우
	if(isAbleToAccept(i)){
		Accumulate(i);
		DFS(i+1, total + T[i].price);
		Decumulate(i);
	}

	//수용하지 않는 경우
	DFS(i+1, total);
}

int main()
{
	while(cin>>n>>m>>r)
	{
		if(n+m+r == 0) return 0;
		for(int i = 0; i < r; i++){
			cin>>T[i].from>>T[i].to>>T[i].passenger;
			T[i].price = (T[i].to - T[i].from)*T[i].passenger;
		}
		_max = 0;
		memset(station, 0, sizeof(station));
		DFS(0, 0);
		cout<<_max<<endl;
	}
	return 0;
}