#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int N, M;
bool remoteControl[10];

void input()
{
    cin >> N >> M;
    for(int i=0; i<M; ++i)
    {
        int temp;
        cin >> temp;
        // 고장난 버튼은 true
        remoteControl[temp] = true;
    }
}

bool check(int num)
{
    int tempNum = num;
    while(tempNum != 0)
    {
        int temp = tempNum%10;
        if(remoteControl[temp])
        {
            return true;
        }
        tempNum = tempNum/10;
    }

    // 고장난 버튼을 사용한경우 true
    return false;
}

int findMinButtonPress()
{
    // +버튼 || -버튼으로만 이동한 경우
    int ret = abs(N - 100);

    // 현재 버튼을 기준으로 ++, -- 를 하여 가장 먼저 누를 수 있는 버튼이 최소이다.
    int currentChannel = N;
    // 고장난 버튼을 사용한 경우
    while(currentChannel<=1000000 && check(currentChannel))
    {
        currentChannel++;
    }
    int digitCount = 0;
    if(currentChannel == 0)
    {
        digitCount = 1;
    }
    else 
    {
        int temp = currentChannel;
        while(temp != 0)
        {
            temp /= 10;
            digitCount++;
        }
    }
    ret = min(ret, digitCount + abs(currentChannel-N));

    currentChannel = N;
    while(currentChannel >=0 && check(currentChannel))
    {
        currentChannel--;
    }
    digitCount = 0;
    if(currentChannel == 0)
    {
        digitCount = 1;
    }
    else 
    {
        int temp = currentChannel;
        while(temp != 0)
        {
            temp /= 10;
            digitCount++;
        }
    }
    ret = min(ret, digitCount + abs(currentChannel - N));

    return ret;
}

int main()
{
    input();
    cout << findMinButtonPress();

    return 0;
}

/*
 *
 * 5457
 * 3
 * 6 7 8
 *
 * 5455++ || 5459--
 *
 * BUT
 * 100에서 101으로 가는 가장 빠른 방법은 ++ 1번이다. -> 기본값으로 설정1
 *
 *
 * */
