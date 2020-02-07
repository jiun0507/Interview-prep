//baekjoon 12919
//A와 B 2

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
string s;
bool fin(int a, int b, string t){
    if(a<0 || b<0){
        return false;
    }
    if(t == s){
        return true;
    }
    if(t.at(0) == 'B'){
        bool one;
        if(t.at(t.size()-1) == 'A'){
            string newt = t;
            newt.pop_back();
            one = fin(a-1, b, newt) ;   
        }
        reverse(t.begin(), t.end());
        t.pop_back();
        return one || fin(a, b-1, t);
    }
    else if(t.at(t.size()-1)== 'B'){
        return false;
    }
    else if(t.at(t.size()-1) == 'A'){
        t.pop_back();
        return fin(a-1, b, t);
    }

    // cout<<t<<"\n";
    return false;
    
}

int main(void){
    string t;
    cin>>s;
    cin>>t;
    int a,b;
    a = b = 0;
    for(int i = 0;i<t.size();i++){
        if(t.at(i) == 'A'){
            a++;
        }
        else{
            b++;
            
        }
    }
    for(int i = 0;i<s.size();i++){
        if(s.at(i) == 'A'){
            a--;
        }
        else{
            b--;
            
        }
    }
    cout<<fin(a, b, t);
    // cout<<a<<"\n"<<b<<"\n";
    
}