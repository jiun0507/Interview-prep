
//baekjoon 17406
//배열 돌리기4
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n, m, k;

void rotation(vector<vector<int>> &board, tuple<int,int,int> move){
    int y, x, size;
    tie(y, x, size) = move;
    vector<vector<int>> groups(size+1);
    for(int l = 1;l<=size;l++){
        vector<int> group;
        for(int i = x-l;i<x+l;i++){
            group.push_back(board[y-l][i]);
        }
        for(int i = y-l;i<y+l;i++){
            group.push_back(board[i][x+l]);
        }
        for(int i = x+l;i>x-l;i--){
            group.push_back(board[y+l][i]);
        }
        for(int i = y+l;i>y-l;i--){
            group.push_back(board[i][x-l]);
        }
        groups[l-1] = group;
    }
    
    for(int l = 1;l<=size;l++){
        auto& group = groups[l-1];
        //rotate(begin, the pointer that comes at beginning, end)
        //since using begin, end pointer function gives us left rotation I used rbegin, rend which is 
        //reverse iterator for vector
        rotate(group.rbegin(), group.rbegin()+1, group.rend());
        int index = 0;
        for(int i = x-l;i<x+l;i++){
            board[y-l][i] = group[index++];
        }
        for(int i = y-l;i<y+l;i++){
            board[i][x+l] = group[index++];
        }
        for(int i = x+l;i>x-l;i--){
            board[y+l][i] = group[index++];
        }
        for(int i = y+l;i>y-l;i--){
            board[i][x-l] = group[index++];
        }
    }
}

int main(void){
    
    cin>>n>>m;
    cin>>k;
    vector<vector<int>> board(n+1, vector<int>(m+1));
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            cin>>board[i][j];
            // cout<<board[i][j]<<" ";
        }
        // cout<<"\n";
    }
    vector<tuple<int,int,int>> moves(k);
    for(int i = 0;i<k;i++){
        int y, x, size;
        cin>>y>>x>>size;
        moves[i] = (make_tuple(y, x, size));
    }

    sort(moves.begin(), moves.end());
    int ans = -1;
    do{
        vector<vector<int>> current = board;
        for(int i = 0;i<k;i++){
            rotation(current, moves[i]);
        }
        int sum = -1;
        for(int i = 1;i<=n;i++){
            int temp = 0;
            for(int j = 1;j<=m;j++){
                temp += current[i][j];
                // cout<<current[i][j]<<" ";
            }
            // cout<<"\n";
        
            if(sum == -1 || sum>temp) sum = temp;
        }
        if(ans==-1||ans>sum) ans = sum;
        
    }while(next_permutation(moves.begin(), moves.end()));
    cout<<ans<<"\n";
}