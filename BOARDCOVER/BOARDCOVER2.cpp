#include <cstdio>
#include <cstring>

int cover();
bool set(int, int, int, int);

const int coverType[4][3][2] = {
	{ { 0, 0}, { 1, 0}, { 0, 1} },
	{ { 0, 0}, { 0, 1}, { 1, 1} },
	{ { 0, 0}, { 1, 0}, { 1, 1} },
	{ { 0, 0}, { 1, 0}, { 1, -1} } };
int board[21][21];
int h, w;

int main()
{
	int testcase;
	scanf("%d",&testcase);
	
	while(testcase--)
	{
		scanf("%d %d", &h, &w);
		
		for(int i=0; i<h; i++)
		{
			char temp[21];
			scanf("%s",temp);
			for(int k=0; k<strlen(temp); k++)
				temp[k] == '#' ? board[i][k] = 1 : board[i][k] = 0;
		}
		printf("%d\n",cover());
	}
	return 0;
}

bool set(int y, int x, int type, int delta)
{
	bool ok = true;
	for(int i=0; i<3; i++)
	{
		const int ny = y + coverType[type][i][0];
		const int nx = x + coverType[type][i][1];
		if(ny < 0 || ny >= h*w || nx < 0 || nx >= w )
			ok = false;
		else if ((board[ny][nx] += delta) > 1)
			ok = false;
	}
	return ok;
}

int cover()
{
	int y=-1, x=-1;
	for(int i=0; i<h*w; i++)
	{
		for(int j=0; j<w; j++)
		{
			if(board[i][j] == 0)
			{
				y=i;
				x=j;
				break;
			}
		}
		if(y != -1) break;
	}
	
	if(y == -1) return 1;
	int ret = 0;
	bool s;
	for(int type=0; type<4; type++)
	{
		//덮을 수 있으면 재귀호출로 찾는다 
		if(set(y, x, type, 1))
			ret += cover();
		//덮었던 블록을 원상태로 
		s = set(y, x, type, -1);
	}
	return ret;
}
