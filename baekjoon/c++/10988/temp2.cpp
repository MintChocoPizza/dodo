#include <cstring>
#include <stdio.h>
#include <string.h>

#define MAX_LEGNTH 100

int main()
{
    char str[MAX_LEGNTH];
    bool result = true;

    scanf("%s", str);

    for(int i=0; i<strlen(str)/2; i++)
    {
        if(str[i] != str[strlen(str)-i-1])
            result = false;
    }

    if(result)
        printf("1");
    else
        printf("0");

    return 0;
}
