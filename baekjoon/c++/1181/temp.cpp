#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool compare(const string& a, const string& b)
{
    if(a.length() != b.length())
        return a.length() < b.length();
    
    return a<b;
}

int main()
{
    int N, i;
    cin >> N;
    string str[N];
    for(i=0; i<N; i++)
    {
        cin >> str[i];
    }

    sort(str, str+N, compare);

    for(i=0; i<N; i++)
    {
        if(str[i] == str[i+1])
            continue;
        cout << str[i] << endl;
    }
    return 0;
}
