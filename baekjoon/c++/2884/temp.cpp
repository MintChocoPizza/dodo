#include <iostream>
#include <ostream>

using namespace std;

int main()
{
    int H, M;
    int temp;
    cin >> H >> M;
    temp = H*60 + M;

    temp -= 45;

    if(temp < 0 ){
        int day = (23*60) + 59;

        cout << day << endl;

        temp = day + temp + 1;

        cout << temp << endl;
    }

    cout << temp/60 << ' ' << temp%60 << endl;

    return 0;
}
