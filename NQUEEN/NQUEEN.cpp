#include <iostream> 
 
using namespace std; 
 
int N, result, queen[12]; 
 
void solve(int); 
bool available(int, int); 
 
int main() { 
    int testcase; 
    cin >> testcase; 
    for(int i=0; i<testcase; i++) {
        cin >> N; 
        result=0;
        solve(0);
        cout << result << endl; 
    }
    
    return 0; 
} 
 
void solve(int q) {
    if (q == N) { 
        result++; 
        return; 
    } 
 
    for (int i = 0; i < N; ++i) { 
        if (available(q, i)) { 
            queen[q] = i;
            solve(q + 1);
        } 
    } 
} 
 
bool available(int q, int col) { 
    for (int i = 0; i < q; i++) { 
        if (queen[i] == col) 
            return false; 
 
        if (q - i == abs(col - queen[i])) 
            return false; 
    } 
    return true; 
} 
 
