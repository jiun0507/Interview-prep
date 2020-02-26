//baekjoon 16987
//계란으로 계란치기
#include <iostream>
#include <bits/stdc++.h>
// #include <algorithm>
using namespace std;
int n;
int barrier[10], weight[10];

int go(int index){
    if(index == n){
        int cnt = 0;
        for(int i = 0;i<n;i++){
            if(barrier[i]<=0)cnt++;
        }
        
        return cnt;
    }
    if(barrier[index]<=0) return go(index+1);
    int ans = 0;
    for(int i = 0;i<n;i++){
        if(i == index) continue;
        int temp;
        if(barrier[i]<=0) temp = go(index +1);
        else{
            barrier[i] -= weight[index];
            barrier[index] -= weight[i];
            temp = go(index+1);
            barrier[i] += weight[index];
            barrier[index] += weight[i];
        }
        if(ans<temp){
            ans = temp;
        } 
    }
    return ans;
}

int main(void){
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>barrier[i]>>weight[i];
    }
    int ans = go(0);
    cout<<ans<<"\n";
    
}