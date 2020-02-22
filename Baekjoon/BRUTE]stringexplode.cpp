//baekjoon 9935
//문자열 폭발
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(void){
    string line;
    string bomb;
    
    cin>>line;
    cin>>bomb;
    stack<char> detect;
    int bombindex = 0;
    int bombarray[line.size()+1];
    for(int i = 0;i<line.size();i++){
        char cur = line.at(i);
        detect.push(cur);
        if(cur == bomb.at(bombindex)){
             bombindex++;
             bombarray[detect.size()-1] = bombindex;
        }
        else{
            bombindex = 0;
            if(cur == bomb.at(bombindex)) bombindex++;
            bombarray[detect.size()-1] = bombindex;
        }
        if(bombindex == bomb.size()){
            for(int j = 0;j<bomb.size();j++){ detect.pop();}
            if(detect.size() == 0){
                bombindex = 0;
            }
            else{bombindex = bombarray[detect.size()-1];}
        }
    }
    string ans = "";
    while(!detect.empty()){
        ans += detect.top();
        detect.pop();
    }
    if(ans.size() == 0){
        cout<<"FRULA\n";
        return 0;
    }
    reverse(ans.begin(), ans.end());
    cout<<ans<<"\n";
}