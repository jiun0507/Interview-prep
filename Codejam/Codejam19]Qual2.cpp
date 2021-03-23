

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    int cnt =1 ;
    while(t--){
        cout<<"Case #"<<cnt++<<": ";
        int n;
        cin>>n;
        map<int,int> board[n];
        string lydia;
        cin>>lydia;
        int y = 0;
        int x = 0;
        for(int i = 0;i<lydia.size();i++){
            if(lydia[i]=='E'){
                board[y][x] = 0;
                x += 1;
            } else{
                board[y][x] = 1;
                y += 1;
            }
        }
        y = 0;
        x = 0;
        vector<char> path;
        while(y!=n-1 || x != n-1){
            int dirs[2] = {1, 1};
            if(board[y].find(x)!=board[y].end()){
                dirs[board[y][x]] = 0;
            }
            if(dirs[0]==1 && x < n-1){
                path.push_back('E');
                x += 1;
            } else if(dirs[1]==1&&y<n-1){
                path.push_back('S');
                y += 1;
            }
        }
        for(auto a: path){
            cout<<a;
        }
        cout<<"\n";
    }


    return 0;
}
