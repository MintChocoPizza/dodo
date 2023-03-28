#include <iostream>

using namespace std;

int main()
{
    int alpha[26] = {0,};
    int nalpha;
    int max = -1;
    int index = -1;
    bool B = false;
    char ch;

    while(cin.get(ch))
    {
        if(ch == '\n')
            break;

        if('a'<= ch && ch <= 'z')
        {
            nalpha = int(ch-'a');
        }
        else if('A'<=ch && ch<='Z')
        {
            nalpha = int(ch-'A');
        }
        alpha[nalpha]++;

        if(max < alpha[nalpha])
        {
            max = alpha[nalpha];
            index = nalpha;
            B = false;
        }
        else if(max == alpha[nalpha])
        {
            B = true;
        }
        
        //cout << "현재 문자: " << char(nalpha+'A') << ' ' << nalpha << endl;
        //cout << "max: " << max << endl;
        //cout << "index: " << char(index+'A') << ' ' << index << endl;
        //cout << "B: " << B << endl<<endl;
    }

    //for(int i=0; i<26; i++)
    //{
    //    cout << char(i+'A') << ' ' << alpha[i] << endl;
    //}
    if(B)
        cout << '?' << endl;
    else 
        cout << char(index+'A') << endl;

    return 0;
}
