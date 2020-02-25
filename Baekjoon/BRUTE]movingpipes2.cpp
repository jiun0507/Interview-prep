//baekjoon 17069
//파이프 옮기기 2
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int board[33][33];
int n;
int dy[] = {0, 1, 1};
int dx[] = {1, 0, 1};
long long memo[33][33][3];


bool check_range(int y, int x){
    return y>=0 && y<n && x>=0 && x<n && board[y][x] == 0;
}

long long go(int y, int x, int dir){
    // cout<<left.first<<" "<<left.second<<"\n"<<right.first<<" "<<right.second<<"\n\n";
    if(y == n-1 && x == n-1){
        return 1;
    }
    long long &ans = memo[y][x][dir];
    if(ans != -1){
        return ans;
    }
    ans = 0;
    bool zero = check_range(y + dy[0], x + dx[0]);
    bool one = check_range(y + dy[1], x + dx[1]);
    bool two = check_range(y + dy[2], x + dx[2]);
    if(dir == 0){ //세로
        if(one){ 
            pair<int,int> newright = make_pair(y + dy[1], x + dx[1]);
            ans += go(newright.first, newright.second, 0);
            if(two && zero){
                newright.second = newright.second + 1;
                ans += go(newright.first, newright.second, 2);    
            }
            
        }
    }
    else if(dir == 1){ //가로
        if(zero){
            pair<int,int> newright = make_pair(y+ dy[0], x+dx[0]);
            ans += go(newright.first, newright.second, 1);
            if(two&&one){
                newright.first = newright.first + 1;
                ans += go(newright.first, newright.second, 2); 
            } 
        } 
        
    }
    else if(dir == 2){
        pair<int,int> newright = make_pair(y+ dy[0], x+dx[0]);
        if(zero){
            ans += go(newright.first, newright.second, 1);    
        } 
        newright = make_pair(y + dy[1], x +dx[1]);
        if(one){
            ans += go(newright.first, newright.second, 0);
        } 
        newright = make_pair(y + dy[2], x +dx[2]);   
        if(one && two && zero){
            ans += go(newright.first, newright.second, 2);
        }
        
    }
    memo[y][x][dir] = ans;
    return ans;
}

int main(void){
    cin>>n;
    // cout<<n<<"\n";
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin>>board[i][j];
            // cout<<board[i][j]<<" ";
        }
        // cout<<"\n";
    }
    memset(memo, -1, sizeof(memo));
    long long ans = go(0, 1, 1);
    cout<<ans<<"\n";
}
