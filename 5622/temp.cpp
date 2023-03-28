#include <iostream>

using namespace std;

int main()
{
    char ch[16];
    char t;
    int arr[26] = {3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10};
    int sum = 0;

    while(cin.get(t))
    {
        if( t == '\n')
            break;

        sum += arr[int(t - 'A')];
    }

    cout << sum << endl;
    
    return 0;
}
