//baekjoon 1981
//배열에서 이동
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int nums[101][101];
int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};
int check[101][101];
int n;
bool check_range(int y, int x){
    return y>=0 && y<n && x>=0 && x<n;
}
bool BFSlist(int mn, int mx){
    if(nums[0][0]<mn || nums[0][0]>mx){
        return false;
    }
    memset(check, 0, sizeof(check));
	queue<pair<int,int>> q;
	q.push(make_pair(0, 0));
	check[0][0] = 1;
	
	while(!q.empty()){
	    auto p = q.front();
	    q.pop();
	    int y = p.first;
	    int x = p.second;
	    for(int i = 0;i<4;i++){
	        int newy = y+ dy[i];
	        int newx = x+ dx[i];
	        if(check_range(newy, newx) && !check[newy][newx] && nums[newy][newx]>=mn && nums[newy][newx]<=mx){
	            q.push(make_pair(newy, newx));
	            check[newy][newx] = 1;
	        }
	    }
	}
	return check[n-1][n-1] == 1;
}

bool go(int diff){
    for(int i = diff; i<=200;i++){
        if(BFSlist(i-diff, i)) return true;
    }
    return false;
}

int main(void){
    cin>>n;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin>>nums[i][j];
        }
        // cout<<"\n";
    }
    // cout<<right<<"\n";
    int left = 0;
    int right = 200;
    // cout<<right<<" "<<left<<"\n";
    int ans= 200;
    while(left<=right){
        int middle = (right+left)/2;
        if(go(middle)){
            ans = min(ans, middle);
            right = middle -1;
        }
        else{
            left = middle + 1;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
