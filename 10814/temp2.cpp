#include <ios>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct Member 
{
    int count;
    int age;
    string name;
};

bool compare(const Member& a, const Member& b)
{
    if(a.age == b.age)
        return a.count < b.count;
    return a.age < b.age;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, i;
    cin >> N;
    Member m[N];

    for(i=0; i<N; i++)
    {
        cin >> m[i].age >> m[i].name;
        m[i].count = i;
    }

    sort(m, m+N, compare);

    for(i=0; i<N; i++)
    {
        cout << m[i].age << ' ' << m[i].name << '\n';
    }

    return 0;
}
