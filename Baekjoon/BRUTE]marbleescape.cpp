//baekjoon 13460

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
bool check_range(int y, int x){
	return y>=0 && y<n && x>=0 && x<m;
}
void go(int click, int yr, int xr, int yb, int xb){
	if(click>10) return;
	// if(yr == yb && xr == xb) return;
	for(int i = 0;i<4;i++){
		bool blockr = true;
		bool blockb = true;
		int newyr = yr;
		int newxr = xr;
		int newyb = yb;
		int newxb = xb;
		while(blockr||blockb){
			if(blockr && block[newyr][newxr] != 2){
				newyr += newy[i];
				newxr += newx[i];
			}
			else{
				blockr = false;
			}
			if(blockb && block[newyb][newxb] != 2){
				newyb += newy[i];
				newxb += newx[i];
			}
			else{
				blockb = false;
			}
			
			if(newyr=newyb && newxr==newxb){
				if(!blockr){
					newyb -= newy[i];
					newxb -= newx[i];
					
				}
				else if(!blockb){
					newyr -= newy[i];
					newxr -= newx[i];
				}
			}
		}
		while(blockr || blockb){
			newyr += newy[i];
			newxr += newx[i];
			newyb += newy[i];
			newxb += newx[i];
			if(!blockr||block[newyr][newxr] == 2){
				newyr -= newy[i];
				newxr -= newx[i];
				blockr = false;
			}
			if(!blockb || block[newyb][newxb] == 2){
				newyb -= newy[i];
				newxb -= newx[i];
				blockb = false;
			}
			if(newyr=newyb && newxr==newxb){
				if(!blockr){
					newyb -= newy[i];
					newxb -= newx[i];
					
				}
				else if(!blockb){
					newyr -= newy[i];
					newxr -= newx[i];
				}
			}
			if(block[newyr][newxr] == 1){
				if(click<mini){ 
					mini = click;
				}
				found = true;
				return;
			}
			if(block[newyb][newxb] == 1){
				return;
			}
		}
		cout<<newyr<<" "<<newxr<<"\n";
		go(click + 1, newyr, newxr, newyb, newxb);
	}
	return;
}


int main() {
	cin>>n>>m;
	cin.ignore();
	int ans = 0;
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
	for(int i = 0;i<n;i++){
		for(int j =0;j<m;j++){
			cout<<block[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<yr<<" "<<xr<<" "<<yb<<" "<<xb<<"\n";
	go(0, yr, xr, yb, xb);
	if(found == false){
		cout<<"-1"<<"\n";
	}
	else{
		cout<<mini<<"\n";
	}
    return 0;
}