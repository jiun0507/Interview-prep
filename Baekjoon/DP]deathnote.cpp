//baekjoon 2281
//데스노트
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n, m;
long long d[1001][1001];
int num[1001];
// long long go(int index, int a, int b, int c){
//     if(index == 0){
//         if(a == 0 && b == 0 && c == 0){
//             return 1;
//         }
//         return 0;
//     }
//     if(a<0 || b<0 || c<0) return 0;
//     long long &ans = d2[index][a][b][c];
//     if(ans != -1){
//         return ans;
//     }
//     ans = 0;
//     for(int i =0;i<2;i++){
//         for(int j = 0;j<2;j++){
//             for(int k = 0;k<2;k++){
//                 if(i == 0 && j == 0 && k ==0) continue;
//                 ans += go(index-1, a-i, b-j, c-k);
//                 ans %= mod;
//             }
//         }
//     }
    
    
//     return ans;
// }

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i = 0;i<n;i++){
        cin>>num[i];
        // cout<<num[i]<<" ";
    }
    // cout<<"\n";
    memset(d, -1, sizeof(d));
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
        // cout<<d[11][i]<<"\n";
        if(d[n][i]==-1) continue;
        if(mn == -1 || mn > d[n][i]) mn = d[n][i];
    }
    cout<<mn<<"\n";
    return 0;
}
