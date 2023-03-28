#include <iostream>
#include <string>

using namespace std;

int main()
{
    int N;
    int count = 0;
    cin >> N;
    while(N--)
    {
        string str;
        bool check = false;
        cin >> str;
        bool Alpha[26] = {0,};
        for(int i=0; i<str.length(); i++)
        {
            if(!Alpha[str[i]-'a'])
            {
                Alpha[str[i]-'a'] = true;
            }
            else 
            {
                if(str[i] == str[i-1])
                {

                }
                else
                {
                    check = true;
                    break;
                }
            }
        }
        if(!check)
        {
            count++;
        }
    }

    cout << count;

    return 0;
}
