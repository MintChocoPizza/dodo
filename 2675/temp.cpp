#include <iostream>

using namespace std;

int main()
{
    int T;
    int R;
    char S[21];
    char P[161];
    cin >> T;
    while (T--) {
        cin >> R >> S;
        int cnt = 0;
        int cnt2 = 0;
        while(S[cnt])
        {
            for(int i=0; i<R; i++)
            {
                P[cnt2] = S[cnt];
                cnt2++;
            }
            cnt++;
        }
        P[cnt2] = '\0';
        
        cout << P << endl;
    }
    return 0;
}
