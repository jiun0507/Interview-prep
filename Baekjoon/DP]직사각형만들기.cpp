// 2922 즐거운 단어
// baekjoon

#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

bool dp[20000][160]; //index, has L, index-2 vowel or consonant, index-1 vowel or consonant
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
    memset(dp, false, sizeof(dp));
    dp[0][0] = true;
    int full = 0;
    for(int i = 0;i<n;i++){
        full |= 1<<i;
    }
    cout<<full<<"\n";
    for(int i = 0;i<full;i++){
        for(int j = 0;j<n;j++){
            if((i&(1<<j))!=0) continue;
            for(int k = 0;k<=total;k++){
                if(dp[i][k]){
                    int next = i|(1<<j);
                    dp[next][k] = true;
                    dp[next][k+woods[j]] = true;
                    // cout<<next<<" "<<k<<"\n";
                    // cout<<next<<" "<<k+woods[j]<<"\n";
                }
            }
        }
    }
    int mx = -1;
    for(int i = 3;i<full-2;i++){
        int one_side = -1;
        for(int j = 2;j<total;j+=2){
            if(dp[i][j]&&dp[i][j/2]){
                one_side = j/2;
            }
        }
        if(one_side==-1) continue;
        int other_side = -1;
        int composite = full - i;
        for(int j = 2;j<total;j+=2){
            if(dp[composite][j]&&dp[composite][j/2]){
                other_side = j/2;
            }
        }
        if(other_side==-1) continue;
        if(mx<one_side*other_side){
            cout<<one_side<<" "<<other_side<<"\n";
            mx= one_side*other_side;
        }
    }
    cout<<mx<<"\n";
    return 0;
}
