#include <iostream>
#include <string>

using namespace std;

string input;

int comp(int a, int b)
{
 	if(input[a] > input[b])
 		return 1;
 	else if(input[a] < input[b])
 		return 0;
 	else
 	{
 		if(input[a + 1] > input[b + 1])
 			return 1;
 		else if(input[a + 1] < input[b + 1])
 			return 0;
 		else
 			return 0;
 	}
 }

void swap(int a, int b)
{
 	char temp;
	temp = input[a];
	input[a] = input[b];
	input[b] = temp;
}

void sort(string input)
{
 	int length = input.length() / 2;
 	int i, j;
	for(i = 2 * (length - 1) ; i > 0 ; i -= 2)
	{
    	for(j = 0 ; j < i ; j += 2)
    	{
        	if(comp(j, j + 2) == 1)
        	{
            	swap(j, j + 2);
            	swap(j + 1, j + 3);
        	}
    	}
	}
}

int main()
{
	int testcase;
	cin>>testcase;

	while(testcase--)
	{
    	cin>>input;
    	sort(input);
    	cout << input << endl;
	}
	return 0;

}
