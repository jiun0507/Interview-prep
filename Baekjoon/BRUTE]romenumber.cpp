//baekjoon 16922
//로마 숫자 만들기
#include <iostream>
#include <bits/stdc++.h>
// #include <algorithm>
using namespace std;

bool check[1010][30];
int rome[4] = {1, 5, 10, 50};
int n;
int go(int index, int sum){
    if(index == n){
        return 1;
    }
    int cases= 0;
    for(int i = 0;i<4;i++){
        if(check[sum+rome[i]][index + 1] == 1) continue;
        check[sum+rome[i]][index+1] = true;
        cases += go(index + 1, sum + rome[i]);
    }
    return cases;
}

int main(void){
    
    cin>>n;
    int ans = go(0, 0);
    cout<<ans<<"\n";
    
}