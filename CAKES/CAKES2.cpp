#include <iostream>
#include <vector>

using namespace std;
const int kUb = 500;

int main () {
  int n, t;
  while ((cin >> n) && (n != 0)) {
    int total = 0;
    vector<vector<bool> > possible(kUb+1, vector<bool>(kUb+1, false));
    possible[0][0] = true;

    for (int i = 0; i < n; i++) {
      cin >> t;
      total += t;
      for (int j = kUb; j >= 0; j--)
      for (int k = kUb; k >= 0; k--) {
        if (j >= t && possible[j-t][k]) possible[j][k] = true;
        if (k >= t && possible[j][k-t]) possible[j][k] = true;
      }
    }

    int best = 10000;
    for (int j = 0; j <= kUb; j++)
    for (int k = 0; k <= kUb; k++)
    if (possible[j][k])
      best = min(best, max(j, max(k, total - j - k)));
    cout << best << endl;
  }
  return 0;
}
