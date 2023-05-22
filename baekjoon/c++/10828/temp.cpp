#include <iostream>
#include <string>

using namespace std;

int Data[10000];
int Top = 0;
int Size = 10000;

void push(int num)
{
    if(Top == Size)
        cout << "[error] stack full\n";
    else 
    {
        Data[Top] = num;
        Top++;
    }
}

void pop()
{
    if(Top == 0)
    {
        cout << -1 << '\n';
    }
    else 
    {
        Top--;
        cout << Data[Top] << '\n';
    }
}

void s_Size()
{
    cout << Top << '\n';
}

bool empty()
{
    if(Top == 0)
        return true;
    return false;
}

void s_Top()
{
    if(empty())
        cout << "-1\n";
    else 
        cout << Data[Top-1] << '\n';
}

int main()
{
    int N;

    cin >> N;
    while(N--)
    {
        string commed;
        cin >> commed;
        
        if(!commed.compare("push"))
        {
            int temp;
            cin >> temp;
            push(temp);
        }
        else if(!commed.compare("pop"))
        {
            pop();
        }
        else if(!commed.compare("size"))
        {
            s_Size();
        }
        else if(!commed.compare("empty"))
        {
            cout << empty() << '\n';
        }
        else if(!commed.compare("top"))
        {
            s_Top();
        }
    }

    return 0;
}
