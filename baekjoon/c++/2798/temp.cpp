#include <iostream>

using namespace std;

int main()
{ 
    int N, M;
    int i, j, k;
    cin >> N >> M;
    int arr[N];
    int max=-1;

    for(i=0; i<N; i++)
    {
        cin >> arr[i];
    }

    for(i=0; i<N-2; i++)
    {
        for(j=i+1; j<N-1; j++)
        {
            for(k=j+1; k<N; k++)
            {
                int sum = arr[i]+arr[j]+arr[k];
                if(sum<=M && max<sum)
                {
                    max = sum;
                }
            }
        }
    }
    
    cout << max;

    return 0;
}
