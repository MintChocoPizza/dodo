#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int N;
    int a;
    int cnt=0;
    bool arr[1001] = {1,1,0,};

    cin >> N;

    for(int i=2; i<=sqrt(1000); i++)
    {
        if(!arr[i])
        {
           // i보다 작은 배수는 전단계 i가 해결해줌
            // j+=i: i 곱하기
            for(int j=i*i; j<=1000; j+=i)
            {
                arr[j]=true;
            }
        }
    }

    while (N--) 
    {
        cin >> a;
        if(!arr[a])
            cnt++;
    }

    cout << cnt;

    return 0;
}
