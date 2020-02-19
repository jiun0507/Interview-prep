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
vector<string> store;

bool check_range(int y, int x){
    return y>=0 && y<width && x>=0 && x<width;
}

void go(int y, int x, string num){
    if(num.length() == 6){
         store.push_back(num);
         return;
    }
    
    for(int i = 0;i<4;i++){
        string cur = num;
        int newy = y+dy[i];
        int newx = x+dx[i];
        if(check_range(newy, newx)) go(newy, newx, cur.append(to_string(board[newy][newx])));
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
            go(i, j, to_string(board[i][j]));
       }
   }
   
   sort(store.begin(), store.end());
   int count = distance(store.begin(), unique(store.begin(), store.end())); 
   cout<<count<<"\n";
}