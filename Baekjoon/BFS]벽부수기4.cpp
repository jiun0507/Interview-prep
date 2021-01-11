#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int n, m;
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
int check[1001][1001] = {0};
int board[1001][1001];

void bfs(int a, int b, int label)
{
    pair<int, int> start = make_pair(a, b);
    deque<pair<int, int>> next;
    next.push_back(start);
    check[a][b] = label;
    while (!next.empty())
    {
        auto cur = next.front();
        int y = cur.first;
        int x = cur.second;
        next.pop_front();
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny >= 0 && ny < n && nx >= 0 && nx < m)
            {
                if (board[ny][nx] == 0 && check[ny][nx] == 0)
                {
                    check[ny][nx] = label;
                    next.push_back(make_pair(ny, nx));
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
    int label = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 0 && check[i][j] == 0)
            {
                bfs(i, j, label);
                label++;
            }
        }
    }
    int labellib[label] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (check[i][j] != 0)
            {
                labellib[check[i][j]] += 1;
            }
        }
    }
    int newboard[n][m] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 0)
                continue;
            int sum = 1;
            vector<int> cone;

            for (int k = 0; k < 4; k++)
            {
                int ny = i + dy[k];
                int nx = j + dx[k];
                if (ny >= 0 && ny < n && nx >= 0 && nx < m)
                {
                    if (board[ny][nx] == 0)
                        cone.push_back(check[ny][nx]);
                }
            }
            sort(cone.begin(), cone.end());
            cone.erase(unique(cone.begin(), cone.end()), cone.end());
            for (int k : cone)
            {
                sum += labellib[k];
            }
            newboard[i][j] = sum;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << newboard[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}