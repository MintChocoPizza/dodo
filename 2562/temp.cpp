#include <iostream>

using namespace std;

int main()
{
    int N, temp;
    int max=0, cnt;
    for(int i=1; i<=9; i++)
    {
        cin >> temp;
        if(max<temp)
        {
            cnt = i;
            max = temp;
        }
    }
    cout << max << endl << cnt << endl;

    return 0;
}
