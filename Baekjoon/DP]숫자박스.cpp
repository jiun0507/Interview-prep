// 1983 숫자 박스
// baekjoon

#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

int dp[401][401][401];
int board[2][401];
int up;
int down;
int n;
bool check[401][401][401];
int minimum = -1000000007;
int main()
{
    cin >> n;
    up = down = 0;
    for (int j = 0; j < n; j++)
    {
        int num;
        cin >> num;
        if (num != 0)
        {
            board[0][up] = num;
            up += 1;
        }
    }
    for (int j = 0; j < n; j++)
    {
        int num;
        cin >> num;
        if (num != 0)
        {
            board[1][down] = num;
            down += 1;
        }
    }
    fill(&dp[0][0][0], &dp[400][400][400] + 1, minimum);

    dp[0][0][0] = 0;
    check[0][0][0] = 1;
    for (int index = 0; index < n; index++)
    {
        for (int i = 0; i <= up; i++)
        {
            for (int j = 0; j <= down; j++)
            {
                if (check[index][i][j])
                {
                    if (i < up)
                    {
                        if (dp[index + 1][i + 1][j] < dp[index][i][j])
                        {
                            dp[index + 1][i + 1][j] = dp[index][i][j];
                            check[index + 1][i + 1][j] = 1;
                        }
                    }
                    if (j < down)
                    {
                        if (dp[index + 1][i][j + 1] < dp[index][i][j])
                            dp[index + 1][i][j + 1] = dp[index][i][j];
                        check[index + 1][i][j + 1] = 1;
                    }
                    if (i < up && j < down)
                    {
                        if (dp[index + 1][i + 1][j + 1] < dp[index][i][j] + board[0][i] * board[1][j])
                        {
                            dp[index + 1][i + 1][j + 1] = dp[index][i][j] + board[0][i] * board[1][j];
                            check[index + 1][i + 1][j + 1] = 1;
                        }
                    }
                    if (dp[index + 1][i][j] < dp[index][i][j])
                    {
                        dp[index + 1][i][j] = dp[index][i][j];
                        check[index + 1][i][j] = 1;
                    }
                }
            }
        }
    }
    cout << dp[n][up][down] << "\n";
    return 0;
}
