

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

map<long long,int> board;
map<long long,int> dp;

long long n;

bool dfs(long long y, long long x, stack<char> &ans){
    if(y==n-1&&x==n-1){
        return true;
    }   
    if(dp.find(y*n+x)!=dp.end()) return false;
    int dirs[2] = {1, 1};
    if(board.find(y*n+x)!=board.end()){
        dirs[board[y*n+x]] = 0;
    }   
    if(dirs[0]==1 && x < n-1){
        ans.push('E');
        if(dfs(y, x+1, ans)){
            return true;
        } else{
            ans.pop();
        }
    } 
    if(dirs[1]==1&&y<n-1){
        ans.push('S');
        if(dfs(y+1, x, ans)){
            return true;
        } else{
            ans.pop();
        }
    }
    dp[y*n+x] = 1;
    return false;

}

int main()
{
    int t;
    cin>>t;
    int cnt =1 ;
    while(t--){
        cout<<"Case #"<<cnt++<<": ";
        cin>>n;
        string lydia;
        cin>>lydia;
        long long y = 0;
        long long x = 0;
        for(int i = 0;i<2*n-2;i++){
            if(lydia[i]=='E'){
                board[y*n+x] = 0;
                x += 1;
            } else{
                board[y*n+x] = 1;
                y += 1;
            }
        }
        stack<char> path;
        dfs(0, 0, path);
        stack<char> ans;
        while(!path.empty()){
            ans.push(path.top());
            path.pop();
        }
        while(!ans.empty()){
            cout<<ans.top();
            ans.pop();
        }
        cout<<"\n";
        board.clear();
        dp.clear();

    }


    return 0;
}
