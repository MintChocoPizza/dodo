#include <iostream>

using namespace std;

int main()
{
    int N;
    int i;
    int minCnt = 999999;
    bool check = false;
    cin >> N;

    for(i=0; i*5<=N; i++)
    {
        int temp = N;
        temp -= i*5;
        if(!(temp%3) && minCnt>(i+temp/3))
        {
            minCnt = i+(temp/3);
            check = true;
        }
    }
    
    if(check)
        cout << minCnt;
    else 
        cout << -1;
    return 0;
}
// 처음에 틀렸는데 아마도 minCnt 값이 충분히 작지 않아서 그런것으로 보임
