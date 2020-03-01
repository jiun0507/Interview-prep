//baekjoon 4991
//로봇 청소기
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};
int board[30][30];
int n, m;
int dist[30][30][15];

int BFSmonkey(int r, int c, int id){
	queue<pair<int, int>> list;
	list.push(make_pair(r, c));
	dist[r][c][id] = 0;
    while(!list.empty()){
        
        int y, x;
        tie(y, x) = list.front();
        list.pop();
        // cout<<y<<" "<<x<<" "<<jump<<" "<<dist[y][x][jump]<<"\n";
        for(int l = 0; l<4; l++){
            int newy = y + dy[l];
            int newx = x + dx[l];
            if(0 <= newx && newx <m && 0 <= newy && newy < n){
                if(board[newy][newx] == -1) continue;
                if(dist[newy][newx][id] == -1){
                    dist[newy][newx][id] = dist[y][x][id] + 1;
                    list.push(make_pair(newy, newx));
                }                      
                
 
            }
        } 

    }
    return -1;
}

int main() {
    while(cin>>m>>n){
        
        if(m == 0 || n == 0){
            break;
        }
        int id = 1;
        vector<pair<int,int>> spots(15);
        for(int i = 0;i<n;i++){
            string buf;
            cin>>buf;
            for(int j = 0;j<m;j++){
                if(buf.at(j) == '.'){
                    board[i][j] = 0;
                }
                else if(buf.at(j) == '*'){
                    id++;
                    board[i][j] = id;
                    spots[id] = make_pair(i,j);
                }
                else if(buf.at(j) == 'o'){
                    board[i][j] = 1;
                    spots[1] = make_pair(i,j);
                }
                else if(buf.at(j) == 'x'){
                    board[i][j] = -1;
                }
            }
        }
        memset(dist, -1, sizeof(dist));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(board[i][j] == 0 || board[i][j] == -1) continue;
                BFSmonkey(i,j,board[i][j]);
            }
        }
        
        vector<int> order;
        for(int i = 1;i<=id;i++){
            order.push_back(i);
        }
        int ans = -1;
        bool clean = true;
        do{
            int temp = 0;
            for(int i = 0;i<order.size()-1;i++){
                auto p = spots[order[i]];
                // cout<<dist[p.first][p.second][order[i+1]]<<" ";
                int distance = dist[p.first][p.second][order[i+1]];
                if(distance == -1){
                    clean = false;
                    break;
                }
                temp += dist[p.first][p.second][order[i+1]];
                
            }
            // cout<<temp<<"\n";
            if(ans==-1 || temp<ans) ans = temp;
            // for(int i= 0;i<order.size();i++){
            //     cout<<order[i]<<" ";
            // }
            // cout<<"\n";
            
        }while(clean&&next_permutation(order.begin()+1, order.end()));
        if(!clean){
            cout<<"-1\n";
        }
        else{
            cout<<ans<<"\n";        
        }

    }
    

    
	return 0;
}