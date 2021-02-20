// 2494 숫자 맞추기
// baekjoon

#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

int dp[10010][10];
int shifts[10010][10];
int n;
string start, goal;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dp, -1, sizeof(dp));
    cin >> n;
    cin >> start >> goal;
    dp[0][0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (dp[i][j] == -1)
                continue;
            int cur = start[i] - '0';
            int end = goal[i] - '0';
            cur += j;
            cur %= 10;
            int left = (end - cur + 10) % 10;
            int right = (cur - end + 10) % 10;
            int newj = (j + left + 10) % 10;
            if (dp[i + 1][newj] == -1 || (dp[i + 1][newj] != -1 && dp[i + 1][newj] > dp[i][j] + left))
            {
                dp[i + 1][newj] = dp[i][j] + left;
                shifts[i + 1][newj] = left;
            }
            if (dp[i + 1][j] == -1 || (dp[i + 1][j] != -1 && dp[i + 1][j] > dp[i][j] + right))
            {
                dp[i + 1][j] = dp[i][j] + right;
                shifts[i + 1][j] = -right;
            }
        }
    }
    int ans = 100000000;
    int left_shift;
    int index = n;
    for (int i = 0; i < 10; i++)
    {
        if (ans > dp[n][i] && dp[n][i] != -1)
        {
            ans = dp[n][i];
            left_shift = i;
        }
    }
    vector<int> ans_vec;
    int total = 0;
    while (index > 0)
    {
        ans_vec.push_back(shifts[index][left_shift]);
        if (shifts[index][left_shift] > 0)
        {
            total += shifts[index][left_shift];
            left_shift = (left_shift + 10 - shifts[index][left_shift]) % 10;
        }
        else
        {
            total -= shifts[index][left_shift];
        }
        index--;
    }
    cout << total << "\n";
    reverse(ans_vec.begin(), ans_vec.end());
    for (int i = 0; i < ans_vec.size(); i++)
    {
        cout << i + 1 << " " << ans_vec[i] << "\n";
    }
    return 0;
}
