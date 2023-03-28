#include <iostream>

using namespace std;

int main()
{
    int arr[10] = {0,};
    char ch;
    while(cin.get(ch))
    {
        if(ch == '\n')
            break;

        arr[ch-'0']++;
    }

    for(int i=9; i>=0; i--)
    {
        while(arr[i]--)
            cout << i;
    }

    return 0;
}
