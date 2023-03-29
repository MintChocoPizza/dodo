#include <iostream>

using namespace std;

int main()
{
    int N;
    int arr[1000];
    int key, i, j;
    int temp;

    cin >> N;

    for(i=0; i<N; i++)
    {
        cin >> arr[i];
    }

    for(i=1; i<N; i++)
    {
        key = arr[i];
        j=i;
        while(--j>=0 && arr[j]>key)
        {
            arr[j+1] = arr[j];
        }
        arr[j+1] = key;

//        key = arr[i];
//        for(j=i-1; j>=0 && key<arr[j]; j--)
//        {
//            arr[j+1] = arr[j];
//        }
//        arr[j+1] = key;
    }

    for(int i=0; i<N; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}

// 생각보다 조금 느림
