#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int board[20][20];
int n;
int dy[] = {0, 1, 1};
int dx[] = {1, 0, 1};

bool check_range(int y, int x){
    return y>=0 && y<n && x>=0 && x<n && board[y][x] == 0;
}

int go(pair<int,int> left, pair<int,int> right){
    // cout<<left.first<<" "<<left.second<<"\n"<<right.first<<" "<<right.second<<"\n\n";
    if(right.first == n-1 && right.second == n-1){
        return 1;
    }
    int ddy = right.first - left.first;
    int ddx = right.second - left.second;
    int ans = 0;
    bool zero = check_range(right.first + dy[0], right.second + dx[0]);
    bool one = check_range(right.first + dy[1], right.second + dx[1]);
    bool two = check_range(right.first + dy[2], right.second + dx[2]);
    if(ddx == 0){ //세로
        if(one){ 
            pair<int,int> newright = make_pair(right.first + dy[1], right.second + dx[1]);
            ans += go(right, newright);
            if(two && zero){
                newright.second = newright.second + 1;
                ans += go(right, newright);    
            }
            
        }
    }
    else if(ddy == 0){ //가로
        if(zero){
            pair<int,int> newright = make_pair(right.first+ dy[0], right.second+dx[0]);
            ans += go(right, newright);
            if(two&&one){
                newright.first = newright.first + 1;
                ans += go(right, newright); 
            } 
        } 
        
    }
    else if(ddx == 1 && ddy == 1){
        pair<int,int> newright = make_pair(right.first+ dy[0], right.second+dx[0]);
        if(zero){
            ans += go(right, newright);    
        } 
        newright = make_pair(right.first + dy[1], right.second +dx[1]);
        if(one){
            ans += go(right, newright);
        } 
        newright = make_pair(right.first + dy[2], right.second +dx[2]);   
        if(one && two && zero){
            ans += go(right, newright);
        }
        
    }
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
    int ans = go(make_pair(0, 0), make_pair(0, 1));
    cout<<ans<<"\n";
}