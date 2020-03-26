//baekjoon 11049
//행렬 곱셈 순서
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int,int>> num;
int d[501][501];

int go(int x, int y){
    if(x == y) return 0;
    if(d[x][y]) return d[x][y];
    if(x+1 == y) return num[x].first * num[x].second * num[y].second;
    int &ans = d[x][y];
    ans = -1;
    for(int k = x; k<y ;k++){
        int temp = go(x, k) + go(k+1, y) + num[x].first * num[k].second * num[y].second;
        if(ans == -1 || ans > temp){
            ans = temp;
        }
        
        
    }
    return ans;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i = 0;i<n;i++){
        int first, second;
        cin>>first>>second;
        num.push_back(make_pair(first, second));
    }
    cout<<go(0, n-1)<<"\n";
    return 0;
}
