//baekjoon 1744
//수묶기
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(void){
    int n;
    cin>>n;
    vector<int> plus, minus;
    int zero, one;
    zero = one = 0;
    for(int i = 0;i<n;i++){
        int temp;
        cin>>temp;
        if(temp == 0) zero +=1;
        else if(temp == 1) one +=1;
        else if(temp >0) plus.push_back(temp);
        else{
            minus.push_back(temp);
        }
    }
    
    sort(plus.begin(), plus.end());
    reverse(plus.begin(), plus.end());
    sort(minus.begin(), minus.end());
    if(plus.size() % 2 == 1){
        plus.push_back(1);
    }
    if(minus.size() % 2 == 1){
        minus.push_back(zero>0 ? 0 : 1);
    }
    int sum = 0;
    for(int i =0 ;i<plus.size();i+=2){
        int temp = plus[i];
        temp *= plus[i+1];
        sum += temp;
    }
    for(int i =0 ;i<minus.size();i+=2){
        int temp = minus[i];
        temp *= minus[i+1];
        sum += temp;
    }
    sum += one;
    cout<<sum<<"\n";
}