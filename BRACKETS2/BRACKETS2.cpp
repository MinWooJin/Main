#include <cstdio>
#include <string.h>

int main()
{
	int testcase;
	scanf("%d",&testcase);
	
	while(testcase--)
	{
		char data[10000];
		char lastch[10000];
		int open=0, close=0, ord=0;
		int brk = 0;
		scanf("%s",data);
		
		for(int i=0; i < strlen(data); i++)
		{
			if(brk == 1)
				break;
			else {
				switch(data[i]) {
					case 40 : // "("
						lastch[ord] = '(';
						ord++;
						open++;
						break;
					case 41 : // ")"
						ord--;
						if(lastch[ord] == '(')
						{
							close++;
						}
						else
							brk=1;
						break;
					case 123 : // "{"
						lastch[ord] = '{';
						ord++;
						open++;
						break;
					case 125 : // "}"
						ord--;
						if(lastch[ord] == '{')
						{
							close++;
						}
						else
							brk=1;
						break;
					case 91 : // "["
						lastch[ord] = '[';
						ord++;
						open++;
						break;
					case 93 : // "]"
						ord--;
						if(lastch[ord] == '[')
						{
							close++;
						}
						else
							brk=1;
						break;
				}
			}
		}
		brk == 0 && (open - close) == 0 ? printf("YES\n") : printf("NO\n");
	}
	return 0;
}
