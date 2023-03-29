#include <cstdint>
#include <iostream>

using namespace std;

int N;
int A[12];
int oper[4];
int Min = 2147483647-1;
int Max = -2147483647+1;

int calcul(int res, int temp, int cnt)
{
    int result;
    switch (temp) 
    {
    case 0:         // +
        result = res + A[cnt+1];
        break;
    case 1:         // -
        result = res - A[cnt+1];
        break;
    case 2:         // *
        result = res * A[cnt+1];
        break;
    case 3:         // /
        if(res<0)
        {
            res *= -1;
            result = res / A[cnt+1];
            result *= -1;
        }
        else 
        {
            result = res / A[cnt+1];
        }
        break;
    }

    return result;
}

void BT(int res, int cnt)
{
    int i, sum;

    if(cnt+1 == N)
    {
        if(Min>res)
            Min = res;
        if(Max<res)
            Max = res;
        return;
    }

    for(i=0; i<4; i++)
    {
        if(oper[i])
        {
            sum = calcul(res, i, cnt);
            oper[i]--;
            BT(sum, cnt+1);
            oper[i]++;
        }
    }
}

int main()
{
    int i;
    cin >> N;

    for(i=0; i<N; i++)
    {
        cin >> A[i];
    }
    for(i=0; i<4; i++)
    {
        cin >> oper[i];
    }

    BT(A[0], 0);

    cout << Max << '\n' << Min;

    return 0;
}
