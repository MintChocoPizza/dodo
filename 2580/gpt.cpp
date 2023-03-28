#include <iostream>

using namespace std;

int sudoku[9][9];
int col[10][10];      // 세로
int row[10][10];      // 가로
int square[10][10];
int xy[10][10] = {
    {1,1,1,2,2,2,3,3,3},
    {1,1,1,2,2,2,3,3,3},
    {1,1,1,2,2,2,3,3,3},
    {4,4,4,5,5,5,6,6,6},
    {4,4,4,5,5,5,6,6,6},
    {4,4,4,5,5,5,6,6,6},
    {7,7,7,8,8,8,9,9,9},
    {7,7,7,8,8,8,9,9,9},
    {7,7,7,8,8,8,9,9,9}
};
int zero[81][2];
int cnt = 0;
bool found = false;

void BT(int count)
{
    if (count == cnt) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << sudoku[i][j] << ' ';
            }
            cout << '\n';
        }
        found = true; // 모든 값을 찾은 경우, found 변수를 true로 설정하여 종료
        return;
    }

    int y = zero[count][0];
    int x = zero[count][1];

    for (int i = 1; i <= 9; i++) {
        if (!col[x][i] && !row[y][i] && !square[xy[y][x]][i]) {
            sudoku[y][x] = i;
            col[x][i] = true;
            row[y][i] = true;
            square[xy[y][x]][i] = true;
            BT(count + 1);
            if (found) return; // 값을 모두 찾은 경우, 재귀호출 종료
            sudoku[y][x] = 0;
            col[x][i] = false;
            row[y][i] = false;
            square[xy[y][x]][i] = false;
        }
    }
}

int main()
{
    for (int i = 0; i < 9; i++) {      // y
        for (int j = 0; j < 9; j++) {  // x
            cin >> sudoku[i][j];

            if (sudoku[i][j] != 0) {
                col[j][sudoku[i][j]] = true;
                row[i][sudoku[i][j]] = true;
                square[xy[i][j]][sudoku[i][j]] = true;
            }
            else {
                zero[cnt][0] = i;
                zero[cnt][1] = j;
                cnt++;
            }
        }
    }

    BT(0);

    return 0;
}

