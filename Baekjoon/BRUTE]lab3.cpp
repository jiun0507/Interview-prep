//baekjoon 17142
//연구소 3
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int n, m;
int board[101][101];
int dy[] = {0, 0, -1, 1};
int dx[] = {1, -1, 0, 0};

void BFS(vector<vector<int>> &cur, queue<pair<int, int>> &q)
{
    while (!q.empty())
    {
        auto p = q.front();
        int y = p.first;
        int x = p.second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int newy = y + dy[i];
            int newx = x + dx[i];
            if (newy >= 0 && newy < n && newx >= 0 & newx < n)
            {
                if (cur[newy][newx] == -2)
                    continue;
                if (cur[newy][newx] == -1)
                {
                    cur[newy][newx] = cur[y][x] + 1;
                    q.push(make_pair(newy, newx));
                }
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    vector<vector<int>> d(n, vector<int>(n, -1));
    vector<pair<int, int>> spots;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 1)
            {
                d[i][j] = -2;
            }
            if (board[i][j] == 2)
            {
                spots.push_back(make_pair(i, j));
            }
        }
    }
    vector<int> combi;
    for (int i = 0; i < m; i++)
    {
        combi.push_back(1);
    }
    for (int i = 0; i < spots.size() - m; i++)
    {
        combi.push_back(0);
    }

    sort(combi.begin(), combi.end());
    int ans = -1;
    do
    {
        vector<vector<int>> cur = d;
        queue<pair<int, int>> q;
        for (int i = 0; i < combi.size(); i++)
        {
            if (combi[i] == 1)
            {
                cur[spots[i].first][spots[i].second] = 0;
                q.push(make_pair(spots[i].first, spots[i].second));
            }
        }

        BFS(cur, q);

        bool full = true;
        int mx = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (cur[i][j] == -1)
                {
                    full = false;
                    break;
                }
                if (board[i][j] == 2 && cur[i][j] != 0)
                {
                    continue;
                }
                if (cur[i][j] > mx)
                    mx = cur[i][j];
            }
        }
        if (full && (ans == -1 || ans > mx))
        {
            ans = mx;
        }

    } while (next_permutation(combi.begin(), combi.end()));
    cout << ans << "\n";
}