// 2922 즐거운 단어
// baekjoon

#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

long long dp[101][2][2][2]; //index, has L, index-2 vowel or consonant, index-1 vowel or consonant
int board[101];
string input;
int n;

int main()

{
    bool hasL = false;
    string vowels = "AEIOU";
    cin >> input;
    for (int i = 0; i < input.size(); i++)
    {
        if (vowels.find(input.at(i)) != string::npos)
        {
            board[i] = 0;
        }
        else
        {
            if (input.at(i) == '_')
            {
                board[i] = 2;
            }
            else
            {
                if (input.at(i) == 'L')
                {
                    hasL = true;
                }
                board[i] = 1;
            }
        }
    }
    n = input.size();
    dp[0][hasL][1][1] = 1LL;
    dp[0][hasL][0][0] = 1LL;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int prev2 = 0; prev2 < 2; prev2++)
            {
                for (int prev = 0; prev < 2; prev++)
                {
                    if (dp[i][j][prev2][prev] == 0)
                        continue;
                    if (board[i] != 2)
                    {
                        if (prev != prev2 || prev != board[i])
                        {
                            dp[i + 1][j][prev][board[i]] += dp[i][j][prev2][prev];
                        }
                        continue;
                    }
                    int choices[2] = {1, 1};
                    if (prev == prev2)
                    {
                        choices[prev] = 0;
                    }
                    if (choices[1] == 1LL)
                    {
                        dp[i + 1][1][prev][1] += dp[i][j][prev2][prev];
                        dp[i + 1][j][prev][1] += 20 * dp[i][j][prev2][prev];
                    }
                    if (choices[0] == 1LL)
                    {
                        dp[i + 1][j][prev][0] += 5 * dp[i][j][prev2][prev];
                    }
                }
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            ans += dp[n][1][i][j];
        }
    }
    cout << ans << "\n";
    return 0;
}
