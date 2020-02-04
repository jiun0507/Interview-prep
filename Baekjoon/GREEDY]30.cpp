//baekjoon 10610
//30
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(void){
    
    string s;
    cin>>s;
    int zero= 0;
    vector<int> num;
    int sum = 0;
    for(int i = 0;i<s.size();i++){
        int cur = s.at(i) -'0';
        if(cur == 0){
            zero++;
        }
        else{
            num.push_back(cur);
            sum += cur;
        }
    }
    if(zero == 0 || sum % 3 != 0){
        cout<<-1<<"\n";
        return 0;
    }
    for(int i = 0;i<zero;i++){
        num.push_back(0);
    }
    sort(num.begin(), num.end());
    reverse(num.begin(),num.end());
    for(int i =0 ;i<num.size();i++){
        cout<<num[i];
    }
    
}