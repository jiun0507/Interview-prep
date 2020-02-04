//baekjoon 1783
//병든 나이트
//h를 123, w를 나누어서 각 케이스별로 정리해서 문제를푼다.
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(void){
    int n,m;
    cin>>n>>m;
    int ans;
    if(n==1){
        ans = 1;    
    }
    else if(n == 2){
        if(m < 7){
            ans = (m+1)/2;
        }
        else{
            ans = 4;
        }
    }
    else if(n >=3){
        if(m<=4) ans = m;
        else if(m>4 && m<7){
            ans = (m+3)/2;
        }
        else{
            
            ans = m-2;
        }
    }
    
    cout<<ans<<"\n";
}