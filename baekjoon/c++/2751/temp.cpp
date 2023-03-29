#include <cstdlib>
#include <iostream>

using namespace std;

int arr[1000000];

int compare(const void* a, const void* b)
{
    const int* x = (int*)a;
    const int* y = (int*)b;

    if(*x>*y)
        return 1;
    else if(*x<*y)
        return -1;

    return 0;
}

int main()
{
    int N, i;
    cin >>N;
    for(i=0; i<N; i++)
        cin >> arr[i];
    qsort(arr, N, sizeof(int), compare);
    for(i=0; i<N; i++)
        cout << arr[i] << '\n';
    return 0;
}
