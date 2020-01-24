//baekjoon 16197

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;

int n,m;
int mini = 1000000001;
int newx[4] = {0, 0, 1, -1};
int newy[4] = {1, -1, 0, 0};
int block[25][25] = {0};
bool found = false;
void go(int click, int y1, int x1, int y2, int x2){
	if(click>10) return;
	if(y1 < 0 || y1>=n || x1<0 || x1>=m || y2 < 0 || y2>=n || x2<0 || x2>=m){
		if((y1<0||y1>=n || x1<0 || x1>= m) && (y2<0||y2>=n || x2<0 || x2>= m)) return;
		if(click<mini){ 
			mini = click;
		}
		found = true;
		return;
	}
	// bool fall1 = false, fall2= false;
	// if (x1 < 0 || x1 >= m || y1 < 0 || y1 >= n) fall1 = true;
 //   if (x2 < 0 || x2 >= m || y2 < 0 || y2 >= n) fall2 = true;
 //   if (fall1 && fall2) return;
 //   if (fall1 || fall2){
 //   	if(click<mini){
 //   		mini = click;
 //   	}
 //   	found = true;
 //   	return;
 //   }
	for(int i = 0;i<4;i++){
		int newy1 = y1 + newy[i];
		int newx1 = x1 + newx[i];
		int newy2 = y2 + newy[i];
		int newx2 = x2 + newx[i];
		if(newy1>=0 && newy1<n && newx2>=0 && newx2< m && block[newy1][newx1] == 2){
			newy1 = y1;
			newx1 = x1;
		}
		if(newy2>=0 && newy2<n && newx2>=0 && newx2< m && block[newy2][newx2] == 2){
			newy2 = y2;
			newx2 = x2;
		}
		go(click + 1, newy1, newx1, newy2, newx2);
	}
	return;
}


int main() {
	cin>>n>>m;
	cin.ignore();
	int ans = 0;
	vector<pair<int,int>> coin;
	for(int i = 0;i<n;i++){
		string line;
		getline(cin, line);
		for(int k = 0;k<line.size();k++){
			char c= line.at(k);
			if(c == 'o'){ 
				block[i][k] = 0;
				coin.push_back(make_pair(i, k));
			}
			else if(c == '#') block[i][k] = 2;
			else if(c == '.') block[i][k] = 0;				
		}
	}
	int y1 = coin[0].first;
	int x1 = coin[0].second;
	int y2 = coin[1].first;
	int x2 = coin[1].second;
	go(0, y1, x1, y2, x2);
	if(found == false){
		cout<<"-1"<<"\n";
	}
	else{
		cout<<mini<<"\n";
	}
    return 0;
}