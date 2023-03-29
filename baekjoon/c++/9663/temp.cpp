#include <iostream>

using namespace std;

int N;
int arr[15];
int cnt=0;

bool visited(int row)
{
    
    for(int i=0; i<row; i++)
    {
        if(arr[row] == arr[i] || arr[row]+row == arr[i]+i || row-i == arr[row]-arr[i])
            return true;
    }

    return false;
}

void BT(int row)
{
    if(row == N)
    {
        cnt ++;
        return;
    }
    for(int col=0; col<N; col++)
    {
        arr[row] = col;
        if(!visited(row))
        {
            BT(row+1);
        }
    }
}

int main()
{
    cin >> N;

    BT(0);

    cout << cnt;


    return 0;
}

