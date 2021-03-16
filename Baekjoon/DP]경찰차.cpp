//baekjoon 
// 2618 경찰차

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n, m;
int dp[1001][1001]; // 
int tracer[1001][1001];
vector<pair<int,int>> cases_left;
vector<pair<int,int>> cases_right;

int go(int i, int j){
    int mx = max(i, j);
    if(mx==m){
        return 0;
    }
    int &ans = dp[i][j];
    if(ans!=-1) return ans;
    mx += 1;
    int y = cases_left[mx].first;
    int x = cases_left[mx].second;
    
    int car_one = abs(y-cases_left[i].first)+abs(x-cases_left[i].second)+go(mx, j);
    int car_two = abs(y-cases_right[j].first)+abs(x-cases_right[j].second)+go(i, mx);
    if(car_one<=car_two){
        ans = car_one;
        tracer[i][j] = 1;
    }
    else{
        ans = car_two;
        tracer[i][j] = 2;
    }
    // cout<<i<<" "<<j<<" "<<dp[i][j]<<"\n";
    return ans;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    memset(dp, -1, sizeof(dp));
    cases_left.push_back(make_pair(1, 1));
    cases_right.push_back(make_pair(n, n));
    for(int i = 0;i<m;i++){
        int y, x;
        cin>>y>>x;
        cases_left.push_back(make_pair(y, x));
        cases_right.push_back(make_pair(y, x));
    }
    int ans = go(0, 0);
    cout<<ans<<"\n";
    vector<int> ret;
    int i,j;
    i = j= 0;
    while(i!=m&&j!=m){
        if(tracer[i][j]==1){
            i = max(i, j) + 1;
            ret.push_back(1);
        } else{
            j = max(i, j) + 1;
            ret.push_back(2);
        }
    }
    for(auto a: ret){
        cout<<a<<" ";
    }
    cout<<"\n";
    return 0;
}
