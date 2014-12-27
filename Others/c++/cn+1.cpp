#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int start = 0, end = 0;
    int temp = 0, num = 0;
    int maximumln = 0, cycleln;
    
    cin >> start >> end;
    if (start < 0 | start > 10000 | end < 0 | end > 10000) {
        cout << "Error!" << endl;
        exit(1);
    }
    //Input 조건에 의해서 0보다 크고 10000보다 작은값만 받는다.
     
    cout << start << " " << end << " ";
    //Input을 출력한다.
     
    if (start > end) {
        temp = start;
        start = end;
        end = temp;
    }
    //작은 수 부터 큰 순서대로 구해야 하기 때문에 순서를 확인한다.
     
    for(int i = start; i <= end; i++) {
        num = i;
        cycleln = 1; //num의 cycleln을 구할때 처음 값을 포함해준다. 따라서 +1.
        while(num != 1) {
            if (num % 2 == 1) {
                num = 3*num+1;
                cycleln++;
            }
            else {
                num = num/2;
                cycleln++;
            }
        }
        //num값이 1이 될때까지 cycleln을 ++ 시킨다. 
        
        if (maximumln < cycleln) maximumln = cycleln;
        //가장 큰 cycleln값을 찾는다. 
    }
    
    cout << maximumln << endl; //가장 큰 cycleln값 출력. 
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
