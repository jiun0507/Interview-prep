//baekjoon 16943
//숫자 재배치
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(void){
    string a;
    int b;
    cin>>a>>b;
    
    sort(a.begin(),a.end());
    reverse(a.begin(), a.end());

    do{
        if(a[0] == '0') break;
        int c = stoi(a);
        if(c<=b){
            cout<<c<<"\n";
            return 0;
        }
        
    }while(prev_permutation(a.begin(), a.end()));
    cout<<"-1\n";
    
}