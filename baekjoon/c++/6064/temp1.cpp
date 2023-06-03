#include <iostream>

using namespace std;

int M, N, x, y;

// 최대공약수(유클리드 호제법)
int GCD(int a, int b)
{
    if(b == 0)
        return a;
    else 
        return GCD(b, a%b);
}
// 최소공배수 (최대공약수를 이용)
int LCM(int a, int b)
{
    return a*b / GCD(a,b);
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        bool check = false;

        cin >> M >> N >> x >> y;

        int temp = LCM(M, N);
        x--, y--;
        for(int i=x; i<=temp; i+=M)
        {
            // test
            //cout << '<' << (i%M) << ',' << (i%N) << "> 는 " << i << "번째 해 입니다." << endl;
            if((i%N) == y) 
            {
                cout << i+1 << '\n';
                check = true;
                break;
            }
        }
        if(!check)
        {
            cout << -1 << '\n';
        }
    }
    return 0;
}

// 1<= M,N <=40.000 , 1<=x<=M, 1<=y<=N;
// <M, N>일때 <x,y>는 k번째 해임
// 
// 저것과 상관없이 x는 1부터 M까지 계속 돌아감 이럴때 쓰던 방법은 (k%m) = x임   -> y도 k%n = y 로 동일함
// 마지막 해는 k%m=m 이고 k%n=n인 k 이다. 
// 
// 
// M = 5, N = 7
// if(x == 3 y == 6)이면 
// k: <x,y> -> (k%m) = x
// 
// 근데 나머지 연산으로 증가하는 수를 범위 안에서 반복되게 할 때는 
// int next = (ID+1)%range; -> ID:0~, next:0~range-1, 0이 1번이 된다.
// 이 문제에서는 0이 나오면 안됨-> 아니면 0이 첫번째가 되게 바꿔야 한다.
// 
// 1: <1,1> -> 6: <1,6>
// 2: <2,2> -> 7: <2,7>
// 3: <3,3> -> 8: <3,1> -> 13: <3,6>   => 하나의 기준을 정하여 계산하면 됨 
// 4: <4,4> -> 9: <4,2>
// 5: <5,5> -> 10:<5,3>
// 
// 1<= x <=5 , 1<=y<=7, 
