#include <cstdio>
#include <stdio.h>

int k[15], n[15];
int dp[15][15];

int main()
{
    int testcase;
    scanf("%d", &testcase);
    for(int i=1; i<= testcase; i++)
    {
        scanf("%d %d", &k[i], &n[i]);
        for(int x=0; x<=k[i]; x++)
        {
            for(int y=1; y<=n[i]; y++)
            {
                if(x==0)
                    dp[x][y] = y;
                else
                    dp[x][y] = dp[x][y-1] + dp[x-1][y];
            }
        }
        printf("%d\n", dp[k[i]][n[i]]);
    }
}
