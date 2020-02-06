//baekjoon 1201
//NMK
//
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(void){
    
    int n, m, k;
    cin>>n>>m>>k;
    
    vector<int> num;
    for(int i = 1;i<=n;i++){
        num.push_back(i);
    }
    int index = k;
    int cnt = 1;
    // for(int i = 0;i<n;i++){
    //     cout<<num[i]<<" ";
    // }
    // cout<<"\n";
    reverse(num.begin(), num.begin() + k);
    int dist = n - k;
    if(m+k-1>n || m*k < n){
        cout<<"-1\n";;
        return 0;
    }
    int newn = n-k;
    m -=1;
    int jump = m == 0 ? 1: newn/m;
    int r = m == 0? 0: newn%m;
    for(int i = 0;i< m;i++){
        reverse(num.begin() + index, num.begin() +index + jump + (r>0 ? 1:0) );
        index += jump + (r>0 ? 1:0) ;
        if(r>0){
            r-=1;
        }
    }
    // reverse(num.begin()+index, num.end());
    for(int i = 0;i<n;i++){
        cout<<num[i]<<" ";
    }


}