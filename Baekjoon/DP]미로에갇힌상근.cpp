// 5069 미로에 갇힌 상근
// baekjoon

#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

int dy[6] = {1, 0, -1, -1, 0, 1};
int dx[6] = {0, 1, 1, 0, -1, -1};
int dp[16][32][32]; // steps, y, x the number of ways of geting to y, x coordinate using steps.

int main()

{
    int t;
    cin >> t;
    int maxi = 0;
    vector<int> questions;
    while (t--)
    {
        int n;
        cin >> n;
        questions.push_back(n);
    }
    dp[0][14][14] = 1;
    for (int i = 0; i <= 14; i++)
    {
        for (int j = 1; j <= 30; j++)
        {
            for (int k = 0; k <= 30; k++)
            {
                if (dp[i][j][k] == 0)
                    continue;
                for (int move = 0; move < 6; move++)
                {
                    int nx = j + dx[move];
                    int ny = k + dy[move];
                    if (ny >= 0 && nx >= 0 && ny <= 30 && nx <= 30)
                    {
                        dp[i + 1][nx][ny] += dp[i][j][k];
                    }
                }
            }
        }
    }
    for (auto q : questions)
    {
        cout << dp[q][14][14] << "\n";
    }
    return 0;
}
