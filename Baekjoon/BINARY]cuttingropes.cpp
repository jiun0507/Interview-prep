
//baekjoon 1654
//랜선 자르기
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n,k;
long long ropes[10000];

long long kth(long long middle){
    long long ans = 0;
    for(int i = 0;i<k;i++){
        ans += ropes[i]/middle;
    }
    return ans;
}

int main(void){
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>k;
	cin>>n;
	int max = 0;
    for(int i = 0;i<k;i++){
        cin>>ropes[i];
        if(max == 0 || max<ropes[i]){
            max = ropes[i];
        }
        // cout<<ropes[i]<<"\n";
    }
    long long  left = 1;
    long long right = max;
    long long ans = -1;
    
    while(left<=right){
        long long  middle = (left+right)/2;
        long long num = kth(middle);
        // cout<<left<<" "<<right<<" "<<middle<<" "<<num<<"\n";
        if(num>= n){
            ans = middle;
            left = middle+1;
        }
        else{
            right = middle - 1;
        }
    }
    cout<<ans<<"\n";

    
    return 0;
}