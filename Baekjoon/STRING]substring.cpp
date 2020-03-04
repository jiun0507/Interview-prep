//baekjoon 16916
//부분 문자열 
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long mod = 2147483647;
long long base = 256;

// bool match(string &s, string &p){
//     int len = s.length();
//     bool ans = true;
//     for(int i = 0;i < len;i++){
//         if(s.at(i) != p.at(i)) ans = false;
//     }
//     return ans;
// }

long long h(string str){
    long long ans = 0;
    for(char c: str){
        ans = (ans * base + c ) % mod;
    }
    return ans;
}

int main(void){
    string s;
    string p;
    cin>>s>>p;
    int n = s.size();
    int m = p.size();
    long long hash_p = h(p);
    long long hash_s = h(s.substr(0, m));
    if(hash_p == hash_s){
        cout<<"1\n";
        return 0;
    }
    long long first = 1;
    for(int i = 0;i<m-1;i++){
        first = (first * base) % mod;
    }
    for(int i = 0;i<n-m;i++){
        if(hash_s == hash_p){
            cout<<"1\n";
            return 0;
        }
        hash_s = hash_s - (s[i]*first)%mod;
        hash_s = (hash_s + mod) % mod;
        hash_s = ((hash_s * base) % mod + s[i+m]) % mod;

    }
    if(hash_s == hash_p){
        cout<<"1\n";
        return 0;
    }
    cout<<"0\n";
    return 0;
}