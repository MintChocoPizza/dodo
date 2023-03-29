#include <iostream>

using namespace std;

int main()
{
    int N;
    int max=0;
    int i=0;
    int LR = -1;
    int a,b;

    cin >> N;
    
    while(N > max)
    {
        i++;
        max += i;
        LR *=-1;
    }

    a=i;
    b=1;

    while(max != N)
    {
        max--;
        a--;
        b++;
    }

    if(LR > 0)
    {
        cout << b << '/' << a;
    }
    else if(LR < 0)
    {
        cout << a << '/' << b;
    }

    return 0;
}


// 다양한 규칙들이 있음 
// 1. 대각선으로 보면 i번째 대각선은 i개의 요소가 있음, 이걸이용하면 위치 찾기 가능
