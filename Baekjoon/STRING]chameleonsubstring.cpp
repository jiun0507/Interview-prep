//baekjoon 13506
//카멜레온 부분 문자열
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> preprocess(string p){
    int len = p.size();
    vector<int> pi(len);
    pi[0] = 0;
    int j = 0;
    for(int i = 1;i < len; i++){
        while(j>0 && p[i] != p[j]) j = pi[j-1];
        if(p[i] == p[j]){
            pi[i] = j+1;
            j++;
        } else{
            pi[i] = 0;
        }
    }
    return pi;
}



int main(void){
    string p;
    cin>>p;
    vector<int> pi = preprocess(p);
    
    vector<int> ans;
    
    int k = pi[p.size()-1];
    // cout<<k<<"\n";
    // cout<<pi[k-1];
    // k = pi[k-1];
    // cout<<k<<"\n";
    // k = pi[k-1];
    // cout<<k<<"\n";
    // for(int i = 0;i<pi.size();i++){
    //     cout<<pi[i]<<" ";
    // }
    
    while(k != 0){
        int cnt = 0;
        for(int i = 0;i<pi.size();i++){
            if(pi[i] >= k) cnt++;
        }
        if(cnt>1){
            cout<<p.substr(0, k)<<"\n";
            return 0;
        }
        k = pi[k-1];
    }
    cout<<"-1\n";
    return 0;
}
