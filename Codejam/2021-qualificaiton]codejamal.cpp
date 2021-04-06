#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int inf = 1000000000;

int main()
{
    int t;
    cin>>t;
    int ct = 1;
    while(t--){
        cout<<"Case #"<<ct++<<": ";
        int x, y;
        string s;
        cin>>x>>y>>s;
        vector<int> spaces;
        int dp[1002][2];
        fill(&dp[0][0], &dp[1001][1]+1, inf);

        if(s[0]=='?'){
            dp[0][1] = 0;
            dp[0][0] = 0;
        } else if(s[0]=='C'){
            dp[0][0] = 0;
        } else if(s[0]=='J'){
            dp[0][1] = 0;
        }
        // cout<<dp[0][0]<<" "<<dp[0][1]<<"\n";
        for(int i = 1;i<s.size();i++){
            for(int j = 0;j<2;j++){
                if(s[i]!='?'){
                    if(s[i]=='C'&&j==0){
                        dp[i][j] = min(dp[i-1][j], dp[i-1][1-j]+y);
                    }
                    if(s[i]=='J'&&j==1){
                        dp[i][j] = min(dp[i-1][j], dp[i-1][1-j]+x);
                    }
                }
                else{
                    if(s[i-1]=='?'){
                        int add = y;
                        if(j == 1) add = x;
                        dp[i][j] = min(dp[i-1][1-j] + add, dp[i-1][j]);
                    } else{
                        if(s[i-1]=='J'){
                            if(j==0){
                                dp[i][j] = dp[i-1][1]+y;
                            } else{
                                dp[i][j] = dp[i-1][1];
                            }
                        } 
                        if(s[i-1]=='C'){
                            if(j==1){
                                dp[i][j] = dp[i-1][0]+x;
                            } else{
                                dp[i][j] = dp[i-1][0];
                            }
                        }
                    }

                }
                // cout<<i<<" "<<j<<" "<<dp[i][j]<<"\n";
            }
        }
        int ans = min(dp[s.size()-1][0], dp[s.size()-1][1]);
        cout<<ans<<"\n";
    }
    return 0;
}
