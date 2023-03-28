#include <iostream>

using namespace std;

int arr[10001] = {1,1,0,};

int main()
{
    int T;
    int n;

    for(int i=2; i*i<=10000; i++)
    {
        if(!arr[i])
        {
            for(int j = i*i; j<=10000; j = j+i)
            {
                arr[j] = 1;
            }
        }
    }

    cin >> T;
    while(T--)
    {
        int min = 10000;
        int x, y;
        cin >> n;

        for(int i=2; i<=n/2+1; i++)
        {
            if(!arr[i] && !arr[n-i])
            {
                int a,b;
                if(i<n-i)
                {
                    a=i;
                    b=n-i;
                }
                else
                {
                    a=n-i;
                    b=i;
                }
                cout << "i: " << i << "  " << "n-i: " << n-i << "  " << endl;
                cout << "a: " << a << "  " << "b  : " << b << "  " << endl; 
                cout << "min: " << min << "  " << "b-a: " << b-a << endl;

                if(min>b-a)
                {
                    x = a;
                    y = b;
                    min = b-a;
                }
                cout << "min: " << min << endl;
                cout << "x: " << x << "  " << "y: " << y << endl;
            }
        }

        cout << x << ' ' << y << endl;
    }
    return 0;
}


// 출력 초과......
// 작성한 내가 봐도 스파게티 코드....
// 지금 제정신도 아님...
//
