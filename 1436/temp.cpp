#include <iostream>

using namespace std;

int main()
{
    int N;
    int cnt = 0;
    int num;
    int temp;
    cin >> N;
    
    for(num = 666;  ;num++)
    {
        temp = num;
        while(temp>665)
        {
            if(temp%1000 == 666)
            {
                cnt++;
                break;
            }
            temp = temp/10;
        }

        if(cnt == N)
        {
            cout << num;
            return 0;
        }
    }

    return 0;
}

