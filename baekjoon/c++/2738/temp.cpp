#include <iostream>

using namespace std;

int main()
{
    int N, M;
    int A[2][100][100];
    cin >> N >> M;

    for(int i=0; i<2; i++)
    {
        for(int j=0; j<N; j++)
        {
            for(int k=0; k<M; k++)
            {
                cin >> A[i][j][k];
            }
        }
    }
    for(int j=0; j<N; j++)
    {
        for(int k=0; k<M; k++)
        {
            cout << A[0][j][k]+A[1][j][k] << ' ';
        }
        cout << endl;
    }

    return 0;
}
