#include <iostream>
#include <string>
using namespace std;

int main()
{
    string ch;
    int count = 0;
    cin >> ch;
    
    for(int i=0; i<ch.length(); i++)
    {
        char c = ch[i];
        if(c == 'c')
        {
            if(ch[i+1] == '=' || ch[i+1] == '-')
            {
                i++;
            }
        }
        else if(c == 'd')
        {
            if(ch[i+1] == '-')
            {
                i++;
            }
            else if(ch[i+1] == 'z' && ch[i+2] == '=')
            {
                i +=2;
            }
        }
        else if(c == 'l')
        {
            if(ch[i+1] == 'j')
            {
                i++;
            }
        }
        else if(c == 'n')
        {
            if(ch[i+1] == 'j')
            {
                i++;
            }
        }
        else if(c == 's')
        {
            if(ch[i+1] == '=')
            {
                i++;
            }
        }
        else if(c == 'z')
        {
            if(ch[i+1] == '=')
            {
                i++;
            }
        }
        count++;
    }

    cout << count;

    return 0;
}
