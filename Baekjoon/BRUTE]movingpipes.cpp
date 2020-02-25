//baekjoon 17070
//파이프 옮기기 1
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int board[20][20];
int n;
int dy[3] = {0, 1, 1};
int dx[3] = {1, 0, 1};

bool check_range(int y, int x){
    return y>=0 && y<n && x>=0 && x<n && board[y][x] == 0;
}


int go(pair<int,int> left, pair<int,int> right){
    cout<<left.first<<" "<<left.second<<"\n"<<right.first<<" "<<right.second<<"\n\n";
    if(right.first == n-1 && right.second == n-1){
        return 1;
    }
    int ddy = right.first - left.first;
    int ddx = right.second - left.second;
    int ans = 0;
    if(ddx == 0){ //세로
        if(check_range(right.first + dy[1], right.second + dx[1]) ){ 
            pair<int,int> newright = make_pair(right.first + dy[1], right.second + dy[1]);
             ans += go(right, newright);
            if(check_range(right.first + dy[2], right.second + dx[2]) && check_range(right.first + dy[0], right.second + dx[0])){
                newright.second = newright.second + 1;
                ans += go(right, newright);    
            }
            
        }
        
       
    }
    if(ddy == 0){ //가로
        if(check_range(right.first + dy[0], right.second + dx[0])){
            pair<int,int> newright = make_pair(right.first+ dy[0], right.second+dx[0]);
            ans += go(right, newright);
            if(check_range(right.first + dy[2], right.second + dx[2]) &&check_range(right.first + dy[1], right.second + dx[1])){
                newright.first++;
                ans += go(right, newright); 
            } 
        } 
        
    }
    else{
        pair<int,int> newright = make_pair(right.first+ dy[0], right.second+dx[0]);
        ans= 0;
        bool one = false;
        bool two = false;
        if(check_range(right.first + dy[0], right.second + dx[0])){
            ans += go(right, newright);    
            one = true;
        } 
        newright = make_pair(right.first + dy[1], right.second +dx[1]);
        if(check_range(right.first + dy[1], right.second + dx[1])){
            ans += go(right, newright);
            two = true;
        } 
        newright = make_pair(right.first + dy[2], right.second +dx[2]);   
        if(check_range(right.first + dy[2], right.second + dx[2]) && one && two){
            ans += go(right, newright);
        }
        
    }
    return ans;
}

int main(void){
    cin>>n;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin>>board[i][j];
        }
    }
    int ans = go(make_pair(0, 0), make_pair(0, 1));
    cout<<ans<<"\n";
}
