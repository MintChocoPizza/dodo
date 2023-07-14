#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N;

vector<vector<int> > input()
{
    cin >> N; 

    vector<vector<int> > board(N, vector<int> (N, 0));

    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<N; ++j)
        {
            cin >> board[i][j];
        }
    }

    return board;
}

int maxBlock(vector<vector<int> >& board)
{
    int ret = 0;

    for(int y=0; y<N; ++y)
    {
        for(int x=0; x<N; ++x)
        {
            ret = max(ret, board[y][x]);
        }
    }

    return ret;
}

vector<vector<int> > moveBlock(vector<vector<int> > board, int direction)
{
    queue<int> q;
    int idx;
    int block;

    switch (direction) 
    {
        // 0: up, 1:down, 2:left, 3:right
        case 0:
            for(int x=0; x<N; ++x)
            {
                for(int y=0; y<N; ++y)
                {
                    if(board[y][x])
                    {
                        q.push(board[y][x]);
                        board[y][x] = 0;
                    }
                }

                idx = 0;

                while (!q.empty()) 
                {
                    block = q.front();
                    q.pop();

                    if(board[idx][x] == 0)
                    {
                        board[idx][x] = block;
                    }
                    else if(board[idx][x] == block)
                    {
                        board[idx][x] *= 2;
                        ++idx;
                    }
                    else 
                    {
                        ++idx;
                        board[idx][x] = block;
                    }
                }
            }
            break;

        case 1:
            for(int x=0; x<N; ++x)
            {
                for(int y=N-1; y>=0; --y)
                {
                    if(board[y][x])
                    {
                        q.push(board[y][x]);
                        board[y][x] = 0;
                    }
                }

                idx = N-1;

                while(!q.empty())
                {
                    block = q.front();
                    q.pop();

                    if(board[idx][x] == 0)
                    {
                        board[idx][x] = block;
                    }
                    else if(board[idx][x] == block)
                    {
                        board[idx][x] *= 2;
                        --idx;
                    }
                    else 
                    {
                        --idx;
                        board[idx][x] = block;
                    }
                }
            }
            break;

        case 2:
            for(int y=0; y<N; ++y)
            {
                for(int x=0; x<N; ++x)
                {
                    if(board[y][x])
                    {
                        q.push(board[y][x]);
                        board[y][x] = 0;
                    }
                }

                idx = 0;

                while(!q.empty())
                {
                    block = q.front();
                    q.pop();

                    if(board[y][idx] == 0)
                    {
                        board[y][idx] = block;
                    }
                    else if(board[y][idx] == block)
                    {
                        board[y][idx] *= 2;
                        ++idx;
                    }
                    else 
                    {
                        ++idx;
                        board[y][idx] = block;
                    }
                }
            }
            break;

        case 3:
            for(int y=0; y<N; ++y)
            {
                for(int x=N-1; x>=0; --x)
                {
                    if(board[y][x])
                    {
                        q.push(board[y][x]);
                        board[y][x] = 0;
                    }
                }

                    idx = N-1;

                while(!q.empty())
                {
                    block = q.front();
                    q.pop();

                    if(board[y][idx] == 0)
                    {
                        board[y][idx] = block;
                    }
                    else if(board[y][idx] == block)
                    {
                        board[y][idx] *= 2;
                        --idx;
                    }
                    else 
                    {
                        --idx;
                        board[y][idx] = block;
                    }
                }
            }
            break;
    }

    return board;
}

int dfs(int depth, vector<vector<int> > board)
{

    if(depth == 5)
    {
        return maxBlock(board);
    }

    int ret = 2;

    for(int i=0; i<4; ++i)
    {
        int cand = dfs(depth+1, moveBlock(board, i));

        ret = max(ret, cand);
    }

    return ret;
}

int main()
{
    vector<vector<int> > board = input();

    cout << dfs(0, board);

    return 0;
}
