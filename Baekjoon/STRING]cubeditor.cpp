//baekjoon 1701
//Cubeditor
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n;

vector<int> preprocess(string s){
    int len = s.size();
    vector<int> pi(len);
    pi[0] = 0;
    int j = 0;
    for(int i = 1;i < len; i++){
        while(j>0 && s[i] != s[j]) j = pi[j-1];
        if(s[i] == s[j]){
            pi[i] = j+1;
            j++;
        } else{
            pi[i] = 0;
        }
    }
    return pi;
}

int main(void){
    string str;
    cin>>str;
    int ans = 0;
    for(int i = 0;i < str.size();i++){
        string temp(str.begin()+i, str.end());
        // cout<<temp<<"\n";
        vector<int> pi = preprocess(temp);
        int len = temp.length();
        int candi = 0;
        for(int i = 0;i<len;i++){
            if(candi<pi[i]) candi = pi[i];
        }
        // cout<<candi<<"\n";
        if(ans < candi) ans = candi;
        
    }
 
    cout<<ans<<"\n";
    return 0;
}
