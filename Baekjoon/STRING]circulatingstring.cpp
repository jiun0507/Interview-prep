//baekjoon 12104
//순환 수열

//use KMP to solve it
//compare two strings
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
    string s, p;
    cin>>s>>p;
    s.append(s);
    s.pop_back();
    // cout<<p<<"\n";
    vector<int> pi = preprocess(p);
    
    vector<int> ans;
    
    int n = s.size();
    int m = p.size();
    int j = 0;
    for(int i = 0;i < n; i++){
        while(j>0 && s[i] != p[j]){
            j = pi[j-1];
        }
        if(s[i] == p[j]){
            if(j == m-1){
                // cout<<i-m+1<<"\n";
                ans.push_back(i-m+1);
                j = pi[j];
            } else{
                j++;
            }
        }
        
    }
    if(ans.size() == 0){
        cout<<"0\n";
        return 0;
    }
    cout<<ans.size()<<"\n";
    return 0;
}
