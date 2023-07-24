// 범위오류

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int N;
vector<vector<int> > vec;
int ret[3];

void input()
{
    cin >> N;
    
    for(int y=0; y<N; ++y)
    {
        vec.push_back(vector<int>(N, 2));
        for(int x=0; x<N; ++x)
        {
            int temp;
            cin >> temp;
            vec[y][x] = temp+1;
        }
    }
}

void divide(int n, int Y, int X)
{
    int temp = vec[Y][X];
    int isSame = true;

    for(int y=Y; Y<Y+N; ++y)
    {
        for(int x=X; x<X+N; ++x)
        {
            if(temp != vec[y][x])
            { 
                isSame = false;
                break;
            }
        }
    }
    if(isSame) 
    {
        ret[temp]++;
        return ;
    }

    int div = n/3;
    divide(div, Y, X);
    divide(div, Y, X+div);
    divide(div, Y, X+(2*div));
    divide(div, Y+div, X);
    divide(div, Y+div, X+div);
    divide(div, Y+div, X+(2*div));
    divide(div, Y+(2*div), X);
    divide(div, Y+(2*div), X+div);
    divide(div, Y+(2*div), X+(2*div));
}

int main()
{
    input();

    divide(N, 0, 0);

    for(int i=0; i<3; ++i)
    {
        cout << ret[i] << '\n';
    }

    return 0;
}
