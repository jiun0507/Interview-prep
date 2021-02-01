// 12851 숨바꼭질 2
// baekjoon

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int check[100001][2]; // 0: number of steps, 1: number of ways
int n, k;

int main(void)
{
    memset(check, -1, sizeof(check));
    cin >> n >> k;
    queue<pair<int, int>> q; // current location, number of steps
    q.push(make_pair(n, 0));
    check[n][0] = 0;
    check[n][1] = 1;
    int least = 200000;
    while (!q.empty())
    {
        int cur, steps;
        tie(cur, steps) = q.front();
        q.pop();
        if (least < steps)
            break;
        if (cur == k)
            least = steps;
        for (int next : {cur + 1, cur - 1, 2 * cur})
        {
            if (next < 0 || next > 100000)
                continue;
            if (check[next][0] == -1)
            {
                check[next][0] = steps + 1;
                check[next][1] = check[cur][1];
                q.push(make_pair(next, steps + 1));
            }
            else
            {
                if (check[next][0] == steps + 1)
                {
                    check[next][1] += check[cur][1];
                }
            }
        }
    }
    cout << check[k][0] << endl;
    cout << check[k][1] << endl;
    return 0;
}