#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str[5];
    
    for(int i=0; i<5; i++)
    {
        cin >> str[i];
    }

    for(int i=0; i<15; i++)
    {
        for(int j=0; j<5;  j++)
        {
            if(str[j][i] == '\0' || i >= str[j].length())
                continue;
            cout << str[j][i];
        }
    }
    return 0;
}
