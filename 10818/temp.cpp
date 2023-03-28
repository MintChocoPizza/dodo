#include <iostream>

using namespace std;

int main()
{
    int N, min=2000000, max= -2000000, temp;
    cin >> N;
    while(N--)
    {
        cin >> temp;
        if(temp<min)
            min = temp;
        if(temp>max)
            max = temp;
    }

    cout << min << ' ' << max << endl;

    return 0;
}
