#include <iostream>

using namespace std;

int main()
{
    int N;
    int i;
    cin >> N;

    for(i=1; i<N; i++)
    {
        int temp = i;
        int sum = i;
        while(temp/10)
        {
            sum += temp%10;
            temp = temp/10;
        }
        sum += temp%10;

        if(N == sum)
        {
            cout << i;
            return 0;
        }
    }
    
    cout << 0;
    return 0;
}
