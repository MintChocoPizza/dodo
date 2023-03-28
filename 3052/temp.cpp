#include <iostream>

using namespace std;

int main()
{
    int a;
    int count = 0;
    bool arr[42] = {0,};
    for(int i=0; i<10; i++)
    {
        cin >> a;
        a = a%42;
        if(!arr[a])
        {
            count++;
            arr[a] = true;
        }
    }

    cout << count << endl;
    return 0;
}
