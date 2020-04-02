//baekjoon 10564
//팔굽혀 펴기

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n, m;
int scores[11];
int d[5001][1001];

void go(int i, int j){
    if(i>push_max) return;
    if(d[i][j]) return;
    d[i][j] = true;
    for(int k = 0;k<score_type;k++){
        go(i + j + scores[k], j + scores[k]);
    }
    return;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin>>test;
    while(test--){
        int push_max;
        int score_type;
        cin>>push_max>>score_type;
        for(int i = 0;i<score_type;i++){
            cin>>scores[i];
        }
        memset(d, -1, sizeof(d));
        d[0][0] = 1;
        for(int i = 1;i<=push_max;i++){
            for(int j = 0;j<=min(i, 1000);j++){
                 for(int k = 0;k<score_type;k++){
                     if(d[i-j][j-scores[k]] == 1){
                         d[i][j] = 1;
                         break;
                     }
                 }
            }
        }
        int mx = -1;
        for(int i = 1;i<1000;i++){
            if(d[push_max][i] ==1) mx = i;
        }
        cout<<mx<<"\n";        
    }

    
    return 0;
}
