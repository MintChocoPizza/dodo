#include <iostream>

using namespace std;

int arr[2][200001];

int main()
{
    int N;
    int x, y;
    int i, j, keyX, keyY;
    
    cin >> N;
    for(i=0; i<N; i++)
    {
        cin >> x >> y;
        arr[0][i] = x;
        arr[1][i] = y;
    }
    
    for(i=1; i<N; i++)
    {
        keyX = arr[0][i];
        keyY = arr[1][i];
        for(j=i-1; j>=0 && arr[0][j] >= keyX; j--)
        {
            if(arr[0][j] == keyX)
            {
                if(arr[1][j] > keyY)
                {
                    arr[0][j+1] = arr[0][j];
                    arr[1][j+1] = arr[1][j];
                }
            }
            else 
            {
                arr[0][j+1] = arr[0][j];
                arr[1][j+1] = arr[1][j];
            }
        }
        arr[0][j+1] = keyX;
        arr[1][j+1] = keyY;
    }

    for(i=0; i<N; i++)
        cout << arr[0][i] << ' ' << arr[1][i] << endl;

    return 0;
}

// B+tree 사용하면 편할거 같음.
