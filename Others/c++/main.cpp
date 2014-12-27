#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    string name;
    cin >> name;
    
    string greeting = "Hello " + name + "!";
    string space (greeting.size(), ' ');
    string first (space.size()+2, '*');
    
    cout << endl;
    cout << first << endl;
    cout << "*" << space << "*" << endl;
    cout << "*" << greeting << "*" << endl;
    cout << "*" << space << "*" << endl;
    cout << first << endl;
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
