//baekjoon 9944
//NxN보드 완주하기
#include <iostream>
#include <bits/stdc++.h>
// #include <algorithm>
using namespace std;

int n, m;
int dy[] = {0, 0, -1, 1};
int dx[] = {1, -1, 0, 0};
int board[33][33];
bool checkr(int y, int x){
    return y>=0 && y<n && x>=0 && x<m;
}

int go(int y, int x, int cnt){
    if(cnt==0) return 0;
    int ans = -1;
    for(int i = 0;i<4;i++){
        int newy = y+dy[i];
        int newx = x+dx[i];
        while(checkr(newy, newx) && board[newy][newx] == 0){
            board[newy][newx] = 1;
            cnt--;
            newy+=dy[i];
            newx+=dx[i];
        }
        newy -=dy[i];
        newx -=dx[i];
        if(newy != y || newx != x){
            int temp = go(newy, newx, cnt);
            if(temp != -1){
                if(ans == -1 || ans>temp+1) ans = temp + 1;
            }
                
        }
        while(y!=newy || x != newx){
            cnt++;
            board[newy][newx] = 0;
            newy-=dy[i];
            newx-=dx[i];
        }
    }

    return ans;
}

int main(void){
    int tc = 1;
    while(cin>>n>>m){
        memset(board,0,sizeof(board));
        // cout<<n<<" "<<m<<"\n";
        int cnt = 0;
        for(int i = 0;i<n;i++){
            string s;
            cin>>s; 
            for(int j = 0;j<m;j++){
                if(s.at(j)=='.') cnt++;
                else{
                    board[i][j] = 1;
                }
                // cout<<board[i][j]<<" ";
            }
            // cout<<"\n";
            
        }
        // cout<<cnt<<"\n";
        int ans = -1;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(board[i][j] == 0){
                    board[i][j] = 1;
                    int temp = go(i,j, cnt-1);
                    if(temp!=-1){
                        if(ans == -1 || ans>temp) ans = temp;
                    
                    }
                    board[i][j] = 0;
                }
            }
        }
        cout<<"Case "<<tc<<": "<<ans<<"\n";
        tc++;
    }


}