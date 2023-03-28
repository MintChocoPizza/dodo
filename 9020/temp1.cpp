#include <iostream>

using namespace std;

int arr[10001];

int main()
{
    int T;

    for(int i=0; i<10001; i++)
        arr[i] = i;
    for(int i=2; i*i<=10000; i++)
    {
        if(arr[i])
        {
            for(int j=i*i; j<=10000; j+=i)
            {
                arr[j] = 0;
            }
        }
    }

    cin >> T;
    while(T--)
    {
        int n;
        int min = 10000;
        int a,b;
        cin >> n;
        
        for(int i=2; i<=n/2+1;i++)
        {
            if(arr[i] && arr[n-i])
            {
                if(arr[n-i]-arr[i]>=0 && min> arr[n-i]-arr[i])
                {
                    a = arr[i];
                    b = arr[n-i];
                    min = arr[n-i]-arr[i];
                }
            }
        }
        cout << a << " " << b << endl;
    }
    return 0;
}


// 맞았음... 생각은 똑같은데 
// 스파케티코드, 개발 세발 잔 코드는 좋지 않음....
// 좀 중복되더라도 깔끔한 코드
//
//
//
// 더 좋은 방법은 n/2-i 와 n/2+i의 합은 언제나 n이 된다는 것을 활용하면 더 빠르다.
