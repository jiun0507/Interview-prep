//baekjoon 16924
//십자가 찾기
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int n, m;
int check[100][100];
bool board[100][100];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, -1, 1};

bool bounds(int y, int x, int length)
{
    if (y + length >= n || y - length < 0)
        return false;
    else if (x + length >= m || x - length < 0)
        return false;
    else
    {
        return true;
    }
}

bool crosscheck(int y, int x, int length)
{
    for (int dir = 0; dir < 4; dir++)
    {
        if (!board[y + length * dy[dir]][x + length * dx[dir]])
            return false;
    }
    for (int dir = 0; dir < 4; dir++)
    {
        if (!check[y + length * dy[dir]][x + length * dx[dir]])
        {
            check[y + length * dy[dir]][x + length * dx[dir]] = true;
        }
    }
    check[y][x] = length + 1;
    return true;
}

int main()
{
    cin >> n >> m;
    string buf;
    for (int i = 0; i < n; i++)
    {
        cin >> buf;
        for (int j = 0; j < m; j++)
        {
            if (buf.at(j) == '*')
                board[i][j] = true;
        }
    }
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < m - 1; j++)
        {
            if (!board[i][j])
                continue;
            for (int k = 1;; k++)
            {
                if (!bounds(i, j, k))
                    break;
                if (!crosscheck(i, j, k))
                    break;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((board[i][j] && check[i][j] == 0) || (!board[i][j] && check[i][j] > 0))
            {
                cout << -1 << endl;
                return 0;
            }
            if (check[i][j] > 1)
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (check[i][j] > 1)
            {
                cout << i + 1 << " " << j + 1 << " " << check[i][j] - 1 << endl;
            }
        }
    }
    return 0;
}