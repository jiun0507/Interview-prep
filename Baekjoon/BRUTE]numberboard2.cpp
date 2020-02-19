//baekjoon 2210
//숫자판 점프
#include <iostream>
#include <bits/stdc++.h>
// #include <algorithm>
using namespace std;
int n,m;
int board[50][50];
int width = 5;
int dy[] = {0, 0, -1, 1};
int dx[] = {1, -1, 0, 0};
set<int> store;

bool check_range(int y, int x){
    return y>=0 && y<width && x>=0 && x<width;
}

void go(int y, int x, int num, int len){
    if(len == 6){
         store.insert(num);
         return;
    }
    
    for(int i = 0;i<4;i++){
        int newy = y+dy[i];
        int newx = x+dx[i];
        if(check_range(newy, newx)) go(newy, newx, num*10 + board[newy][newx], len+1);
    }
}


int main(void){
   for(int i = 0;i<width;i++){
       for(int j = 0;j<width;j++){
           cin>>board[i][j];
       }
   }
   for(int i = 0;i<width;i++){
       for(int j = 0;j<width;j++){
            go(i, j, board[i][j], 1);
       }
   }
   
  cout<<store.size()<<"\n";
}