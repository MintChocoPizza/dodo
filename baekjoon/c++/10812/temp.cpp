#include <iostream>

using namespace std;

int main()
{
    int N, M;
    int arr[101];
    cin >> N >> M;

    for(int i=1; i<=N; i++)
    {
        arr[i] = i;
    }

    while(M--)
    {
        int i,j,k;
        int temp[101];
        cin >> i >> j >> k;
        
        int index = i;
        for(int t=k; t<=j; t++)
        {
            temp[index] = arr[t];
            index++;
        }
        for(int t=i; t<k; t++)
        {
            temp[index] = arr[t];
            index++;
        }

        for(int t=i; t<=j; t++)
        {
            arr[t] = temp[t];
        }
    }
    
    for(int i=1; i<=N; i++)
    {
        cout << arr[i] << ' ';
    }
    return 0;
}

// 다들 임시 배열을 만들어서 사용함
