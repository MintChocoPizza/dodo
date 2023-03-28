#include <iostream>
#include <string>

using namespace std;

string arr[201][100001];    // 1~200살 나이에 따른 이름 순차적으로 저장
int cnt[201];               // 1~200살 까지 명 수

int main()
{
    int N;
    int i,j;
    int age;
    string name;
    
    cin >> N;

    for(i=0; i<N; i++)
    {
        cin >> age >> name;
        cnt[age]++;
        arr[age][cnt[age]] = name;
    }

    for(i=1; i<201; i++)
    {
        if(cnt[i])
        {
            for(j=1; j<=cnt[i]; j++)
            {
                cout << i << ' ' << arr[i][j] << endl;
            }
        }
    }

    return 0;
}
