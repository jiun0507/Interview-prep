//baekjoon 2294
//동전 2
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n, k;
int num[101];
int d[10001];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    memset(d, -1, sizeof(d));
    for(int i = 0;i<n;i++){
        cin>>num[i];   
    }
    d[0] = 0;
    for(int i = 0;i<n;i++){
        for(int j = 1;j<=k;j++){
            if(j - num[i] >=0 && d[j-num[i]] != -1){
                if(d[j] == -1 || d[j-num[i]]+1<d[j]){
                    d[j] = d[j-num[i]]+1;
                }
            }
        }
    }
    cout<<d[k]<<"\n";
}

