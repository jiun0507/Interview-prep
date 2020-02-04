//baekjoon 10610
//30
//문자열로만 해결한 케이스

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(void){
    
    string s;
    cin>>s;
    int sum = 0;
    for(int i = 0;i<s.size();i++){
        sum += s.at(i) - '0';
    }
    sort(s.begin(), s.end());
    if(s[0] == '0' && sum % 3 == 0){
        reverse(s.begin(), s.end());
        cout<<s<<"\n";
    }
    else{
        cout<<"-1\n";
    }
    
}