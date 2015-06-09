#include <cstdio>

int main()
{
	int testcase;
	scanf("%d",&testcase);
	while(testcase--)
	{
		int data[500];
		int check[500];
		int n, count, result = 0;
		scanf("%d",&n);
		for(int i=0; i<n; i++)
		{
			scanf("%d",&data[i]);
		}
		for(int i = 0; i < n; i++) {
            check[i] = 1;
            for (int j = 0; j < i; j++) {
                if (data[j] < data[i] && check[i] < check[j] + 1)
                    check[i] = check[j] + 1;
            }
        }
        for(int i = 0; i < n; i++) {
                if (result< check[i])
                    result = check[i];
        }
		printf("%d\n",result);
	}
	return 0;
}
