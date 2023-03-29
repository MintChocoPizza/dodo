#include <iostream>

using namespace std;

int main()
{
    char ch[102];
    int alpha[26];
    int num = 0;

    for(int i=0; i<26; i++)
    {
        alpha[i] = -1;
    }

    cin >> ch;
    while(ch[num])
    {
        int nAlpha = int(ch[num]) - 'a';
        if(alpha[nAlpha] == -1)
        {
            alpha[nAlpha] = num;
        }
        num++;
    }

    for(int i=0; i<26; i++)
    {
        cout << alpha[i] << ' ';
    }

    return 0;
}
