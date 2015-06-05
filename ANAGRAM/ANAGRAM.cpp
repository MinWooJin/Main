#include <cstdio>
#include <cstdlib>
#include <string.h>

int compare(const void *a, const void *b)
{
	return ( *(char *)a - *(char *)b );
}

int main()
{
	int testcase;
	scanf("%d",&testcase);
	while(testcase--)
	{
		char d1[101], d2[101];
		int check=0;
		scanf("%s",d1);
		getchar();
		scanf("%s",d2);
		if(strlen(d1) != strlen(d2)) check=1;
		else if(strcmp(d1,d2)==0) check=1;
		else
		{
			qsort(d1,strlen(d1),sizeof(char), compare);
			qsort(d2,strlen(d2),sizeof(char), compare);
			for(int i=0; i<strlen(d1); i++) {
				if(d1[i] != d2[i])
				{
				  	check=1; 
					break;
				}
			}
		}
		
		check == 0 ? printf("Yes\n") : printf("No.\n");
	}
	return 0;
}

