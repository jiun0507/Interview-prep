##16932##모양만들기

#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
    using namespace std;

int n, m;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void BFSFind(vector<vector<int>> &board, pair<int, int> one, vector<vector<pair<int, int>>> &origins)
{
    deque<pair<int, int>> ones;
    ones.push_back(one);
    origins[one.first][one.second] = one;
    int num = 1;
    while (!ones.empty())
    {
        auto cur = ones.front();
        int y = cur.first;
        int x = cur.second;
        ones.pop_front();
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny >= 0 && ny < n && nx >= 0 && nx < m)
            {
                if (board[ny][nx] == 0 || origins[ny][nx].first != -1)
                    continue;
                if (board[ny][nx] == 1)
                {
                    ones.push_back(make_pair(ny, nx));
                    origins[ny][nx] = one;
                    num++;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (origins[i][j] == one)
            {
                board[i][j] = num;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    vector<vector<int>> board;
    vector<vector<pair<int, int>>> origins;
    for (int i = 0; i < n; i++)
    {
        vector<int> line;
        vector<pair<int, int>> pairs;
        for (int j = 0; j < m; j++)
        {
            int num;
            cin >> num;
            line.push_back(num);
            pairs.push_back(make_pair(-1, -1));
        }
        board.push_back(line);
        origins.push_back(pairs);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 1)
            {
                if (origins[i][j].first != -1)
                    continue;
                BFSFind(board, make_pair(i, j), origins);
            }
        }
    }
    // for(int i = 0;i<n;i++){
    //     for(int j = 0;j<m;j++){
    //         cout<<board[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] != 0)
            {
                if (max < board[i][j])
                    max = board[i][j];
            }
            else
            {
                int sum = 1;
                vector<pair<int, int>> done;
                for (int k = 0; k < 4; k++)
                {
                    int ny = i + dy[k];
                    int nx = j + dx[k];
                    if (ny >= 0 && ny < n && nx >= 0 && nx < m)
                    {
                        pair<int, int> cur_origin = origins[ny][nx];
                        bool already_done = false;
                        for (int d = 0; d < done.size(); d++)
                        {
                            if (cur_origin.first == done[d].first && cur_origin.second == done[d].second)
                            {
                                already_done = true;
                            }
                        }
                        if (already_done)
                            continue;
                        done.push_back(cur_origin);
                        sum += board[ny][nx];
                    }
                }
                if (max < sum)
                    max = sum;
            }
        }
    }
    cout << max << endl;
    return 0;
}