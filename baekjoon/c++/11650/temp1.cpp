#include <iostream>

using namespace std;

typedef struct {
    int x;
    int y;
}Coordin;

Coordin arr[200001];
Coordin sorted[200001];

void merge(Coordin list[], int left, int mid, int right);
void merge_sort(Coordin list[], int left, int right);

int main()
{
    
    int N;
    int x, y;
    int i, j;
    cin >> N;

    for (i=0; i<N; i++)
    {
        cin >> arr[i].x >> arr[i].y;
    }

    merge_sort(arr, 0, N-1);

    for(i=0; i<N; i++)
    {
        cout << arr[i].x << ' ' << arr[i].y << '\n';
    }

    return 0;
}

void merge(Coordin list[], int left, int mid, int right)
{
    int i, j, k, l;
    
    i=left, j=mid+1; k=left;


    while(i<=mid && j<=right)
    {
        if(list[i].x < list[j].x)
        {
            sorted[k++] = list[i++];
        }
        else if(list[i].x > list[j].x)
        {
            sorted[k++] = list[j++];
        }
        else 
        {
            if(list[i].y < list[j].y)
            {
                sorted[k++] = list[i++];
            }
            else
            {
                sorted[k++] = list[j++];
            }
        }
    }

    if(i > mid)
        for(l=j; l<=right; l++)
            sorted[k++] = list[l];
    else 
        for(l=i; l<=mid; l++)
            sorted[k++] = list[l];

    for(l=left; l<=right; l++)
        list[l] = sorted[l];
}

void merge_sort(Coordin list[], int left, int right)
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


// 71, 74번째 줄 l++를 하여서 오류가 발생하였음:
