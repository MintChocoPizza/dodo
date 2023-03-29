#include <algorithm>
#include <iostream>

using namespace std;

struct Member {
    int count;
    int age;
    string name;
    // Member(int count, int age, string name): count(count), age(age), name(name){}
};

bool compare(const Member& a, const Member& b)
{
    if(a.age == b.age)
        return a.count < b.count;
    return a.age < b.age;
};

int main()
{
    int N, i;
    Member m[100000];
    cin >> N;
    for(i=0; i<N; i++)
    {
        m[i].count = i;
        cin >> m[i].age >> m[i].name;
    }

    sort(m, m+N, compare);

    for(i=0; i<N; i++)
    {
        cout << m[i].age << ' ' << m[i].name << endl;
    }

    return 0;
}
