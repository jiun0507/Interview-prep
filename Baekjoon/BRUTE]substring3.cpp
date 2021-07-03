//baekjoon 16916
//KMP를 사용한 부분 문자열
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

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

    // int begin = 1;
    // int matched = 0;

    // while(begin+matched<p.size()){
    //     //Each loop tries to define pi with index begin+matched.
    //     //if index gets to m it means we're out of bound.
    //     if(p[begin+matched]==p[matched]){
    //         //begin + matched increases by 1.
    //         //remember that the first element's index is 0.
    //         matched++;
    //         pi[begin+matched-1] = matched;
    //     } else{
    //         if(matched==0){
    //             //begin +matched increases by 1
    //             begin++;
    //         } else{
    //             //begin + matched stays the same
    //             begin += matched - pi[matched-1];
    //             matched = pi[matched-1];
    //         }
    //     }
    // }
    return pi;
}

int main(void){
    string s, p;
    cin>>s>>p;
    vector<int> pi = getpi(p);

    int len = s.size();
    int m = p.size();
    // int j = 0;
    // for(int i =0;i<len;i++){
    //     while(j>0 && s[i]!=p[j]){
    //         j = pi[j-1];
    //     }
    //     if(s[i]==p[j]){
    //         j++;
    //         if(j==p.size()){
    //             cout<<1<<"\n";
    //             return 0;
    //         }
    //     }
    // }
    int begin = 1;
    int match = 0;
    while(begin+match<len){
        if(s[begin+match]==p[match]){
            match++;
            s[begin+match-1] = match;
            if(match==m){
                cout<<"1\n";
                return 0;
            }
        } else{
            if(match==0){
                begin++;
            } else{
                begin += match - pi[match-1];
                match = pi[match-1];
            }
        }
    }
    cout<<0<<"\n";


    return 0;
}