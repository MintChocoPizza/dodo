#include <iostream>

using namespace std;

int main()
{
    int N;
    long double max = 0;
    long double sum = 0;
    long double a;
    cin >> N;
    for(int i=0; i<N; i++)
    {
        cin >> a;
        if(max < a)
        {
            max = a;
        }
        sum += a;
    }
    long double ret = (sum/max*100)/N;
    cout << ret << endl;
    return 0;
}
