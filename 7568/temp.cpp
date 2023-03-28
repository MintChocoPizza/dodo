#include <iostream>

using namespace std;

int level[50];

struct People
{
    int kg;
    int cm;
};

int main()
{
    int N;
    int i, j;
    cin >> N;

    People p[N];
    for(i=0; i<N; i++)
        cin >> p[i].kg >> p[i].cm;

    for(i=0; i<N-1; i++)
    {
        for(j=i+1; j<N; j++)
        {
            if(p[i].cm<p[j].cm && p[i].kg<p[j].kg)
            {
                level[i]++;
            }
            else if(p[i].cm>p[j].cm && p[i].kg>p[j].kg)
            {
                level[j]++;
            }
        }
    }

    for(i=0; i<N; i++)
        cout << level[i]+1 << ' ';

    return 0;
}
