//baekjoon 17088
//등차수열 변환
#include <iostream>
#include <bits/stdc++.h>
// #include <algorithm>
using namespace std;
int n;
int num[100000];
int d[] = {0, -1, 1};

int main(void){
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>num[i];
    }
    int ans = -1;
    for(int i  = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            int dif = num[0]+d[i] - (num[1]+d[j]);
            int cnt = 0;
            if(i!= 0) cnt++;
            if(j!=0) cnt++;
            bool ok = true;
            int next = num[1] + d[j];
            for(int k =2;k<n;k++){
                next -= dif;
                if(next-num[k]<-1 || next-num[k]>1){
                    ok = false; 
                    break;
                }
                if(next-num[k] != 0) cnt++;
                
            }
            if(!ok) continue;
            if(ans==-1||ans>cnt) ans = cnt;
        }
        
    }
    cout<<ans<<"\n";
    
}