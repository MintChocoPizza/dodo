#include <iostream>

using namespace std;

int sudoku[9][9];
int col[10][10];      // 세로
int row[10][10];      // 가로
int square[10][10];
int xy[10][10] = {
    {1,1,1,2,2,2,3,3,3,0},
    {1,1,1,2,2,2,3,3,3,0},
    {1,1,1,2,2,2,3,3,3,0},
    {4,4,4,5,5,5,6,6,6,0},
    {4,4,4,5,5,5,6,6,6,0},
    {4,4,4,5,5,5,6,6,6,0},
    {7,7,7,8,8,8,9,9,9,0},
    {7,7,7,8,8,8,9,9,9,0},
    {7,7,7,8,8,8,9,9,9,0},
    {0,0,0,0,0,0,0,0,0,0}
};
int zero[81][2];

int cnt=0;
bool found = false;

void BT(int count)
{

    if(count == cnt)
    {
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                cout << sudoku[i][j] << ' ';
            }
            cout << '\n';
        }
        found = true;
        return;
    }

    for(int i=1; i<=9; i++)
    {
        int y = zero[count][0];
        int x = zero[count][1];
        // sudoku[y][x] == 0;
        if(!col[x][i] && !row[y][i] && !square[xy[y][x]][i])
        {
            sudoku[y][x] = i;
            col[x][i] = true;
            row[y][i] = true;
            square[xy[y][x]][i] = true;
            BT(count +1);
            if(found) return;
            sudoku[y][x] = 0;
            col[x][i] = false;
            row[y][i] = false;
            square[xy[y][x]][i] = false;

        }
    }
}


int main()
{
    for(int i=0; i<9; i++)      // y
    {
        for(int j=0; j<9; j++)  // x
        {
            cin >> sudoku[i][j];

            if(sudoku[i][j] != 0)
            {
                col[j][sudoku[i][j]] = true;
                row[i][sudoku[i][j]] = true;
                square[xy[i][j]][sudoku[i][j]] = true;
            }
            else
            {
                zero[cnt][0] = i;
                zero[cnt][1] = j;
                cnt++;
            }
        }
    }

    BT(0);


    return 0;
}



// gpt를 보고 수정함 
// 아마도 출력 후 함수는 종료가 되지만 다른 정답을 찾는 경우의 수가 발생함
// 그래서 2번째 출력이 발생하게 되고 그로 인하여 틀리게 됨
