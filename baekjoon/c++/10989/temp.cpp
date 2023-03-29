#include <ios>
#include <iostream>

using namespace std;

int arr[10001]={0,};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);
    int N, temp;
    cin >> N;
    for(int i=0; i<N; i++)
    {
        cin >> temp;
        arr[temp]++;
    }
    for(int i=0; i<10001; i++)
    {
        while(arr[i]--)
            cout << i << '\n';
    }
    return 0;
}
