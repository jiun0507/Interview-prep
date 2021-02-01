// 16952 체스판여행 2
// baekjoon

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int luke_y[4] = {1, -1, 0, 0}; //0
int luke_x[4] = {0, 0, -1, 1};
int bishop_y[4] = {1, 1, -1, -1}; //1
int bishop_x[4] = {-1, 1, -1, 1};
int knight_y[8] = {-2, -2, -1, -1, 1, 1, 2, 2}; //2
int knight_x[8] = {1, -1, 2, -2, 2, -2, 1, -1};

int check[11][11][101][3][21];
int board[11][11];
int n;

int main(void)
{
    cin >> n;
    vector<pair<int, int>> numbers(n * n + 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
            numbers[board[i][j]] = make_pair(i, j);
        }
    }
    memset(check, -1, sizeof(check));
    queue<tuple<int, int, int, int, int>> q; // y, x, what number we reached, previous move, switches
    int starty = numbers[1].first;
    int startx = numbers[1].second;
    for (int i = 0; i < 3; i++)
    {
        q.push(make_tuple(starty, startx, 1, i, 0));
        check[starty][startx][1][i][0] = 0;
    }

    while (!q.empty())
    {
        int y, x, num, prev, switches;
        tie(y, x, num, prev, switches) = q.front();
        q.pop();
        if (switches > 2 * n)
            continue;
        // rook
        for (int i = 0; i < 4; i++)
        {
            if (prev != 0)
                break;
            int j = 1;
            while (true)
            {
                int newy = y + luke_y[i] * j;
                int newx = x + luke_x[i] * j;
                j++;
                if (newy >= 0 && newx >= 0 && newy < n && newx < n)
                {
                    int next_num = num;
                    if (board[newy][newx] == num + 1)
                        next_num++;
                    if (check[newy][newx][next_num][prev][switches] != -1)
                        continue;
                    q.push(make_tuple(newy, newx, next_num, prev, switches));
                    check[newy][newx][next_num][prev][switches] = check[y][x][num][prev][switches] + 1;
                }
                else
                {
                    break;
                }
            }
        }
        // bishop
        for (int i = 0; i < 4; i++)
        {
            if (prev != 1)
                break;
            int j = 1;
            while (true)
            {
                int newy = y + bishop_y[i] * j;
                int newx = x + bishop_x[i] * j;
                j++;
                if (newy >= 0 && newx >= 0 && newy < n && newx < n)
                {
                    int next_num = num;
                    if (board[newy][newx] == num + 1)
                        next_num++;
                    if (check[newy][newx][next_num][prev][switches] != -1)
                        continue;
                    q.push(make_tuple(newy, newx, next_num, prev, switches));
                    check[newy][newx][next_num][prev][switches] = check[y][x][num][prev][switches] + 1;
                }
                else
                {
                    break;
                }
            }
        }
        // knight
        for (int i = 0; i < 8; i++)
        {
            if (prev != 2)
                break;
            int newy = y + knight_y[i];
            int newx = x + knight_x[i];
            if (newy >= 0 && newx >= 0 && newy < n && newx < n)
            {
                int next_num = num;
                if (board[newy][newx] == num + 1)
                    next_num++;
                if (check[newy][newx][next_num][prev][switches] != -1)
                    continue;
                q.push(make_tuple(newy, newx, next_num, prev, switches));
                check[newy][newx][next_num][prev][switches] = check[y][x][num][prev][switches] + 1;
            }
        }
        for (int i = 0; i <= 2; i++)
        {
            if (i == prev)
                continue;
            int next_switches = switches + 1;
            if (check[y][x][num][i][next_switches] != -1)
                continue;
            q.push(make_tuple(y, x, num, i, next_switches));
            check[y][x][num][i][next_switches] = check[y][x][num][prev][switches] + 1;
        }
    }
    vector<pair<int, int>> ans;
    int desty, destx;
    tie(desty, destx) = numbers[n * n];
    for (int i = 0; i <= 2 * n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (check[desty][destx][n * n][j][i] != -1)
            {
                ans.push_back(make_pair(check[desty][destx][n * n][j][i], i));
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans[0].first << " " << ans[0].second << endl;

    return 0;
}