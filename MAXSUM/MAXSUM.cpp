#include <iostream>

using namespace std;

int main() {
	int sum, n, max, input;
	int testcase;
	cin>>testcase;
	
	for(int i=0; i<testcase; i++) {
		sum=0;
		max=0;
		cin>>n;

		for(int j=0; j<n; j++) {
			cin>>input;
			
			if(sum>0)
				sum+=input;
			else
				sum=input;
			if(max < sum)
				max = sum;
		}

		cout << max << endl;

	}
	return 0;
}
