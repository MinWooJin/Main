#include <iostream>
#include <string.h>
#include <sstream>

using namespace std;

string int2str(int);
bool possible(int);

int main() {
	int n, num, count, result;
	
	for(;;) {
		cin>>n;
		if(n==0) break;
		else {
			num=1;
			count = 0;
			for(;;) {
				if(count == n) {
					cout << result << endl;
					break;
				}
				else {
					if(possible(num)) {
						result=num;
						num++;
						count++;
					}
					else {
						num++;
					}
				}
			}
		}
	}
	
	return 0;
}

bool possible(int n) {
	string s = int2str(n);
	int size = s.length();
	for(int i=0; i<size; i++) {
		for(int j=i-1; j>=0; j--) {
			if(s[i]==s[j]) return false;
		}
	}
	return true;
}

string int2str(int n) {
	stringstream ss;
	ss << n;
	return ss.str();
}
