#include <iostream>

using namespace std;

int main()
{
    int T;
    char ch[1001];
    cin >> T;
    while(T--)
    {
        cin >> ch;
        int cnt = 0;
        while(ch[cnt++])
        {
        }
        cout << ch[0] << ch[cnt-2] << endl;
    }
    return 0;
}
