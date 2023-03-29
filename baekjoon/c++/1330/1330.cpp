#include <iostream>

using namespace std;

int main()
{
    int A, B;
    string temp;

    cin >> A >> B;

    temp = A==B? "==" : (A>B? ">":"<");

    cout << temp << endl;

    return 0;
}
