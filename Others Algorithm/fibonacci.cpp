#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

int fibo(int);
int dpfibo(int);

int resul[100];

int main()
{
	memset(resul, 0, sizeof(resul));
	
	printf("fibo = %d\n",fibo(40));
	printf("dpfibo = %d\n",dpfibo(40));
	return 0;
}

int fibo(int k)
{
	if(k < 2) return 1;
	else return fibo(k-1) + fibo(k-2);
}

int dpfibo(int k)
{
	if(resul[k] != 0)	return resul[k];
	
	if(k < 2) return resul[k] = 1;
	else
		return resul[k] = dpfibo(k-1) + dpfibo(k-2);

}
