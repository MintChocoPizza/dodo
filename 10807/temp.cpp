#include <iostream>

using namespace std;

int main()
{
    int N, v;
    int arr[201] = {0,};
    int temp;

    cin >> N;
    while(N--)
    {
        cin >> temp;
        arr[temp+100]++;
    }
    cin >> v;
    cout << arr[v+100] << endl;
    return 0;
}
