#include <iostream>

using namespace std;

int main()
{
    int cnt = 0;
    bool start = false;
    char ch;
    while(cin.get(ch))
    {        
        // ch = (ch & ~' ') - 'A';
        ch = (ch & ~' ');
        if('A' <= ch && ch <= 'Z')
        {
            start = true;
        }
        else
        {
            if(start)
            {
                start = false;
                cnt++;
            }
        }
        if(ch == '\n')
        {
            break;
        }

    }
    cout << cnt << endl;
    return 0;
}
