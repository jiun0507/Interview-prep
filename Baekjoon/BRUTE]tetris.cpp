//baekjoon 3019
//테트리스
#include <iostream>
#include <bits/stdc++.h>
// #include <algorithm>
using namespace std;
int heights[100];
int width, tetris;
int go(int index, string tet){
    int base = heights[index]-(tet.at(0)-'0');
    
    if(width<index+tet.size()||base<0) return 0;
    for(int i = 0;i<tet.size();i++){
        if(heights[index+i]-base!= tet.at(i)-'0') return 0;
    }
    return 1;
}

int main(void){
    cin>>width>>tetris;
    int smallest = -1;
    for(int i = 0;i<width;i++){
       cin>>heights[i];
       if(smallest == -1|| smallest>heights[i]) smallest = heights[i];
    }
    for(int i = 0;i<width;i++){
        heights[i] -= smallest;
        // cout<<heights[i];
    }
    int ans = 0;
    for(int i = 0;i<width;i++){
        if(tetris == 1){
            ans+= go(i, "0") + go(i, "0000");
        }
        else if(tetris == 2){
            ans+= go(i, "00");
        }
        else if(tetris == 3){
            ans+= go(i, "001")+go(i,"10");
        }
        else if(tetris == 4){
            ans+= go(i, "100")+go(i,"01");
        }
        else if(tetris == 5){
            ans+= go(i, "000")+go(i,"01")+go(i,"101")+go(i,"10");
        }
        else if(tetris == 6){
            ans+= go(i, "000")+go(i,"00")+go(i,"011")+go(i,"20");
        }
        else if(tetris == 7){
            ans += go(i, "000")+go(i,"00")+go(i,"110")+go(i,"02");
        }
    }
    cout<<ans<<"\n";

    return 0;
    
}