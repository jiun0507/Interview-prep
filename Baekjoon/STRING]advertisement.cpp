//baekjoon 1305
//광고
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n;

vector<int> preprocess(string s){
    int len = s.size();
    vector<int> pi(len);
    pi[0] = 0;
    int j = 0;
    for(int i = 1;i < len; i++){
        while(j>0 && s[i] != s[j]) j = pi[j-1];
        if(s[i] == s[j]){
            pi[i] = j+1;
            j++;
        } else{
            pi[i] = 0;
        }
    }
    return pi;
}

int main(void){
    cin>>n;
    string str;
    cin>>str;
    vector<int> pi = preprocess(str);
    int j = n-1;

    cout<<n- pi[j]<<"\n";
    return 0;
}
