//baekjoon 12969
//ABC
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n, k;
int d[31][31][31][450];
char ans[31];

bool go(int i, int a, int b, int j){
    if(i == n){
        if(j == k){
            cout<<ans<<"\n";
            d[i][a][b][j] = 1;
            return true;
        }
        else {
            d[i][a][b][j] = 2;
            return false;
            
        }
    }
    if(d[i][a][b][j]){
        if(d[i][a][b][j] == 2) return false;
        return true;
    }
    bool found = false;
    ans[i] = 'A';
    if(go(i +1, a+1, b, j)){
        d[i][a][b][j] = true;
        return true;
    }
    ans[i] = 'B';
    if(go(i+1, a, b+1,j+a)){
        d[i][a][b][j] = true;
        return true;
    }
    ans[i] = 'C';
    
    if(go(i+1, a, b, j+a+b)){
        d[i][a][b][j] = true;
        return true;
    }
    d[i][a][b][j] = 2;
    
    return false;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    // d[1][1][0][0] = 1;
    // d[1][0][1][0] = 1;
    // d[1][0][0][0] = 1;
    // for(int i = 2;i<=n;i++){
    //     for(int a = 0;a<=n;a++){
    //         for(int b = 0;b<=n;b++){
    //             for(int j = 0;j<=k;j++){
    //                 int &temp = d[i][a][b][j];
    //                 if(a>0) temp += d[i-1][a-1][b][j];
    //                 if(b>0 && j - a >=0) temp += d[i-1][a][b-1][j-a];
    //                 if(i -a - b>0 && j-a-b>=0) temp += d[i-1][a][b][j-a-b];
    //             }
    //         }
    //     }
    // }

    if(go(0, 0, 0, 0)){
        return 0;
    }
    else{
        cout<<"-1\n";
    }
    
    
    return 0;
}
