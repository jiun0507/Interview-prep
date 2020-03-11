//baekjoon 13576
//prefix와 suffix
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
    
    int n = p.size();
    int k = pi[p.size()-1];

    vector<int> cnt(pi.size()+1);
    for(int i = 0;i<p.size();i++){
        cnt[pi[i]] += 1;
    }
    for(int i = n;i>0;i--){
        cnt[pi[i-1]] += cnt[i];
    }
    vector<pair<int,int>> ans;
    for (int i=n; i>0; i=pi[i-1]) {
        ans.push_back(make_pair(i, cnt[i]+1));
    }
    sort(ans.begin(), ans.end());
    cout<<ans.size()<<"\n";
    for(int i =0;i<ans.size();i++){
        cout<<ans[i].first<<" "<<ans[i].second<<"\n";
    }
    return 0;
}
