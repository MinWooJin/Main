#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <iomanip>
 
using namespace std;

double grade(double mid, double final, double homework)
{
       return 0.2*mid + 0.4*final + 0.4*homework;
}

double median(vector<double> vec)
{
       typedef vector<double>::size_type vec_sz;
       
       vec_sz size = vec.size();
       if(size==0)
            throw domain_error("ㅠㅠ");
       
       sort(vec.begin(), vec.end());
       
       vec_sz mid = size/2;
       
       return size%2 == 0 ? (vec[mid]+vec[mid+1])/2 : vec[mid];
}

double grade(double mid, double final, const vector<double>& hw)
{
       if(hw.size() == 0)
                    throw domain_error("ㅠㅠ");
       return grade(mid,final,median(hw));
}

istream& read_hw(istream& in, vector<double>& hw)
{
         if (in) {
                 hw.clear();
                 double x;
                 while (in >> x)
                       hw.push_back(x);
                 in.clear();
                 }
         return in;
}
         

int main(int argc, char *argv[])
{
    double mid, final;
    cout<<"중간 기말 입력"<<endl; 
    cin >> mid >> final;
    
    vector<double> homework;
    cout<<"숙제 입력"<<endl; 
    read_hw(cin, homework);
    
    try {
        double final_grade = grade(mid, final, homework);
        
        cout<<"Your grade is " 
            << final_grade  << endl;
    } catch (domain_error) {
            cout<<endl<<"ㅠㅠ"<<endl;
            return 1;
    } 
    system("PAUSE");
    return EXIT_SUCCESS;
}
