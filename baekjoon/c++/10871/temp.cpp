#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, X, temp;
    vector<int> vec;

    cin >> N >> X;
    for(int i=0; i<N; i++)
    {
        cin >> temp;
        if(temp<X)
            vec.push_back(temp);
    }

    for(int i=0; i<vec.size(); i++)
        cout << vec[i] << ' ';


    return 0;
}
