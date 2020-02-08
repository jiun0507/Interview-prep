//baekjoon 13460
//marble escape
//baekjoon 13460
//marble escape

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;

int n,m;
int mini = 1000000001;
int newx[4] = {0, 0, -1, 1};
int newy[4] = {1, -1, 0, 0};
int block[25][25] = {0};
bool found = false;


//in the hole = 1
//blocked = 2
//moved = 0
int simulate(int dir, int &y, int &x){
	int moved = 2;
	while(true){
		int ny = y + newy[dir];
		int nx = x + newx[dir];
		int next = block[ny][nx];
		if(next == 2){
			return moved;
		}
		if(next == 3 || next == 4){
			return moved;
		}

		if(next == 1){
			block[y][x] = 0;
			// cout<<y<<" "<<x<<"\n";
			return 1;	
		} 
		moved = 0;
		//swap
		swap(block[ny][nx], block[y][x]);
		y = ny;
		x = nx;		
	}
	return 5;
	
}
int go(int click, int yr, int xr, int yb, int xb, int dir){
	if(click>10) return 11;
// 	cout<<"click : "<< click<<"\n";
// 	for(int i = 0;i<n;i++){
// 		for(int j =0;j<m;j++){
// 			cout<<block[i][j]<<" ";
// 		}
// 		cout<<"\n";
// 	}
// 	cout<<"\n";
	int nblock[n][m];
	for(int i = 0;i<n;i++){
		for(int j =0;j<m;j++){
		    nblock[i][j] = block[i][j];
		}
	}
	int ans = 11;
	for(int i = 0;i<4;i++){
    	for(int j = 0;j<n;j++){
    		for(int k =0;k<m;k++){
    		    block[j][k] = nblock[j][k];
    		}
    	}
    // 	cout<<i<<" "<<"\n";
		if(dir != -1){
			// if(dir == i) continue;
			if(newy[dir] == newy[i] || newx[dir] == newx[i]) continue;
		}

		int newyr = yr;
		int newxr = xr;
		int newyb = yb;
		int newxb = xb;
		bool blockr = false;
		bool blockb = false;
		bool red = false;
		bool blue = false;
		while(true){
			int r = simulate(i, newyr, newxr);
			int b = simulate(i, newyb, newxb);
			if(r==2 && b==2){
				break;
			}
			if(b == 1){
				blue = true;
				break;
			}
			if(r == 1){
				red = true;
				break;
			}
		}
// 		cout<<newyr<<" "<<newxr<<" "<<newyb<<" "<<newxb<<"\n";
		if(blue) continue;
		if(red){
			return click+1;	
		}
        //This part was the problem. Red sometimes need to stay in the same
        //position to reach the goal.
        //EX
        // 5 7
        // #######
        // #######
        // ###.###
        // #O.BR##
        // #######
// 		if(newyr == yr && newxr == xr ){
// 			continue;
// 		}
		int temp = go(click + 1, newyr, newxr, newyb, newxb, i);
		if(ans > temp) ans = temp;
			
		
	}
	return ans;
}


int main() {
	cin>>n>>m;
	cin.ignore();
	int yr, xr, yb,xb;
	int holey, holex;
	vector<pair<int,int>> coin;
	for(int i = 0;i<n;i++){
		string line;
		getline(cin, line);
		for(int k = 0;k<line.size();k++){
			char c= line.at(k);
			if(c == 'R'){
				yr = i;
				xr = k;
				block[i][k] = 3;
			}
			else if(c == 'B'){
				yb = i;
				xb = k;
				block[i][k] = 4;
			}
			else if(c == 'O'){ 
				block[i][k] = 1;
				holey = i;
				holex = k;
			}
			else if(c == '#') block[i][k] = 2;
			else if(c == '.') block[i][k] = 0;				
		}
	}
// 	for(int i = 0;i<n;i++){
// 		for(int j =0;j<m;j++){
// 			cout<<block[i][j]<<" ";
// 		}
// 		cout<<"\n";
// 	}
	
	// cout<<yr<<" "<<xr<<" "<<yb<<" "<<xb<<"\n";
	int ans = go(0, yr, xr, yb, xb, -1);
	if(ans== 11){
		cout<<-1<<"\n";
	}
	else{
		cout<<ans<<"\n";		
	}

    return 0;
}