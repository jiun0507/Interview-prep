//baekjoon 16916
//KMP를 사용한 부분 문자열
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//kmp와 preprocessing의 time complexity

// O(N)

vector<int> getpi(string &p){
    int len = p.size();
    vector<int> pi(len);
    pi[0] = 0;
    int j = 0;
    for(int i = 1;i<len;i++){
        while(j>0 && p[i]!=p[j]){
            j = pi[j-1];
        }
        if(p[i]==p[j]){
            j++;
            pi[i] = j;
        } else{
            pi[i] = 0;
        }
    }

    return pi;
}

int main(void){
    string s, p;
    cin>>s>>p;
    vector<int> pi = getpi(p);

    int begin = 0;
    int match = 0;
    int n = s.size();
    int m = p.size();
    while(begin<n){
        if(match<m && s[begin+match]==p[match]){
            match++;
            if(begin+match==n){
                cout<<match<<"\n";
                return 0;
            }
        }
        else{
            if(match==0){
                begin++;
            } else{
                begin += match - pi[match-1];
                match = pi[match-1];
            }
        }
    }
    cout<<"0\n";


    return 0;
}