//baekjoon 12996
//Acka
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n;
int A, B, C;
long long d[51][51][51][51];
long long d2[51][51][51][51];
const int mod = 1000000007;
long long go(int index, int a, int b, int c){
    if(index == 0){
        if(a == 0 && b == 0 && c == 0){
            return 1;
        }
        return 0;
    }
    if(a<0 || b<0 || c<0) return 0;
    long long &ans = d2[index][a][b][c];
    if(ans != -1){
        return ans;
    }
    ans = 0;
    for(int i =0;i<2;i++){
        for(int j = 0;j<2;j++){
            for(int k = 0;k<2;k++){
                if(i == 0 && j == 0 && k ==0) continue;
                ans += go(index-1, a-i, b-j, c-k);
                ans %= mod;
            }
        }
    }
    
    
    return ans;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    cin>>A;
    cin>>B;
    cin>>C;
    memset(d2, -1, sizeof(d2));
    d[0][0][0][0] = 1;
    for(int i = 1;i<=n;i++){
        for(int a = 0;a<=n;a++){
            for(int b = 0;b<=n;b++){
                for(int c = 0;c<=n;c++){
                    long long &cur = d[i][a][b][c];
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
    cout<<go(n, A, B, C);
    return 0;
}
