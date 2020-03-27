//baekjoon 14238
//출근 기록
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n, k;
int A,B,C;
int d[51][51][51][3][3];
char ans[51];

bool go(int i, int a, int b, int prev1, int prev2){
    if(i == n){
        if(a == A && b == B){
            cout<<ans<<"\n";
            d[i][a][b][prev1][prev2] = 1;
            return true;
        }
        return false;
    }
    if(d[i][a][b][prev1][prev2]){
        if(d[i][a][b][prev1][prev2] == 2){
            return false;    
        }
        return true;
    }
    ans[i] = 'A';
    
    if(a<A && go(i+1, a+1, b, 0, prev1)){
        d[i][a][b][prev1][prev2] = 1;
        
        return true;
    }
    
    ans[i] = 'B';
    if(i == 0 || (i >0 && prev1 != 1)){
        if(b<B && go(i+1, a, b+1, 1, prev1)){
            d[i][a][b][prev1][prev2] = 1;
            return true;
        }
    }
    ans[i] = 'C';
    if(i == 0 || (i==1  && prev1 != 2) || (i >1 && prev1 != 2 && prev2 != 2)){
        if(i-a-b<n-A-B && go(i+1, a, b, 2, prev1)){
            d[i][a][b][prev1][prev2] = 1;
            return true;
        }
    }
    d[i][a][b][prev1][prev2] = 2;
    return false;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    cin>>str;
    A = B = C = 0;
    for(int i = 0;i<str.size();i++){
        if(str.at(i) == 'A') A++;
        else if(str.at(i) == 'B') B++;
        else{
            C++;
        }
    }

    // cout<<A<<" "<<B<<" "<<C<<"\n";
    n = A + B + C;
    if(!go(0, 0, 0, 0, 0)){
        cout<<"-1\n";
    }
    return 0;
}
