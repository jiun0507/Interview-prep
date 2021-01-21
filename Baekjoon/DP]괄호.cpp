//baekjoon 10422
//괄호
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n;
int questions[101];
long long dp[5001];
const long long mod = 1000000007;

long long brackets(int length)
{
    long long &ans = dp[length];
    if (ans != -1)
        return ans;
    ans = 0;
    for (int i = 2; i <= length; i += 2)
    {
        ans += brackets(i - 2) * brackets(length - i);
        ans %= mod;
    }
    return ans;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    memset(dp, -1, sizeof(dp));
    dp[0] = 1;
    dp[2] = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> questions[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (questions[i] % 2 != 0)
            cout << 0 << endl;
        else
        {
            cout << brackets(questions[i]) << endl;
        }
    }
    return 0;
}