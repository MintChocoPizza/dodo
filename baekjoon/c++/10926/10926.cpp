#include <iostream>
#include <string>

using namespace std;

int main()
{
    string id;
    string str = "\?\?!\n";
    
    cin >> id;
    id.append(str);
    cout << id << endl;
    
    return 0;
}
