#include <iostream>
#include <string>

using namespace std;

int main()
{
    int N, M;
    int min = 99999;
    cin >> N >> M;
    cin.ignore();
    
    string str[N];
    for(int i=0; i<N; i++)
    {
        getline(cin, str[i]);
    }


    for(int i=0; i<=N-8; i++)
    {
        for(int j=0; j<=M-8; j++)
        {
            int black=0;
            int white=0;
            for(int a=i; a<i+8; a++)
            {
                for(int b=j; b<j+8; b++)
                {
                    if((a+b)%2 == 0)
                    {
                        if(str[a][b] == 'B')
                            white++;
                        else 
                            black++;
                    }
                    else 
                    {
                        if(str[a][b] == 'B')
                            black++;
                        else 
                            white++;
                    }
                }
            }
            
            min = min>black? black:min;
            min = min>white? white:min;
        }
    }

    cout << min;

    return 0;
}


// 규칙을 생각하지 못했음.... 2차원 배열은 대각선으로 1,2,3, ... 등가함:ㅈ
