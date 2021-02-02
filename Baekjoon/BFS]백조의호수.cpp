#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int board[1501][1501];
int swan_water[1501][1501];
int check[1501][1501];
int n, m;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, 1, -1};

int main(void)
{
    cin >> n >> m;
    memset(check, -1, sizeof(check));
    memset(swan_water, 0, sizeof(swan_water));
    int swan = 1;
    vector<tuple<int, int, int>> swans;
    for (int i = 0; i < n; i++)
    {
        string buf;
        cin >> buf;
        for (int j = 0; j < m; j++)
        {
            if (buf[j] == '.')
                board[i][j] = 0;
            else if (buf[j] == 'X')
                board[i][j] = 1;
            else
            {
                board[i][j] = 2;
                swans.push_back(make_tuple(i, j, swan));
                swan_water[i][j] = swan++;
            }
            // cout<<board[i][j]<<" ";
        }
        // cout<<endl;
    }
    queue<tuple<int, int, int>> swan_property;
    for (int i = 0; i < 2; i++)
    {
        int y, x, swan_id;
        tie(y, x, swan_id) = swans[i];
        swan_property.push(make_tuple(y, x, swan_id));
    }
    while (!swan_property.empty())
    {
        int y, x, swan_id;
        tie(y, x, swan_id) = swan_property.front();
        swan_property.pop();
        for (int i = 0; i < 4; i++)
        {
            int newy = y + dy[i];
            int newx = x + dx[i];
            if (newy >= 0 && newx >= 0 && newy < n && newx < m && board[newy][newx] == 0 && swan_water[newy][newx] == 0)
            {
                swan_property.push(make_tuple(newy, newx, swan_id));
                swan_water[newy][newx] = swan_id;
            }
        }
    }

    queue<pair<int, int>> melting_ice;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] != 1)
                continue;
            for (int k = 0; k < 4; k++)
            {
                int y_dir = i + dy[k];
                int x_dir = j + dx[k];
                if (y_dir < 0 || y_dir >= n || x_dir < 0 || x_dir >= m)
                    continue;
                if (board[y_dir][x_dir] != 1)
                {
                    melting_ice.push(make_pair(i, j));
                    check[i][j] = 1;
                    break;
                }
            }
        }
    }
    for (int days = 0;; days++)
    {
        queue<pair<int, int>> next_melting;
        vector<pair<int, int>> melt;
        while (!melting_ice.empty())
        {
            int y, x;
            tie(y, x) = melting_ice.front();
            melt.push_back(make_pair(y, x));
            melting_ice.pop();
            int swan_id = 0;
            for (int i = 0; i < 4; i++)
            {
                int newy = y + dy[i];
                int newx = x + dx[i];
                if (newy >= 0 && newx >= 0 && newy < n && newx < m)
                {
                    if (board[newy][newx] == 1 && check[newy][newx] == -1)
                    {
                        next_melting.push(make_pair(newy, newx));
                        check[newy][newx] = 1;
                    }
                    if (board[newy][newx] == 0 && swan_water[newy][newx] > 0 && swan_id != swan_water[newy][newx])
                    {
                        swan_id += swan_water[newy][newx];
                        if (swan_id == 3)
                        {
                            cout << days + 1 << endl;
                            return 0;
                        }
                    }
                }
            }
            swan_water[y][x] = swan_id;
        }
        for (auto &ice : melt)
        {
            board[ice.first][ice.second] = 0;
        }
        melting_ice = next_melting;
    }

    return 0;
}