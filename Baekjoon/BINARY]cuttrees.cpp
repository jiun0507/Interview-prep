
//baekjoon 2805
//나무 자르기
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n,k;
long long trees[1000000];

bool kth(long long middle){
    long long ans = 0;
    for(int i = 0;i<k;i++){
        if(trees[i]> middle){
            ans += trees[i] - middle;
        }
    }
    return ans>=n;
}

int main(void){
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>k;
	cin>>n;
    long long max = -1;
    for(int i = 0;i<k;i++){
        cin>>trees[i];
        if(max<trees[i]){
            max = trees[i];
        }
    }
    long long left = 0;
    long long right = max;
    long long ans = -1;
    
    while(left<=right){
        long long  middle = (left+right)/2;
        bool enough = kth(middle);
        // cout<<left<<" "<<right<<" "<<middle<<" "<<enough<<"\n";
        if(enough){
            ans = middle;
            left = middle +1;
        }
        else{
            right = middle -1;
        }
    }
    cout<<ans<<"\n";

    
    return 0;
}