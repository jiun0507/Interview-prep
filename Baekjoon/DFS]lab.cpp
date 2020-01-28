//baekjoon 14502
//연구실

#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int n,m;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, -1, 1};
vector<vector<int>> test;
bool check_range(int y, int x){
    return y>=0 & y<n && x>=0 && x<m;   
}
void go2(int y, int x){
	test[y][x] = 2;
	for(int i = 0;i<4;i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(check_range(ny ,nx)){
		    if(test[ny][nx] == 0){
		        go2(ny ,nx);
		    }
		}
	}
	return;
}
int go(vector<vector<int>> d){
    queue<pair<int,int>> q;
    for(int i =0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(d[i][j] == 2){
                q.push(make_pair(i,j));
            }
        }
    }   
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        int y = cur.first;
        int x = cur.second;
        for(int i = 0;i<4;i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(!check_range(ny , nx)) continue;
            if(d[ny][nx]==0){
                d[ny][nx] = 2;
                q.push(make_pair(ny,nx));  
            }
           
        }
    }
    int cnt = 0;
    for(int i =0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(d[i][j] == 0){
                cnt++;
            }
        }
    } 
    return cnt;
}

int count(vector<vector<int>> & test){
    int cnt = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(test[i][j] == 0) cnt++;
        }
    }
    return cnt;
}


int main(){
    cin>>n>>m;
    vector<vector<int>> d(n, vector<int>(m));
    vector<pair<int, int>> virus;
    for(int i =0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>d[i][j];
            if(d[i][j] == 2){
                virus.push_back(make_pair(i,j));
            }
        }
    }
    // cout<<virus[0].first<<" "<<virus[0].second<<"\n";
    // cout<<virus[1].first<<" "<<virus[1].second<<"\n";
    
    int ans = -1;
    for(int i =0;i<n*m;i++){
        for(int j = 0;j<n*m;j++){
            for(int k = 0;k<n*m;k++){
                if(i == j || i == k || j == k) continue;
                if(d[i/m][i%m] != 0 || d[j/m][j%m]!= 0|| d[k/m][k%m] != 0) continue;
                d[i/m][i%m] = 1; d[j/m][j%m] = 1; d[k/m][k%m] = 1;
                test = d;
                for(int l = 0;l<virus.size();l++){
                    go2(virus[l].first, virus[l].second);
                }
                int cnt = count(test);
                
                if(cnt > ans) ans = cnt;
                d[i/m][i%m] = 0; d[j/m][j%m] = 0; d[k/m][k%m] = 0;                
            }
            
        }
    }
    cout<<ans<<"\n";    
    
    return 0;
}