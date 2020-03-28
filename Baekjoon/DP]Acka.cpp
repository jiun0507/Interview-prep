//baekjoon 12996
//Acka

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n;
int A, B, C;
int d[51][51][51][51];
const int mod = 1000000007;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    cin>>A;
    cin>>B;
    cin>>C;

    d[0][0][0][0] = 1;
    for(int i = 1;i<=n;i++){
        for(int a = 0;a<=n;a++){
            for(int b = 0;b<=n;b++){
                for(int c = 0;c<=n;c++){
                    int &cur = d[i][a][b][c];
                    if(a>0){
                        if(b>0){
                            if(c>0){
                                cur += d[i-1][a-1][b-1][c-1];
                                cur %= mod;
                            }
                            cur += d[i-1][a-1][b-1][c];
                            cur %= mod;
                        }
                        if(c>0){
                            cur += d[i-1][a-1][b][c-1];
                            cur %= mod;
                        }
                        cur += d[i-1][a-1][b][c];
                        cur %= mod;
                    }
                    if(b>0){
                        if(c>0){
                            cur+= d[i-1][a][b-1][c-1];
                            cur %= mod;
                        }
                        cur+= d[i-1][a][b-1][c];
                        cur %= mod;
                    }
                    if(c>0){
                        cur+=d[i-1][a][b][c-1];
                        cur %= mod;
                    }
                }
            }
        }
    }
    cout<<d[n][A][B][C]<<"\n";
    return 0;
}
