// 2606 돌다리 건너기
// baekjoon

#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

int scroll[21], heaven[102], hell[102];
vector<int> heaven_step[5];
vector<int> hell_step[5];
int dp[21][102][2]; // steps, the bridge location.

int what(char c){
    if(c=='R') return 0;
    if(c=='I') return 1;
    if(c=='N') return 2;
    if(c=='G') return 3;
    if(c=='S') return 4;
}

int main()

{
    string s,hea,hel;
    cin>>s>>hea>>hel;
    for(int i=0;i<s.size();i++){
        scroll[i] = what(s.at(i));
    }
    for(int i=1;i<=hea.size();i++){
        heaven[i] = what(hea.at(i-1));
        heaven_step[what(hea.at(i-1))].push_back(i);
    }
    for(int i=1;i<=hel.size();i++){
        hell[i] = what(hel.at(i-1));
        hell_step[what(hel.at(i-1))].push_back(i);
    }
    dp[0][0][0] = 1;
    dp[0][0][1] = 1;
    for(int i = 0;i<s.size();i++){
        for(int j = 0;j<=hea.size();j++){
            for(int k = 0;k<2;k++){
                if(dp[i][j][k] == 0) continue;
                if(k==0){
                    //heaven(current position)
                    for(auto next: hell_step[scroll[i]]){
                        if(next>j){
                            dp[i+1][next][1] += dp[i][j][k];
                        }
                    }
                }
                if(k==1){
                    for(auto next: heaven_step[scroll[i]]){
                        if(next>j){
                            dp[i+1][next][0] += dp[i][j][k];   
                        }
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int i = 1;i<=hea.size();i++){
        for(int j = 0;j<2;j++){
            ans += dp[s.size()][i][j];   
        }
    }
    cout<<ans<<"\n";
    return 0;
}
