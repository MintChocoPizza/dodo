#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int i,n,arr[1001];
    cin >> n;
    for(i=0; i<n; i++)
        cin >> arr[i];
    sort(arr,arr+n);
    for(i=0; i<n; i++)
        cout << arr[i] << '\n';
    return 0;
}

// 그냥 인덱스로 접근하는 배열은 정렬이 빠른다.
