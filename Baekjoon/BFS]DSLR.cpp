//baekjoon 9019
//DSLR

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int n;
int pre[10001];
int ops[10001];


bool check_range(int y, int x){
	return y>=0 && y<n && x>=0 && x<n;
}
bool BFS(int from, int to){
	queue<int> list;
	list.push(from);
	pre[from] = from;
	while(!list.empty()){
		int cur = list.front();
		list.pop();
		if(cur == to) return true;
		for(int i = 0;i<4;i++){
			int next;
			if(i == 0){
				next = cur*2%10000;
			}
			else if(i == 1){
				next = ((cur-1)+10000)%10000;
			}
			else if(i == 2){
				next = (cur * 10)%10000 + cur/1000;
			}
			else{
				next = (cur%10)*1000 + cur/10;
			}
			if(pre[next] == -1){
				pre[next] = cur;
				list.push(next);
				ops[next] = i;
			}
		}
		
	}
	return false;
}

char change(int i){
	if(i ==0) return 'D';
	if(i == 1) return 'S';
	if(i ==2) return 'L';
	if(i == 3) return 'R';
}
int main() {
	cin>>n;
	for(int j = 0;j<n;j++){
		int from, to;
		cin>>from>>to;
		memset(pre,-1, sizeof(pre));
		memset(ops, -1, sizeof(ops));
		BFS(from , to);
		int cur = to;
		vector<char> pro;
		while(true){
			pro.push_back(change(ops[cur]));
			cur = pre[cur];
			if(cur == from){
				break;
			}
		}
		for(int i = pro.size()-1;i>=0;i--){
			cout<<pro[i]<<"";
		}	
		cout<<"\n";
	}

    return 0;
}