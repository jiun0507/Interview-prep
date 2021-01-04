//baekjoon 16968
//차량번호판 1
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int go(string &a, int index, char last){
    if(index == a.length()){
        return 1;
    }
    int ans = 0;
    char start = (a.at(index) == 'd'? '0':'a');
    char end = (a.at(index) == 'd'? '9':'z');
    for(char i = start;i<=end;i++){
        if(i != last){
            ans += go(a, index + 1, i);
        }
    }
    return ans;
}

int main(void){
    string board;
    cin>>board;
    int ans = go(board, 0, 'A');
    cout<<ans<<"\n";
    
}