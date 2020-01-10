//baekjoon 15651
//nbym non incremental with overlaps
//erase things with check
#include <iostream>
using namespace std;

int result[10];
int cnt[10];
int check[10];
void go(int selected, int n, int m){
	if(selected == m){
		for(int i = 0; i<m ; i++){
			cout<<result[i]<<" ";
		}
		cout<<"\n";
		return;
	}
	for(int i = 1;i<=n;i++){
		result[selected] = i;
		go(selected+ 1, n, m);
	}
}

int main() {
	int n, m;
	cin >> n>>m;
	go(0, n, m);

	return 0;
}