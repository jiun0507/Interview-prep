//baekjoon 14238
//출근기록

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string s;
int n;
int alphabets[3] = {0};

int dp[51][51][51][3][3];
string letters[3] = {"A", "B", "C"};
string ans = "";

bool go(int a, int b, int c, int prev, int prev2)
{
    if (a + b + c >= alphabets[0] + alphabets[1] + alphabets[2])
    {
        if (a == alphabets[0] && b == alphabets[1] && c == alphabets[2])
        {
            dp[a][b][c][prev][prev2] = 1;
            cout << ans << endl;
            return true;
        }
        else
        {
            dp[a][b][c][prev][prev2] = 2;
            return false;
        }
    }
    if (dp[a][b][c][prev][prev2])
    {
        if (dp[a][b][c][prev][prev2] == 2)
        {
            return false;
        }
        return true;
    }
    ans[a + b + c] = 'A';
    if (a < alphabets[0])
    {
        if (go(a + 1, b, c, 0, prev))
        {
            dp[a + 1][b][c][0][prev] = 1;
            return true;
        }
        else
        {
            dp[a + 1][b][c][0][prev] = 2;
        }
    }
    ans[a + b + c] = 'B';
    if (prev != 1 && b < alphabets[1])
    {
        if (go(a, b + 1, c, 1, prev))
        {
            dp[a][b + 1][c][1][prev] = 1;
            return true;
        }
        else
        {
            dp[a][b + 1][c][1][prev] = 2;
        }
    }
    ans[a + b + c] = 'C';
    if (prev != 2 && prev2 != 2 && c < alphabets[2])
    {
        if (go(a, b, c + 1, 2, prev))
        {
            dp[a][b][c + 1][2][prev] = 1;
            return true;
        }
        else
        {
            dp[a][b][c + 1][2][prev] = 2;
        }
    }
    dp[a][b][c][prev][prev2] = 2;
    return false;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'A')
            alphabets[0]++;
        else if (s[i] == 'B')
            alphabets[1]++;
        else
        {
            alphabets[2]++;
        }
    }
    if (alphabets[0] + alphabets[1] + alphabets[2] == 1)
    {
        if (alphabets[0])
            cout << 'A' << endl;
        if (alphabets[1])
            cout << 'B' << endl;
        if (alphabets[2])
            cout << 'C' << endl;
    }
    for (int i = 0; i < alphabets[0] + alphabets[1] + alphabets[2]; i++)
    {
        ans += 'A';
    }
    if (!go(0, 0, 0, 0, 0))
    {
        cout << "-1" << endl;
    }

    return 0;
}