//baekjoon 16917
//양념 반 후라이드 반
#include <iostream>
#include <bits/stdc++.h>
// #include <algorithm>
using namespace std;

int a, b, c, x, y;

int main(void){
    
    cin>>a>>b>>c>>x>>y;
    int limit = max(x, y);
    int max = INT_MAX;
    for(int i = 0; i<= limit*2; i+=2){
        int halves = i/2;
        int sum = halves * c*2;
        if((x-halves)>0){
            sum +=(x-halves)*a;
        }
        if((y-halves)>0){
            sum += (y-halves)*b;
        }
        if(max>sum) max = sum;
    }
    cout<<max<<"\n";
    
}