//baekjoon 15652
//nbym incremental with overlaps
#include <iostream>
using namespace std;

int result[10];
int cnt[10];
int check[10];
void go(int index, int start, int n, int m){
	if(index == m){
		for(int i = 0; i<m ; i++){
			cout<<result[i]<<" ";
		}
		cout<<"\n";
		return;
	}
	for(int i = start;i<=n;i++){
		result[index] = i;
		go(index + 1, i, n, m);
	}
}

void go2(int index, int selected, int n , int m){
	if(selected == m){
		for(int i = 1; i<=n;i++){
			for(int j = 0;j<cnt[i]; j++) cout<<i<<" ";
		}
		cout<<"\n";
		return;
	}
	if(index>n){
		return;
	}
	for(int i = m-selected; i>=1; i--){
		cnt[index] = i;
		go2(index+1, selected +i, n,m);
	}
	cnt[index] = 0;
	go2(index + 1, selected, n, m);
	
}

int main() {
	int n, m;
	cin >> n>>m;
	go(0, 1, n, m);

	return 0;
}