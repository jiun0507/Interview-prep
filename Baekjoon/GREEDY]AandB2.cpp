//baekjoon 12919
//A와 B 2
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
string s;

string cut(string t){
    t.pop_back();
    return t;
}

string revcut(string t){
    reverse(t.begin(), t.end());
    t.pop_back();
    return t;
}

bool fin(string t){
    if(t == s){
        return true;
    }
    if(t.length() == 0) return false;
    if(t.at(0) == 'B'){
        if(t.back() == 'A') return fin(cut(t)) || fin(revcut(t));
        return fin(revcut(t));
    }
    else if(t.back() == 'A'){
        return fin(cut(t));
    }

    // cout<<t<<"\n";
    return false;
    
}

int main(void){
    string t;
    cin>>s;
    cin>>t;

    cout<<fin(t)<<"\n";
    // cout<<a<<"\n"<<b<<"\n";
    
}