//baekjoon 2281
//데스노트

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n, m;
long long d[1001][1001];
long long d2[1001][1001];
long long d3[1001][1002];
int num[1001];
long long go(int index, int space){
    if(index == n){
        return 0;
    }
    long long &ans = d2[index][space];
    if(ans != -1){
        return ans;
    }
    int cost = (space+1) * (space+1);
    ans = go(index + 1, m - num[index] - 1) +  cost;
    if(space >= num[index]){
        if(space == num[index]) ans = min(ans, go(index + 1, m));
        else{
            ans = min(ans, go(index + 1, space - num[index] - 1));
        }
    }
    
    return ans;
}

long long go2(int index, int count){
    if(index == n){
        return 0;
    }
    long long &ans = d3[index][count];
    if(ans != -1){
        return ans;
    }
    int space = m - count + 1;
    int cost = space * space;
    ans = go2(index + 1, num[index] + 1) +  cost;
    if(count + num[index] <= m){
        int cur = go2(index + 1, count + num[index] + 1);
        if(cur < ans) ans = cur;
    }
    
    return ans;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i = 0;i<n;i++){
        cin>>num[i];
        // cout<<num[i]<<" ";
    }
    // cout<<"\n";
    memset(d2, -1, sizeof(d2));
    memset(d, -1, sizeof(d));
    memset(d3, -1, sizeof(d3));
    d[0][m] = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<=m;j++){
            if(d[i][j] != -1){
                int step = num[i]+1;
                if(j == m) step = num[i];
                if(d[i+1][m-num[i]]==-1 || d[i+1][m-num[i]]>(d[i][j] + j*j)){
                    d[i+1][m-num[i]]= d[i][j] + j*j;
                }
                if(j-step>0){
                    if(d[i+1][j-step]==-1 || d[i+1][j-step]>d[i][j]){
                        d[i+1][j-step] = d[i][j];
                    }
                }
                else if(j == step){
                    d[i+1][m] = d[i][j];
                }
                
            }
        }
    }
    int mn = -1;
    for(int i = 0;i<=m;i++){
        if(d[n][i]==-1) continue;
        if(mn == -1 || mn > d[n][i]) mn = d[n][i];
    }
    
    
    cout<<go(0, m)<<"\n";
    cout<<go2(0, 0)<<"\n";
    return 0;
}
