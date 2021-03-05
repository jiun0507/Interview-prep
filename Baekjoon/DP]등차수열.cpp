// 1994 등차수열
// baekjoon
#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

int n, k;
int dp[2001][2001];
vector<int> vals;

int main()
{
    memset(dp, -1, sizeof(dp));
    cin >> n;
    map<int, int> finder;
    vector<int> buf;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        buf.push_back(num);
    }
    int mx = 1;
    int index = 0;
    sort(buf.begin(), buf.end());
    int cnt = 1;
    for (int i = 0; i < n; i++)
    {
        if (index == 0 || buf[i - 1] < buf[i])
        {
            vals.push_back(buf[i]);
            finder[buf[i]] = index;
            index++;
            cnt = 1;
        }
        else
        {
            cnt++;
            mx = max(mx, cnt);
        }
    }
    for (int i = 1; i < vals.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            int diff = vals[i] - vals[j];
            if (diff > vals[j])
            {
                dp[i][j] = 2;
                continue;
            }
            map<int, int>::iterator it = finder.lower_bound(vals[j] - diff);
            if (it->first != vals[j] - diff)
            {
                dp[i][j] = 2;
            }
            else
            {
                dp[i][j] = 1 + dp[j][it->second];
            }
            if (mx < dp[i][j])
                mx = dp[i][j];
        }
    }
    cout << mx << "\n";
    return 0;
}
