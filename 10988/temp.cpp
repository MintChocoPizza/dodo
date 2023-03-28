#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    
    cin >> str;

    int front = 0;
    int end = str.length() - 1;
    while(1)
    {
        if(front<=end)
        {
            if(str[front] != str[end])
            {
                cout << 0;
                return 0;
            }
        }
        else
        {
            cout << 1;
            return 0;
        }
        front++;
        end--;
    }

    
    
    return 0;
}
