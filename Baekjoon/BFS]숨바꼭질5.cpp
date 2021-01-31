// 17071
// 숨바꼭질 5
// baekjoon

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int check[500001][2];

int main(void)
{
    int n, k;
    cin >> n >> k;
    memset(check, -1, sizeof(check));
    if (n == k)
    {
        cout << "0";
        return 0;
    }

    queue<pair<int, int>> q;
    q.push(make_pair(n, 0));
    check[n][0] = 0;
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        int now = cur.first;
        int t = cur.second;
        int dist = check[now][t];
        int new_dist = dist + 1;
        for (int y : {now - 1, now + 1, 2 * now})
        {
            if (y >= 0 && y <= 500000)
            {
                if (check[y][1 - t] == -1)
                {
                    check[y][1 - t] = new_dist;
                    q.push(make_pair(y, 1 - t));
                }
            }
        }
    }
    for (int t = 1;; t++)
    {
        k += t;
        if (k >= 500001)
            break;
        if (check[k][t % 2] != -1 && check[k][t % 2] <= t)
        {
            cout << t << endl;
            return 0;
        }
    }
    cout << -1;
    return 0;
}
