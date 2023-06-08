#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int k;          // k: 2<= k <=9
char arr[10];   // 1~k까지 k개

bool isCheck = false;
int pickNumber[10];     // 0~k 10개
bool visited[10];       // 0~9  10개

// cnt: 현재까지 선택한 숫자의 갯수, 0(한개도 안뽑음) ~ k+1개 
void minNumber(int cnt)
{
    // 조건에 맞는 수를 한개라도 찾았다면 계속 return한다.
    if(isCheck) return;
    if(cnt == k+1)
    {
        isCheck = true;
        for(int i=0; i<k+1; ++i)
        {
            cout << pickNumber[i];
        }
        cout << '\n';
        return;
    }
    
    if(cnt == 0)
    {
        for(int i=0; i<10; ++i)
        {
            visited[i] = true;
            pickNumber[cnt] = i;
            minNumber(cnt+1);
            visited[i] = false;
        }
    }
    else 
    {
        for(int i=0; i<10; ++i)
        {
            if(visited[i]) continue;
            if((arr[cnt] == '<' && pickNumber[cnt-1] < i) || (arr[cnt] == '>' && pickNumber[cnt-1] > i))
            {
                visited[i] = true;
                pickNumber[cnt] = i;
                minNumber(cnt+1);
                visited[i] = false;
            }
        }
    }

    return;
}

void maxNumber(int cnt)
{
    if(isCheck) return;
    if(cnt == k+1)
    {
        isCheck = true;
        for(int i=0; i<k+1; ++i)
        {
            cout << pickNumber[i];
        }
        cout << '\n';
        return;
    }

    if(cnt == 0)
    {
        for(int i=9; i>=0; --i)
        {
            visited[i] = true;
            pickNumber[cnt] = i;
            maxNumber(cnt+1);
            visited[i] = false;
        }
    }
    else 
    {
        for(int i=9; i>=0; --i)
        {
            if(visited[i]) continue;
            if((arr[cnt] == '<' && pickNumber[cnt-1] < i) || (arr[cnt] == '>' && pickNumber[cnt-1] > i))
            {
                visited[i] = true;
                pickNumber[cnt] = i;
                maxNumber(cnt+1);
                visited[i] = false;
            }
        }
    }

    return;
}

void BF()
{
    isCheck = false;
    memset(visited, 0, sizeof(visited));
    memset(pickNumber, 0, sizeof(pickNumber));
    maxNumber(0);

    isCheck = false;
    memset(visited, 0, sizeof(visited));
    memset(pickNumber, 0, sizeof(pickNumber));
    minNumber(0);
}

void input()
{
    cin >> k;
    for(int i=1; i<=k; ++i)
    {
        cin >> arr[i];
    }
}

int main()
{
    input();

    BF();

    return 0;
}
