#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <memory>

using namespace std;
int num;
bool root[101][101];
bool check[101];

void DFS(int now) {
    for(int i=1; i < now; i++) {
        if (root[now][i] == true && check[now] == false) {
            check[now] = true;
            DFS(i);
        }
    }
}
int main(int argc, char *argv[])
{
    //입력부분
    int num, cnum, count;
    int first, second;
    string str;
    while (cin >> num) {
        if (num == 0 || num < 0 || num > 100) break;
        getchar();
        while(getline(cin, str)) {
            stringstream s(str);
            s >> first;
            if (first == 0) break;
            while (s >> second) {
                if (second == 0) break;
                root[first][second] = true;
            }
        }
        cin >> cnum;
        for (int i=0; i < cnum; i++) {
            int c = 0;
            memset(check, false, sizeof(bool));
            cin >> c;
            DFS(c);
            for (int j = 1; j < 101; j++) {
                if (check[j] == true) count++;
        }
            
    }
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
