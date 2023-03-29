#include <iostream>

using namespace std;

int main()
{
    int X, N, a, b;
    int temp = 0;
    cin >> X >> N;
    while(N--)
    {
        cin >> a >> b;
        temp += a*b;
    }
    if(temp == X) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
