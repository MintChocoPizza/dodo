#include <iostream>

using namespace std;

int main()
{
    int T;
    int H,W,N;

    cin >> T;
    while(T--)
    {
        int floor, nRoom;
        cin >> H >> W >> N;
        
        nRoom = N/H;
        floor = N%H;

        if(floor)
            nRoom++;
        else
            floor = H;

        if(10>nRoom)
            cout << floor << '0' << nRoom << endl;
        else
            cout << floor << nRoom << endl;
    }
    return 0;
}
