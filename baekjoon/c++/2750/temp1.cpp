#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    int a;
    vector<int> vec;
    vector<int>::iterator Iter1;
    cin >> N;
    for(int i=0; i<N; i++)
    {
        cin >> a;
        vec.push_back(a);
    }

    sort(vec.begin(), vec.end());
    
    for(Iter1 = vec.begin(); Iter1 != vec.end(); Iter1++)
        cout << *Iter1 << endl;

    return 0;
}

// 삽입정렬보다 느린데????? 흠...
