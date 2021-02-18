// 1328 고층빌딩
// baekjoon

//2~N까지 세워진 빌딩에 1높이의 빌딩을 넣는 식으로 생각해본다.
//2~N은 n-1개의 빌딩(1~n-1)들을 각가 높이 1씩 올린거라고 가정하고, n-1개 빌딩이 L, R을 가지고
//있다. 1을 놓는 방법은 왼쪽, 오른쪽 그리고 중간 어딘가(n-2)중 하나. 왼쪽에 놓으면 L->L+1이 된다.
//오른쪽은 R->R+1. 중간은 L, R이 유지된다. 이를 점화식으로 표현하면
//dp[i][j][k] = dp[i-1][j-1][k] + dp[i-1][j][k-1] + dp[i-1][j][k]*(i-2)로 표현된다.
//위 표현은 topdown식 표현이고 downtop은 숫자를 조정해줘야한다.

#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

long long p[101][101][101];
int n, l, r;
const long long mod = 1000000007;

int main()
{
    memset(p, 0, sizeof(p));
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> l >> r;
    p[1][1][1] = 1LL;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            for (int k = 1; k <= i; k++)
            {
                if (p[i][j][k])
                {
                    p[i + 1][j + 1][k] += p[i][j][k];
                    p[i + 1][j + 1][k] %= mod;
                    p[i + 1][j][k + 1] += p[i][j][k];
                    p[i + 1][j][k + 1] %= mod;
                    p[i + 1][j][k] += p[i][j][k] * (i - 1);
                    p[i + 1][j][k] %= mod;
                }
            }
        }
    }
    cout << p[n][l][r] << endl;
    return 0;
}
