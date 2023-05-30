#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
bool Button[10];

void input()
{
    int temp;
    cin >> N >> M;
    for(int i=0; i<M; ++i)
    {
        cin >> temp;
        Button[temp] = true;
    }
}

bool check(int num)
{
    int tempNum = num;
    while(tempNum != 0)
    {
        int temp = tempNum%10;
        if(Button[temp])
        {
            return false;
        }
        tempNum /= 10;
    }
    return true;
}

int numLength(int num)
{
    if(num == 0)
    {
        return 1;
    }
    else 
    {
        int temp = num;
        int count = 0;
        while(temp != 0)
        {
            temp /= 10;
            count++;
        }
        return count;
    }
}

int findMinButtonPress()
{
    int ret = abs(N-100);

    for(int i=0; i<=1000000; ++i)
    {
        if(check(i))
        {
            int temp = abs(N-i) + numLength(i);
            ret = min(ret, temp);
        }
    }
    return ret;
}

int main()
{
    input();
    cout << findMinButtonPress();
    return 0;
}
