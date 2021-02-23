// 1234 크리스마스 트리
// baekjoon

#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

long long dp[12][101][101][101];
int n, red, blue, green;

int main()
{
    long long Combination[51][51] = {};
    Combination[1][0] = 1;
    Combination[1][1] = 1;
    for (int i = 2; i <= 20; i++)
    {
        Combination[i][0] = 1;
        for (int j = 1; j <= 20; j++)
        {
            Combination[i][j] = Combination[i - 1][j - 1] + Combination[i - 1][j];
        }
    }
    cin >> n >> red>>blue>>green;

    dp[1][red][blue][green] = 1LL;

    for (int i = 1; i <= n; i++)
    {
        for (int a = 0; a <= red; a++)
        {
            for(int b = 0; b<= blue; b++){
                for(int c = 0;c<=green;c++){
                    if(dp[i][a][b][c]>0){
                        if(i<=a) dp[i+1][a-i][b][c] += dp[i][a][b][c];
                        if(i<=b) dp[i+1][a][b-i][c] += dp[i][a][b][c];
                        if(i<=c) dp[i+1][a][b][c-i] += dp[i][a][b][c];
                        if(i%2==0){
                            int two = i/2;
                            int mult = Combination[i][two]*Combination[i-two][two];
                            if(a>=two&&b>=two){
                                dp[i+1][a-two][b-two][c]+=dp[i][a][b][c]*mult;
                            }
                            if(b>=two&&c>=two){
                                dp[i+1][a][b-two][c-two]+=dp[i][a][b][c]*mult;
                            }
                            if(a>=two&&c>=two){
                                dp[i+1][a-two][b][c-two]+=dp[i][a][b][c]*mult;
                            }
                        }
                        if(i%3==0){
                            int three = i/3;
                            int mult = Combination[i][three]*Combination[i-three][three]*Combination[i-three*2][three];
                            if(a>=three&&b>=three&&c>=three){
                                dp[i+1][a-three][b-three][c-three]+=dp[i][a][b][c]*mult;
                            }
                        }
                    }
                }
            }
        }
    }
    long long ans = 0;
    for(int i = 0;i<=red;i++){
        for(int j = 0;j<=blue;j++){
            for(int k = 0;k<=green;k++){
                if(dp[n+1][i][j][k]>0){
                    ans += dp[n+1][i][j][k];
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
