#include <iostream>
#include <algorithm>

using namespace std;

int bS(int *arr, int element, int start, int end)
{
    int mid = (start+end)/2;
    if(arr[mid] == element)
        return mid;
    else if (arr[mid] < element)
        return bS(arr, element, mid+1, end);
    else 
        return bS(arr, element, start, mid-1);
}

int main()
{
    int N, i;
    cin >> N;
    int arr[N];
    int temp[N];

    for(i=0; i<N; i++)
    {
        cin >> arr[i];
        temp[i] = arr[i];
    }

    sort(temp, temp + N);

    int numInd[N];
    int cnt=0;
    for(i=0; i<N; i++)
    {
        if(i>0 && temp[i] != temp[i-1])
            cnt++;
        numInd[cnt] = temp[i];
    }
    
    for(int i=0; i<N; i++)
    { //시간 복잡도: O(n)*O(logn)=O(nlogn)
        int idx = bS(numInd, arr[i], 0, cnt);    //시간 복잡도: O(logn)
        cout << idx << ' ';    
    }

    return 0;
}

