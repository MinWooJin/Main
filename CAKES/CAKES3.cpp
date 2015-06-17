// Sonny's solution to cakes
// Stanford Local Programming Contest, October 2007

#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdlib>

using namespace std;

const int limit = 40;
const int sentry = 0x7fffffff;

int main()
{
    int size = limit*30 + 4;
    char a[1204][1204];

    // read number of cakes
    int n;
    while (cin >> n)
    {
        if (n == 0) break;
        
        // read times to bake
        int t[limit], sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> t[i];
            sum += t[i];
        }

        
        // build the DP table, which contains possibles states of 2 ovens
        memset(a, 0, sizeof(char) * size * size);
        a[0][0] = 1;
        
        int sofar = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = sofar; j >= 0; --j)
                for (int k = sofar; k >= 0; --k)
                    if (a[j][k]) {
                        a[j+t[i]][k] = 1;
                        a[j][k+t[i]] = 1;
                    }
            sofar += t[i];
        }
        
        // search the DP table for the best answer
        int best = sentry;
        
        for (int i = 0; i <= sum; ++i)
            for (int j = i; j <= sum; ++j)
                if (a[i][j])
                    best = min(best, max(sum-i-j, max(i, j)));
                
        cout << best << endl;
    }

    return 0;
}

