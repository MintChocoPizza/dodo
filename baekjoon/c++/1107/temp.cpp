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
    /*
     *  num = 123456 
     *  int temp = num % 10 -> temp=6
     *  num = num/10 -> num=12345 
     *
     *  .....
     *
     *
     *  num = 12 
     *  temp = num % 10 -> temp=2 
     *  num = num/10 -> num=1 
     *
     *  num = 1
     *  temp = num % 10 -> temp=1 
     *  num = num/10 -> num=0
     * */
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

    return false;
}

int BFS()
{
    // +버튼 || -버튼으로만 이동한 경우
    int ret = abs(N - 100);

    int currentChannel = 0;
    while(currentChannel <= 1000000)
    {
        // 고장난 버튼을 사용한 경우 true
        if(check(currentChannel))
        {
            currentChannel++;
            continue;
        }
        
        int digitCount = 0;
        if(currentChannel == 0)
        {
            digitCount = 1;
        }
        else 
        {
            int temp = currentChannel;
            while (temp != 0)
            {
                temp /= 10;
                digitCount++;
            }
        }
        ret = min(ret, digitCount + abs(currentChannel-N));
        currentChannel++;
    }
    return ret;
}

int main()
{
    input();
    cout << BFS();

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
