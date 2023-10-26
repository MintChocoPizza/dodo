# cin
* cin은 공백을 기준으로 입력을 받는다.
* 이 문제에서 입력은 공백이 없는 연속된 입력을 받고 있다. 

* 이러한 경우 
* 1. string으로 입력을 받으면 \n(공백)을 기분으로 입력을 받을 수 있다. 

* 2. c++ 가 아닌 c언어의 입력을 사용한다. 

```c++
include <stdio.h>

int n,m;

int main() {
    cin >> n >> m;
    for(int i=0; i<n; ++i)
        for(int j=0; j<m; ++j)
            scanf("%1d", &arr[i][j]);   // 1자리 숫자를 읽어서 배열에 저장한다.

    return 0;
}
```
