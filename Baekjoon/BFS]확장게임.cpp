// 16920 확장게임
// baekjoon

#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

int n, m, p;
int player_moves[10];
char board[1001][1001];
int check[1001][1001];
queue<pair<int, int>> players[10];

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int main()
{
    memset(check, -1, sizeof(check));
    cin >> n >> m >> p;
    for (int i = 1; i <= p; i++)
    {
        cin >> player_moves[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> board[i];
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] != '.' && board[i][j] != '#')
            {
                int pnum = board[i][j] - '0';
                check[i][j] = pnum;
                players[pnum].push(make_pair(i, j));
            }
        }
    }

    while (true)
    {
        bool gamestop = true;
        for (int pnum = 1; pnum <= p; pnum++)
        {
            for (int turn = 0; turn < player_moves[pnum]; turn++)
            {
                queue<pair<int, int>> new_moves;
                while (!players[pnum].empty())
                {
                    int y = players[pnum].front().first;
                    int x = players[pnum].front().second;
                    players[pnum].pop();
                    for (int i = 0; i < 4; i++)
                    {
                        int newy = y + dy[i];
                        int newx = x + dx[i];
                        if (newy >= 0 && newx >= 0 && newy < n && newx < m)
                        {
                            if (check[newy][newx] != -1)
                                continue;
                            if (board[newy][newx] == '.')
                            {
                                gamestop = false;
                                new_moves.push(make_pair(newy, newx));
                                check[newy][newx] = pnum;
                            }
                        }
                    }
                }
                if (new_moves.empty())
                    break;
                players[pnum] = new_moves;
                new_moves = queue<pair<int, int>>();
            }
        }
        if (gamestop)
            break;
    }
    int ans[10] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (check[i][j] != -1)
            {
                ans[check[i][j]]++;
            }
        }
    }
    for (int i = 1; i <= p; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
