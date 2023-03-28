#include <algorithm>
#include <iostream>

using namespace std;

bool overlap[2000000001];
void merge(int list[], int left, int mid, int right);
void merge_sort(int list[], int left, int right);

int cnt;

int main()
{
    int N, i;
    cin >> N;
    cnt = N;

    int arr[N];
    int tempArr[N];
    for(i=0; i<N; i++)
    {
        cin >> arr[i];
        tempArr[i] = arr[i];
    }

    merge_sort(tempArr, 0, N-1);

    for(i=0; i<N; i++)
    {
        cout << tempArr[i] << ' ';
    }

    return 0;
}

void merge(int list[], int left, int mid, int right)
{
    int i, j, k, l;
    int sorted[right+1];
    i=left; j=mid+1; k=left;
    while(i<=mid && j<=right)
    {
        if(list[i] < list[j])
            sorted[k++] = list[i++];
        else if (list[i] > list[j])
            sorted[k++] = list[j++];
        else
        {
            i++;

        }
    }

    if(i>mid)
        for(l=j; l<=right; l++)
            sorted[k++] = list[l];
    else 
        for(l=i; l<=left; l++)
            sorted[k++] = list[l];

    for(l=left; l<k; l++)
        list[l] = sorted[l];
}
void merge_sort(int list[], int left, int right)
{
    if(left < right)
    {
        int mid = (left + right)/2;
        merge_sort(list, left, mid);
        merge_sort(list, mid+1, right);
        merge(list, left, mid, right);
    }
}
