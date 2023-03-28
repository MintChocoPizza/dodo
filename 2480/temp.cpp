#include <iostream>

using namespace std;

int main()
{    
    int dice[3];
    int pick[7] = {0,};
    int temp=0;
    int max=0;
    for(int i=0; i<3; i++)
    {
        cin >> dice[i];
        pick[dice[i]]++;
        if(temp < pick[dice[i]])
        {
            temp = pick[dice[i]];
            max = dice[i];
        }
        if(temp < 2 && max < dice[i])
        {
            max = dice[i];
        }
    }

    if(temp == 3)
        cout << 10000+max*1000 << endl;
    else if(temp == 2)
        cout << 1000+max*100 << endl;
    else
        cout << max*100 << endl;

    return 0;
}
