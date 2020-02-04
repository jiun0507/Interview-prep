//baekjoon 1541
//잃어버린 괄호

include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main(void){
    string s;
    cin>>s;
    vector<int> num, ops;
    int cur = 0;
    for(int i = 0;i<s.size();i++){
        char c = s.at(i);
        if(c == '+'|| c == '-'){
            if(c == '+'){
                ops.push_back(1);   
            }
            else{
                ops.push_back(-1);
            }
            num.push_back(cur);
            cur = 0;
        }
        else{
            cur *= 10;
            cur += c - '0';
        }
        if(i == s.size()-1){
            num.push_back(cur);
        }
    }

    int sum = num[0];
    bool minus = false;
    for(int i = 1;i<num.size();i++){
        if(ops[i-1] == 1){
            if(minus){
                sum -= num[i];
            }
            else{
                sum += num[i];
            }
        }
        else{
            minus = true;
            sum -= num[i];
        }
    }
    cout<<sum<<"\n";
}