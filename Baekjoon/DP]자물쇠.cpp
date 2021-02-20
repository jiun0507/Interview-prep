// 1514 자물쇠
// baekjoon

#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

int dp[110][10][10];
int n;
string start, goal;
int turns[10] = {0, 1, 1, 1, 2, 2, 2, 1, 1, 1};

void change(int i, int b, int c, int val)
{
    if (dp[i][b][c] == -1 || (dp[i][b][c] != -1 && dp[i][b][c] > val))
    {
        dp[i][b][c] = val;
    }
}

int go(int i, int j, int k)
{
    if (i == n)
    {
        return 0;
    }
    if (dp[i][j][k] != -1)
        return dp[i][j][k];
    int &ret = dp[i][j][k];
    int cur = start[i] - '0';
    cur = (cur + j) % 10;
    int end = goal[i] - '0';
    for (int three = 0; three < 10; three++)
    {
        for (int two = 0; two < 10; two++)
        {
            int total_turns = turns[three] + turns[two];
            int from = (cur + two + three) % 10;
            int one = (end + 10 - from) % 10;
            total_turns += turns[one];
            total_turns += go(i + 1, (k + two + three) % 10, three);
            if (ret == -1 || ret > total_turns)
            {
                ret = total_turns;
            }
        }
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dp, -1, sizeof(dp));
    cin >> n;
    cin >> start >> goal;
    cout << go(0, 0, 0) << endl;
    return 0;
}
