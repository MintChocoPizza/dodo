#include <ios>
#include <iostream>
#include <cmath>

using namespace std;

int arr[8001] = {0,};

int main()
{
    int N;
    int temp;           // -4000<=temp<=4000
    int sum = 0;        // 산술평균
    int min = 9999;     // 범위
    int max = -9999;
    int mid;            // 중앙값 
    bool isMid = false;
    int cnt = 0;        // 중앙값 for()
    int modeCount = -1; // 최빈값 count
    int mode;           // 최빈값
    bool isSecond = false;

    cin >> N;

    for(int i=0; i<N; i++)
    {
        cin >> temp;
        sum += temp;                    // 산술평균
        if(min>temp) min=temp;          // 범위
        if(max<temp) max=temp;
        arr[temp+4000]++;               // 중앙값
    }

    for(int i=0; i<8001; i++)
    {
        if(modeCount < arr[i])
        {
            modeCount = arr[i];
            mode = i-4000;
            isSecond = false;
        }
        else if(modeCount == arr[i] && !isSecond)
        {
            modeCount = arr[i];
            mode = i-4000;
            isSecond = true;
        }

        cnt += arr[i];
        if(cnt >= N/2+1 && !isMid)
        {
            mid = i-4000;
            isMid = true;
        }
    }

    cout << floor((double)sum/N + 0.5 ) << '\n';
    cout << mid << '\n';
    cout << mode << '\n';
    cout << max - min;

    return 0;
}
