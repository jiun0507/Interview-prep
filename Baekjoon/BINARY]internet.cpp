
//baekjoon 2110
//공유기 설치
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n,k;
long long houses[1000000];

bool possible(long long middle){
    long long cnt = 1;
    int dist = 0;
    for(int i = 1;i<k;i++){
        dist += houses[i] - houses[i-1];
        if(dist>=middle){
            cnt++;
            dist = 0;
        }
    }
    return cnt>=n;
}

int main(void){
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>k;
	cin>>n;
    long long max = -1;
    for(int i = 0;i<k;i++){
        cin>>houses[i];
        if(max<houses[i]){
            max = houses[i];
        }
    }
    sort(houses, houses+k);
    long long left = 1;
    long long right = max;
    long long ans = -1;
    
    while(left<=right){
        long long  middle = (left+right)/2;
        bool can = possible(middle);
        // cout<<left<<" "<<right<<" "<<middle<<" "<<can<<"\n";
        if(can){
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