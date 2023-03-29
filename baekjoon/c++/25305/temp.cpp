#include <iostream>

using namespace std;

int arr[1000];
int sorted[1000];

void merge(int list[], int left, int mid, int right);
void merge_sort(int list[], int left, int right);

int main()
{
    int N,k,x;
    int i;
    cin >> N >> k;
    for(i=0; i<N; i++)
        cin >> arr[i];
    merge_sort(arr, 0, N-1);

    for(i=0; i<N; i++)
        cout << arr[i] << " ";

    cout << arr[N-k];
    return 0;
}

void merge(int list[], int left, int mid, int right)
{
    int i,j,k,l;
    i=left; j=mid+1; k=left;
    while(i<=mid && j<=right)
    {
        if(list[i]<=list[j])
            sorted[k++] = list[i++];
        else
            sorted[k++] = list[j++];
    }

    if(i>mid)
        for(l=j; l<=right; l++)
            sorted[k++] = list[l];
    else
        for(l=i; l<=mid; l++)
            sorted[k++] = list[l];

    for(l=left; l<=right; l++)
        list[l] = sorted[l];
}
void merge_sort(int list[], int left, int right)
{
    int mid;
    if(left<right)
    {
        mid = (left+right)/2;
        merge_sort(list, left, mid);
        merge_sort(list, mid+1, right);
        merge(list, left, mid, right);
    }

}
