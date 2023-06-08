#include <algorithm>
#include <iostream>

using namespace std;

int k;
char arr[10];
int choiceNum[10];

bool isCheck = false;
bool visited[10];


void input()
{
    cin >> k;
    for(int i=1; i<=k; ++i)
    {
        cin >> arr[i];
    }
}

// cnt: 현재까지 선택한 숫자의 수 0~k+1개
void minNumber(int cnt)
{
    if(isCheck) return ;
    if(cnt == k+1)
    {
        isCheck = true;
        for(int i=0; i<k+1; ++i)
        {
            cout << choiceNum[i];
        }
        cout << '\n';
        return ;
    }
    
    if(cnt == 0)
    {
        for(int i=0; i<10; ++i)
        {
            if(visited[i]) continue;;
            visited[i] = true;
            choiceNum[cnt] = i;
            minNumber(cnt+1);
            choiceNum[cnt] = 0;
            visited[i] = false;
        }
    }
    else 
    {
        for(int i=1; i<10; ++i)
        {
            if(visited[i]) continue;
            if(arr[cnt] == '>' && choiceNum[cnt-1] < i) continue;
            if(arr[cnt] == '<' && choiceNum[cnt-1] > i) continue;
            visited[i] = true;
            choiceNum[cnt] = i;
            minNumber(cnt + 1);
            choiceNum[cnt] = 0;
            visited[i] = false;
        }
    }
}

// cnt: 현재까지 선택한 숫자의 수 0~k+1개
void maxNumber(int cnt)
{
    if(isCheck) return ;
    if(cnt == k+1)
    {
        cout << "cnt == k+1 \n";
        isCheck = true;
        for(int i=0; i<k+1; ++i)
        {
            cout << choiceNum[i];
        }
        cout << '\n';
        return ;
    }
    
    if(cnt == 0)
    {
        for(int i=9; i>=0; --i)
        {
            if(visited[i]) continue;;
            visited[i] = true;
            choiceNum[cnt] = i;
            maxNumber(cnt+1);
            choiceNum[cnt] = 0;
            visited[i] = false;
        }
    }
    else 
    {
        for(int i=9; i>0; --i)
        {
            if(visited[i]) continue;

            // cout << "cnt: " << cnt << " i: " << i << endl;
            
            /*
            if(arr[cnt] == '>' && choiceNum[cnt-1] < i) continue;
            if(arr[cnt] == '<' && choiceNum[cnt-1] > i) continue;
            visited[i] = true;
            choiceNum[cnt] = i;
            maxNumber(cnt + 1);
            choiceNum[cnt] = 0;
            visited[i] = false;
            */
            if((arr[cnt] == '>' && choiceNum[cnt-1] > i) || (arr[cnt] == '<' && choiceNum[cnt-1] < i))
            {
                visited[i] = true;
                choiceNum[cnt] = i;
                maxNumber(cnt + 1);
                choiceNum[cnt] = 0;
                visited[i] = false;
            }
        }
    }
}
void BF()
{
    memset(visited, 0, sizeof(visited));
    memset(choiceNum, 0, sizeof(choiceNum));
    isCheck = false;
    maxNumber(0);

    /*
    memset(visited, 0, sizeof(visited));
    memset(choiceNum, 0, sizeof(choiceNum));
    isCheck = false;
    minNumber(0);
    */
}

int main()
{
    input();
    
    BF();

    return 0;
}


/*
 * 
 * if 0~k-1 까지 
 *
 * k = 2
 * 0, 1, 2
 *  , <, >
 *
 * 0  1  2 
 * 8, 9, 7
 *
 *
 *
 * k = 9 
 * 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 
 *  , >, <, <, <, >, >, >, <, <   
 *
 * 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 
 * 9, 5, 6, 7, 8, 4, 3, 0, 1, 2 
 *
 *
 * */
