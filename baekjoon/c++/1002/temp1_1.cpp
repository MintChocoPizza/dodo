#include <iostream>
#include <cmath>

using namespace std;

int main() 
{
    int T;
    cin >> T;
    while(T--) // 테스트 케이스 T번 수행한다.
    {
        // 조규현의 좌표(x1, y1), 류재명과의 거리(r1)
        // 백승환의 좌표(x2, y2), 류재명과의 거리(r2)
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        double d = sqrt(pow(abs(x1-x2),2) + pow(abs(y1-y2),2));
        int r = abs(r1-r2);    // 하나의 원이 다른 원 안에 있는 경우, d<r1+r2 인 경우가 생김, 
        int ret;
        if((d==0) && (r1==r2)) ret = -1;
        else if((d<r1+r2) && (d>r)) ret = 2;
        else if((d==r1+r2) || (d==r)) ret = 1;
        else ret = 0;


        cout << ret << endl;
    }
    return 0;
}
