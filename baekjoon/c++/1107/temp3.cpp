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

// 고장난 버튼이 있으면 false, 없으면 true
bool check(int num)
{
    int tempNum = num;

    if(num == 0)
    {
        if(Button[0])
        {
            return false;
        }
        
        return true;
    }
    else
    {
        while(tempNum != 0)
        {
            int temp = tempNum%10;
            if(Button[temp])
            {
                return false;
            }
            tempNum /= 10;
        }
    }
    return true;
}

// 현재 채널의 길이를 반환
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

long long findMinButtonPress()
{
    long long ret = abs(N-100);

    for(int i=0; i<=1000000; ++i)
    {
        if(check(i))
        {
            long long temp = abs(N-i) + numLength(i);
            ret = min(ret, temp);
            // cout << "ret: " << ret << " i: " << i << " abs(N-i): " << abs(N-i) << " numLength(i): " << numLength(i) << endl; 
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
