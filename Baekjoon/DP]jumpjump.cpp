//baekjoon 11060
//점프 점프
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n;
int jump[1001];
int d[1001];
int d2[1001];

int go(int i){
    // if(i == 1 && j == 1) return candy[i][j];
    if(i > n) return -1;
    if(i == n) return 0;
    if(d[i] != -1){
        return d[i];
    }
    for(int j = 1; j<= jump[i]; j++){
        int temp = go(i + j);
        if(temp == -1) continue;
        if(d[i] == -1 || temp < d[i]){
            d[i] = temp + 1;
        }
    }
    
    return d[i];
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(d, -1, sizeof(d));
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>jump[i];
    }
    cout<<go(1)<<"\n";
    // Dynamic programming using for loop 
    d2[0] = 0;
    for(int i = 0; i <n-1;i++){
        if(d2[i] == -1) continue;
        for(int j = 1;j<=jump[i];j++){
            if(i + j >n) continue;
            if(d2[i+j] == -1 || d2[i+j] > 1 + d2[i]){
                d2[i+j] = d[i] + 1;
            }
            
        }
    }
    cout<<d2[n-1]<<"\n";
    return 0;

}