//baekjoon 9944
//NxN보드 완주하기
//50% correct
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int n, m;

bool check(vector<vector<int>> &board)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 0)
                return false;
        }
    }
    return true;
}

pair<int, int> roll(vector<vector<int>> &board, int direction, int y, int x)
{
    int diry = dy[direction];
    int dirx = dx[direction];
    while (y + diry >= 0 && y + diry < n && x + dirx >= 0 && x + dirx < m && board[y + diry][x + dirx] != 1)
    {
        y = y + diry;
        x = x + dirx;
        board[y][x] = 1;
    }
    return make_pair(y, x);
}

void rollback(vector<vector<int>> &board, int direction, int y, int x, int ny, int nx)
{
    int diry = dy[direction];
    int dirx = dx[direction];
    while (ny != y || nx != x)
    {
        y = y + diry;
        x = x + dirx;
        board[y][x] = 0;
    }
    return;
}

int go(vector<vector<int>> &board, int rolls, int y, int x)
{
    int ans = 100;
    if (check(board))
        return rolls;
    if (rolls >= 10)
        return ans;
    for (int i = 0; i < 4; i++)
    {
        pair<int, int> next = roll(board, i, y, x);
        if (next.first == y && next.second == x)
            continue;
        ans = min(ans, go(board, rolls + 1, next.first, next.second));
        rollback(board, i, y, x, next.first, next.second);
    }
    return ans;
}

int main()
{
    int case_number = 1;
    while (cin >> n >> m)
    {
        vector<vector<int>> board(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                char num;
                cin >> num;
                if (num == '*')
                    board[i][j] = 1;
                else
                {
                    board[i][j] = 0;
                }
            }
        }
        int ans = 100;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] != 0)
                    continue;
                board[i][j] = 1;
                ans = min(ans, go(board, 0, i, j));
                board[i][j] = 0;
            }
        }
        cout << "Case " << case_number << ": ";
        if (ans != 100)
            cout << ans << endl;
        else
        {
            cout << "-1" << endl;
        }
        case_number++;
    }
    return 0;
}