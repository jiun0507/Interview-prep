// 2922 즐거운 단어
// baekjoon

#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

bool dp[81][81][81][81];
int n;
int woods[16];

int main()

{

    cin>>n;
    int total = 0;
    for(int i =0;i<n;i++){
        cin>>woods[i];
        total += woods[i];
    }
    dp[0][0][0][0] = true;
    for(int i = 0;i<n;i++){
        for(int a = total/2;a>=0;a--){
            for(int b = total/2;b>=0;b--){
                for(int c = total/2;c>=0;c--){
                    for(int d = total/2;d>=0;d--){
                        if(dp[a][b][c][d]==true){
                            if(a+woods[i]<=80) dp[a+woods[i]][b][c][d] = 1;
                            if(b+woods[i]<=80)dp[a][b+woods[i]][c][d] = 1;
                            
                            if(c+woods[i]<=80)dp[a][b][c+woods[i]][d] = 1;
                            if(d+woods[i]<=80)dp[a][b][c][d+woods[i]] = 1;
                        }
                    }
                }
            }
        }
    }
    int mx = -1;
    for(int i = 1;i<=total/2;i++){
        for(int j = 1;j<=total/2;j++){
            if(dp[i][i][j][j]==true||dp[j][j][i][i]){
                mx = max(mx, i*j);
            }
        }
    }
    cout<<mx<<"\n";
    return 0;
}
