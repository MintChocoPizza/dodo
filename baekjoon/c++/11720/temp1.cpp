#include <iostream>
#include <string>

using namespace std;

int main()
{
    int N;
    int sum = 0;
    string str;
    cin >> N >> str;
    for(int i=0; i<N; i++)
    {
        sum += int(str[i])-48;
    }
    cout << sum;
    return 0;
}
