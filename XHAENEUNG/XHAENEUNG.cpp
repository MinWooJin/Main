#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string.h>
using namespace std;

int compare (const void * a, const void * b)
{
	return ( *(char*)a - *(char*)b);
}
int sttoint(string);
void init();
int solve(string);

char data[11][6] = {"zero", "one", "two", "three", "four",
	"five", "six", "seven", "eight", "nine", "ten"};

int main()
{
	int testcase;
	scanf("%d",&testcase);
	
	while(testcase--)
	{
		string s1, s2, s3;
		char operation, eq;
		int d1, d2, d3, result;
		cin >> s1 >> operation >> s2 >> eq >> s3;
		d1 = sttoint(s1);
		d2 = sttoint(s2);
		d3 = sttoint(s3);
		init();
		switch(operation)
		{
			case '+' :
				result = d1 + d2;
				break;
			case '-' :
				result = d1 - d2;
				break;
			case '*' :
				result = d1 * d2;
				break;
		}
		if(result < 0) printf("No\n");
		else if(result > 10) printf("No\n");
		else if(result == d3) printf("Yes\n");
		else
		{
			int check = solve(s3);
			check == result ? printf("Yes\n") : printf("No\n");
		}
	}
	
	return 0;
}

void init()
{
	for(int i=0; i<11; i++)
		qsort(data[i], strlen(data[i]), sizeof(char), compare);
}

int solve(string s)
{
	char temp[6];
	for(int i=0; i<s.length()+1; i++)
		temp[i] = s[i];
	qsort(temp, strlen(temp), sizeof(char), compare);
	for(int i=0; i<11; i++)
	{
		if(strcmp(data[i],temp)==0) return i;
	}
	return 99;
}

int sttoint(string s)
{
	if(s.compare("zero") == 0) return 0;
	else if(s.compare("one") == 0) return 1;
	else if(s.compare("two") == 0) return 2;
	else if(s.compare("three") == 0) return 3;
	else if(s.compare("four") == 0) return 4;
	else if(s.compare("five") == 0) return 5;
	else if(s.compare("six") == 0) return 6;
	else if(s.compare("seven") == 0) return 7;
	else if(s.compare("eight") == 0) return 8;
	else if(s.compare("nine") == 0) return 9;
	else if(s.compare("ten") == 0) return 10;
	else return 99;
}
