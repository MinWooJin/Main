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
    //Input ���ǿ� ���ؼ� 0���� ũ�� 10000���� �������� �޴´�.
     
    cout << start << " " << end << " ";
    //Input�� ����Ѵ�.
     
    if (start > end) {
        temp = start;
        start = end;
        end = temp;
    }
    //���� �� ���� ū ������� ���ؾ� �ϱ� ������ ������ Ȯ���Ѵ�.
     
    for(int i = start; i <= end; i++) {
        num = i;
        cycleln = 1; //num�� cycleln�� ���Ҷ� ó�� ���� �������ش�. ���� +1.
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
        //num���� 1�� �ɶ����� cycleln�� ++ ��Ų��. 
        
        if (maximumln < cycleln) maximumln = cycleln;
        //���� ū cycleln���� ã�´�. 
    }
    
    cout << maximumln << endl; //���� ū cycleln�� ���. 
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
