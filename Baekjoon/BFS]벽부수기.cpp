#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int n, m;
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
int check[1001][1001][2] = {0};

void bfs(vector<vector<int>> &board)
{
    tuple<int, int, int> start = make_tuple(0, 0, 0);
    deque<tuple<int, int, int>> next;
    next.push_back(start);
    check[0][0][0] = 1;
    while (!next.empty())
    {
        auto cur = next.front();
        int y = get<0>(cur);
        int x = get<1>(cur);
        int wall = get<2>(cur);
        if (y == n - 1 && x == m - 1)
            return;
        next.pop_front();
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny >= 0 && ny < n && nx >= 0 && nx < m)
            {
                if (board[ny][nx] == 0 && check[ny][nx][wall] == 0)
                {
                    check[ny][nx][wall] = check[y][x][wall] + 1;
                    next.push_back(make_tuple(ny, nx, wall));
                }
                else
                {
                    if (wall == 0 && check[ny][nx][wall + 1] == 0)
                    {
                        check[ny][nx][wall + 1] = check[y][x][wall] + 1;
                        next.push_back(make_tuple(ny, nx, wall + 1));
                    }
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    vector<vector<int>> board(n, vector<int>(m));
    string line;
    for (int i = 0; i < n; i++)
    {
        cin >> line;
        for (int j = 0; j < m; j++)
        {
            if (line.at(j) == '0')
                board[i][j] = 0;
            else
            {
                board[i][j] = 1;
            }
        }
    }
    bfs(board);
    // for(int i=0;i<n;i++){
    //     for(int j = 0;j<m;j++){
    //         cout<<check[i][j][0]<<" ";
    //     }
    //     cout<<endl;
    // }
    // for(int i=0;i<n;i++){
    //     for(int j = 0;j<m;j++){
    //         cout<<check[i][j][1]<<" ";
    //     }
    //     cout<<endl;
    // }
    int nowall = check[n - 1][m - 1][0];
    int onewall = check[n - 1][m - 1][1];
    // cout<<nowall<<" "<<onewall<<endl;
    if (nowall != 0 && onewall != 0)
    {
        cout << min(nowall, onewall) << endl;
    }
    else if (nowall + onewall != 0)
    {
        cout << max(nowall, onewall) << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}