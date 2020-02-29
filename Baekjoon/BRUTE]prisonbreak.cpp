//baekjoon 9376
//탈옥
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int n, m;
int dy[4] = {0, 0, -1, 1};
int dx[4] = {1, -1, 0, 0};

bool check_range(int y, int x){
    return y>=0 && y<n && x>=0 && x<m;
}

vector<vector<int>> BFSprisoner(pair<int,int> &prison1, vector<string> &board){
    vector<vector<int>> doors(n, vector<int>(m));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            doors[i][j] = -1;
        }
    }
	deque<pair<int,int>> list;
	list.push_back(make_pair(prison1.first, prison1.second));
	doors[prison1.first][prison1.second] = 0;
    while(!list.empty()){
        auto p = list.front();
        int y = p.first;
        int x = p.second;
        list.pop_front();
        for(int dir = 0;dir<4;dir++){
            int newy = y + dy[dir];
            int newx = x + dx[dir];

            if(!check_range(newy, newx) || board[newy][newx] == '*' || doors[newy][newx] != -1) continue;
            if(board[newy][newx] == '#'){
                doors[newy][newx] = doors[y][x] + 1;
                list.push_back(make_pair(newy, newx));
            }
            else{
                doors[newy][newx] = doors[y][x];
                list.push_front(make_pair(newy,newx));
            }
        }
        
    }
	return doors;
}

int main() {
    int tc;
    cin>>tc;
    while(tc--){
        cin>>n>>m;
        vector<string> board(n+2);
        pair<int,int> p1, p2;
        p1 = make_pair(-1, -1);
    	for(int i= 1;i<=n;i++){
    	    cin>>board[i];
    	    board[i] = '.'+ board[i] + '.';
    	    for(int j = 0;j<m;j++){
    	        if(board[i][j] == '$'){
    	            if(p1.first == -1){
    	                p1.first = i;
    	                p1.second = j;
    	            }
    	            else{
    	                p2.first = i;
    	                p2.second = j;
    	            }
    	        }
    	    }
    	}
    	n+=2;
        m+=2;
        for(int i = 0;i<m;i++){
            board[0] += '.';
            board[n-1] += '.';
        }
    	pair<int,int> start = make_pair(0, 0);
    
        vector<vector<int>> d1 = BFSprisoner(p1, board);
        vector<vector<int>> d2 = BFSprisoner(p2, board);
        vector<vector<int>> d3 = BFSprisoner(start, board);
        int ans = -1;
        for(int i= 0;i<n;i++){
    	    for(int j = 0;j<m;j++){
    	        if(board[i][j] == '*') continue;
    	        else{
    	            int temp = d1[i][j] + d2[i][j] + d3[i][j];
    	            if(board[i][j] == '#'){
    	                temp -=2;
    	            }
    	            if(ans == -1 || ans>temp) ans = temp;
    	        }
    	    }
    	}
    	if(ans == -1){
    	    cout<<"0\n";
    	} 
    	else{
            cout<<ans<<"\n";
    	}
        
    }

	return 0;
}
