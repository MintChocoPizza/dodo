#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int arr[5];
    int i;
    int sum=0;
    for(i=0; i<5; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    cout << sum/5 << endl;

    sort(arr, arr+5);

    cout << arr[2];

    return 0;
}
