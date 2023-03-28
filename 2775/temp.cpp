#include <iostream>

using namespace std;

int func(int k, int n)
{
    if(k<0 || n<1)
        return 0;
    if(!k)
        return n;

    return func(k-1, n) + func(k, n-1);
}

int main()
{
    int T;
    int k, n;

    cin >> T;

    while(T--)
    {
        cin >> k >> n;
        cout << func(k,n) << endl;
    }

    return 0;
}


// other.cpp를 보면 알겠지만 재귀함수의 경우 위에서 부터 아래로 내려가고, 반복문으로 구현할 경우 아래서 부터 위로 올라감;
