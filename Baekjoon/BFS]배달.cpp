// 1175 배달
// baekjoon

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, -1, 1};

//y, x, direction, delivered
//delivered: 0 none, 1 first one delivered, 2 second one delivered, 3 done.
int check[51][51][4][4];
int board[51][51];
vector<pair<int, int>> d;
int n, m;

int main(void)
{
    cin >> n >> m;
    int starty, startx;
    int delivered = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char buf;
            cin >> buf;
            if (buf == 'S')
            {
                board[i][j] = 3;
                starty = i;
                startx = j;
            }
            else if (buf == 'C')
            {
                board[i][j] = delivered;
                delivered++;
                d.push_back(make_pair(i, j));
            }
            else if (buf == '#')
            {
                board[i][j] = 4;
            }
            else
            {
                board[i][j] = 0;
            }
        }
    }

    memset(check, -1, sizeof(check));

    queue<tuple<int, int, int, int>> q; // y, x, direction, delivered
    for (int i = 0; i < 4; i++)
    {
        check[starty][startx][i][0] = 0;
        q.push(make_tuple(starty, startx, i, 0));
    }
    int ans = -1;
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        int y = get<0>(cur);
        int x = get<1>(cur);
        int direction = get<2>(cur);
        int delivered = get<3>(cur);
        if (delivered == 3)
        {
            ans = check[y][x][direction][delivered];
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            if (i == direction)
                continue;
            int newy = y + dy[i];
            int newx = x + dx[i];
            if (board[newy][newx] == 4)
                continue;
            if (newy >= 0 && newy < n && newx >= 0 && newx < m)
            {
                int next_delivered = delivered;
                if (board[newy][newx] == 1 || board[newy][newx] == 2)
                {
                    if (delivered != board[newy][newx])
                        next_delivered += board[newy][newx];
                }
                if (check[newy][newx][i][next_delivered] == -1)
                {
                    check[newy][newx][i][next_delivered] = check[y][x][direction][delivered] + 1;
                    q.push(make_tuple(newy, newx, i, next_delivered));
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}