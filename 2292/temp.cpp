#include <iostream>

using namespace std;

int main()
{
    int N;
    int sum = 1;
    int i = 0;
    cin >> N;
    
    while(N > sum+(6*i))
    {
        sum += 6*i;
        i++;
    }

    cout << i+1;
    

    return 0;
}
