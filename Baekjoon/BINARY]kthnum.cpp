//baekjoon 1300
//k번째 수
#include <iostream>
#include <bits/stdc++.h>
// #include <algorithm>
using namespace std;

long long n,k;

//when using min the two inputs need to have same types(long long, int).
//It's gonna give compiler error if they have same types. 

long long numbelow(long long middle){
    
    long long sum = 0; 
    for(int i = 1;i<=n;i++){
        sum += min(middle/i, n);
    }
    return sum;
}


int main(void){
    cin>>n;
    cin>>k;
    long long left = 1;
    long long right = n*n;
    long long ans;
    while(left<=right){
        long long middle = (right+left)/2;
        long long below = numbelow(middle);
        if(below>=k){
            ans = middle;
            right = middle -1;
        }
        else{
            left = middle + 1;
        }
    }
    // cout<<numbelow(1000000)<<"\n";
    cout<<ans<<"\n";
    return 0;
}
