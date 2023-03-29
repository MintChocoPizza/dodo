#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;

    while(cin >> n && (n != -1))
    {
        int sum=1;
        bool arr[100001] = {0,};
        
        for(int i=2; i<=sqrt(n); i++)
        {
            if(!(n%i))
            {
                arr[i] = arr[n/i] = true;
                sum = sum + i + n/i;
            }
        }

        if(sum != n)
            cout << n << " is NOT perfect.\n";
        else
        {
            cout << n << " = " << 1;
            for(int i=2; i<n; i++)
            {
                if(arr[i])
                    cout << " + " << i;
            }
            cout << '\n';
        }
    }
    return 0;
}
