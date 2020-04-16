//baekjoon 16236
//아기상어

#include <iostream>
#include <tuple>
#include <algorithm>
#include <cstring>
#include <queue>
#include <string>

using namespace std;
int water[20][20];
int d[20][20];
int n;
int dx[] = {0, -1, 1, 0};
int dy[] = {-1, 0, 0, 1};
int sy, sx, doy, dox;
int ssize = 2;
int eaten = 0;
bool check_range(int y, int x)
{
    return y >= 0 && y < n && x >= 0 && x < n;
}

tuple<int, int, int> nextfish(int a, int b)
{
    vector<tuple<int, int, int>> ans;
    memset(d, -1, sizeof(d));
    queue<pair<int, int>> q;
    q.push(make_pair(a, b));
    d[a][b] = 0;
    while (!q.empty())
    {
        int y, x;
        tie(y, x) = q.front();
        q.pop();
        if (water[y][x] != 0 && water[y][x] < ssize)
        {
            ans.push_back(make_tuple(d[y][x], y, x));
        }
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (!check_range(ny, nx))
                continue;
            if (d[ny][nx] > 0)
                continue;
            if (water[ny][nx] > ssize)
                continue;
            d[ny][nx] = 1 + d[y][x];
            q.push(make_pair(ny, nx));
        }
    }
    if (ans.empty())
    {
        return make_tuple(-1, -1, -1);
    }
    else
    {
        sort(ans.begin(), ans.end());
        return ans[0];
    }
}

int main()
{
    cin >> n;
    int shy, shx;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> water[i][j];
            if (water[i][j] == 9)
            {
                shy = i;
                shx = j;
                water[i][j] = 0;
            }
        }
    }
    int cnt = 0;
    while (true)
    {
        auto p = nextfish(shy, shx);
        int temp;
        tie(temp, shy, shx) = p;
        if (temp == -1)
            break;
        cnt += temp;
        water[shy][shx] = 0;
        eaten++;
        if (eaten == ssize)
        {
            eaten = 0;
            ssize++;
        }
        // for(int i = 0;i<n;i++){
        //     for(int j = 0;j<n;j++){
        //         cout<<water[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        // cout<<"\n";
    }
    cout << cnt << "\n";
    return 0;
}