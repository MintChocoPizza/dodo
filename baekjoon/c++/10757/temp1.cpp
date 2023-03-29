#include <iostream>
#include <string>

#include <stdio.h>

using namespace std;

int main()
{
    string A, B, C;
    int indexA, indexB;
    bool carry = false;
    int num;

    cin >> A >> B;
    indexA = A.length()-1;
    indexB = B.length()-1;

    while(carry || (indexA>=0 && indexB>=0))
    {
        num = 0;
        if(indexA>=0)
            num += A[indexA]-'0';
        if(indexB>=0)
            num += B[indexB]-'0';
        if(carry)
        {
            num += 1;
            carry = false;
        }
        if(num>9)
        {
            num -= 10;
            carry = true;
        }

        // printf("A[%d] = %c , B[%d] = %c\n", indexA, A[indexA], indexB, B[indexB]);
        // //시각화를 위한 코드

        C.push_back(num+'0');
        indexA--;
        indexB--;
    }

    for(int i=C.length()-1; i>=0; i--)
        cout << C[i];

    return 0;
}
