//baekjoon 12026
//BOJ 거리
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n;
int d[1001][3];
int num[1001];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    cin>>n;
    cin>>str;
    for(int i = 1;i<=str.size();i++){
        if(str.at(i-1) == 'B') num[i] = 0;
        else if(str.at(i-1) == 'O') num[i] = 1;
        else{
            num[i] = 2;
        }
    }
    memset(d, -1, sizeof(d));
    d[1][0] = 0;
    for(int i = 1;i<=n;i++){
        for(int j = 0;j < 3;j++){
            if(d[i][j] != -1){
                int newj = (j+1)%3;
                for(int k = 1;k<=n-i;k++){
                    if(num[i+k] ==newj){
                        if(d[i+k][newj]== -1 || d[i+k][newj]>d[i][j] + (k*k)){
                            d[i+k][newj] = d[i][j] + (k*k);
                        }
                    }
                }
            }
        }
    }

    cout<<d[n][num[n]]<<"\n";
    return 0;
}
