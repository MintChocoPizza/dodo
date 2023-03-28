#include <iostream>

using namespace std;

int main()
{
    int N;
    int sum = 0;
    char ch[101];
    cin >> N >> ch; 
    for(int i=0; i<N; i++)
    {
        sum = sum + int(ch[i])-'0';
    }
    cout << sum;

    return 0;
}
