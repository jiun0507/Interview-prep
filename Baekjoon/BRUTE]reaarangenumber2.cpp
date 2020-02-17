//baekjoon 16943
//숫자재배치 recursion
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int check[10];
int num[10];
int n;
int b;
int go(int index, int number){
    if(index == n){
        if(number<=b) return number;
        else{
            return -1;
        }
    }
    int ans = -1;
    for(int i = 0;i<n;i++){
        if(check[i] == 0){
            if(index == 0 && num[i] == 0) continue;
            check[i] = 1;
            int partial_ans = go(index + 1, number*10+ num[i]);
            if(partial_ans > ans){
                ans = partial_ans;
            }
            check[i] = 0;
        }
    }
    return ans;
}

int main(void){
    string a;
    cin>>a;
    cin>>b;
    
    n = a.length();
    for(int i = 0;i<n;i++){
        num[i] = a[i] - '0';
    }
    cout<<go(0, 0)<<"\n";
    
}