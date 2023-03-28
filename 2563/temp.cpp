#include <iostream>

using namespace std;

int main()
{
    int area[100][100] = {0,};
    int N;
    int x,y;
    int count = 0;

    cin >> N;
    while(N--)
    {
        cin >> x >> y;
        for(int i=y; i<y+10; i++)
        {
            for(int j=x; j<x+10; j++)
            {
                area[i][j]++;
            }
        }
    }
    
    for(int i=0; i<100; i++)
    {
        for(int j=0; j<100; j++)
        {
            if(area[i][j]>0)
                count++;
        }
    }

    cout << count;

    return 0;
}
