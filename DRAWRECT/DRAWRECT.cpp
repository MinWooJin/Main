#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    for(int i=0; i<t; i++) {
            int c[4], ccheck1, ccheck2, cnum1=1, cnum2=0;
            int l[4], lcheck1, lcheck2, lnum1=1, lnum2=0;
            for(int j=0; j<3; j++)
              cin >> c[j] >> l[j];
            ccheck1 = c[0];
            lcheck1 = l[0];
            for(int j=1; j<3; j++) {
                    ccheck1 == c[j] ? cnum1 ++ : (ccheck2 = c[j], cnum2++);
                    lcheck1 == l[j] ? lnum1 ++ : (lcheck2 = l[j], lnum2++);
            }
            int cresult, lresult;
            cnum1 > cnum2 ? cresult = ccheck2 : cresult = ccheck1;
            lnum1 > lnum2 ? lresult = lcheck2 : lresult = lcheck1;

            cout << cresult << " " << lresult << endl;               
    }

    return 0;
}
