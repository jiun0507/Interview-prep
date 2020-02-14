//baekjoon 1561
//놀이공원
#include <iostream>
#include <bits/stdc++.h>
// #include <algorithm>
using namespace std;

long long n,m;
int rides[10001];
long long kids(long long minutes){
    
    long long sum = 0; 
    for(int i = 0;i<m;i++){
        long long ad = 1+(minutes-1)/ rides[i];
        sum += ad;
    }
    return sum;
}


int main(void){
    cin>>n;
    cin>>m;
    long long left = 1;
    
    long long right = n*30;
    long long minute;
    for(int i = 0;i<m;i++){
        cin>>rides[i];
    }
    while(left<=right){
        long long middle = (right+left)/2;
        long long below = kids(middle);
        if(below>=n){
            minute = middle;
            right = middle -1;
            
        }
        else{
            left = middle + 1;
            
        }
    }
    int last = kids(minute) - n;
    int ans;
    for(int i = m-1;i>=0;i--){
        if((minute- 1)%rides[i] == 0){
            if(last == 0){
                ans = i+1;
                break;
            }
            last--;
        }
    }
    cout<<ans<<"\n";
    return 0;
}