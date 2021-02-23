// 2922 즐거운 단어
// baekjoon

#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

long long dp[101][2][3][3]; //index, has L, index-2 vowel or consonant, index-1 vowel or consonant
int board[101];
string input;
int n;

long long go(int index, int hasl, int prev2, int prev)
{
    if (index == n)
    {
        if (hasl == 1)
            return 1;
        return 0;
    }
    if (dp[index][hasl][prev2][prev] != -1)
        return dp[index][hasl][prev2][prev];
    long long &ret = dp[index][hasl][prev2][prev];
    int choices[3] = {0, 1, 1}; //vowel, consonant
    if (board[index] != 3)
    {
        if (prev2 == prev && prev == board[index])
        {
            return ret = 0;
        }
        return ret = go(index + 1, (hasl | (input.at(index) == 'L')), prev, board[index]);
    }
    ret = 0LL;
    if (prev == prev2)
    {
        choices[prev] = 0;
    }
    if (choices[1])
    {
        ret += 5 * go(index + 1, hasl, prev, 1);
    }
    if (choices[2])
    {
        ret += 20 * go(index + 1, hasl, prev, 2);
        ret += go(index + 1, 1, prev, 2);
    }
    return ret;
}

int main()

{
    string vowels = "AEIOU";
    cin >> input;
    for (int i = 0; i < input.size(); i++)
    {
        if (vowels.find(input.at(i)) != string::npos)
        {
            board[i] = 1;
        }
        else
        {
            if (input.at(i) == '_')
            {
                board[i] = 3;
            }
            else
            {
                board[i] = 2;
            }
        }
    }
    memset(dp, -1, sizeof(dp));
    n = input.size();

    cout << go(0, 0, 0, 0) << "\n";
    return 0;
}
