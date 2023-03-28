#include <iostream>

using namespace std;

int main()
{
    int C, N;
    cin >> C;
    while(C--)
    {
        int sum = 0;
        double avg;
        int cnt = 0;
        int arr[1001] = {0,};
        cin >> N;
        for(int i=0; i<N; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }
        avg = (double)sum/N;
        for(int i=0; i<N; i++)
        {
            if(arr[i] > avg)
            {
                cnt++;
            }
        }
        cout << fixed;
        cout.precision(3);
        cout << (double)cnt/N*100 << '%'<< endl;
    }
    return 0;
}
