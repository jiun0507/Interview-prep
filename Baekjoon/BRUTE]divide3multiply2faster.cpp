//baekjoon 16936
//나3곱2
#include <iostream>
#include <bits/stdc++.h>
// #include <algorithm>
using namespace std;

long long b[100];
int n;

int main(void){
    
    cin>>n;
    vector<pair<int, long long>> store;
    for(int i = 0;i<n;i++){
        cin>>b[i];
        int threes = 0;
        long long buf = b[i];
        while(b[i]%3 == 0 && b[i] != 0){
            threes++;
            b[i] /= 3;
        }
        store.push_back(make_pair(-threes, buf));
        
    }
    sort(store.begin(), store.end());
    for(int i = 0;i<store.size();i++){
        // cout<<store[i].first<<" ";
        cout<<store[i].second<<" ";
    }
    
}