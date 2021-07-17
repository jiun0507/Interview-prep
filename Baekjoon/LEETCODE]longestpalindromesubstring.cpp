//baekjoon 14501
#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

string longestPalindrome(string s) {
    int len = s.size();
    bool dp[len][len];
    memset(dp, 0, sizeof(dp));
    for(int i = 0;i<len;i++){
        dp[i][i] = true;
    }
    string ret;
    ret.push_back(s[0]);
    for(int i = 1;i<len;i++){
        for(int j = 0;j+i<len;j++){
            if(s[j]==s[j+i]){
                
                if(j+1<=j+i-1){
                    if(dp[j+1][j+i-1]){
                        dp[j][j+i] = true;
                        if(ret.size()<i+1){
                            ret = s.substr(j, i+1);
                        }
                    }
                } else{
                    dp[j][j+i] = true;
                    if(ret.size()<i+1){
                        ret = s.substr(j, i+1);
                    }
                }
            }
        }
    }
    return ret;
}


int main() {
	
    string input;
    cin>>input;
    cout<<longestPalindrome(input)<<"\n";
    return 0;


}