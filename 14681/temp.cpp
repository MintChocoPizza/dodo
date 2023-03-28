#include <iostream>

using namespace std;

int main()
{
    int x, y;
    int res;
    cin >> x >> y;

    if(x>0){
        if(y>0){
            res = 1;
        }else{
            res = 4;
        }
    }else{
        if(y>0){
            res = 2;
        }else{
            res = 3;
        }
    }
    
    cout << res << endl;

    return 0;
}
