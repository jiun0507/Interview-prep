//baekjoon 15649
//print m numbers out of n numbers  
#include <iostream>
using namespace std;

int check[10], result[10];

void go(int index, int n, int m){
	if(index == m){
		for(int i = 0; i<m ; i++){
			cout<<result[i]<<" ";
		}
		cout<<"\n";
	}
	for(int i = 1;i<=n;i++){
		if(check[i] == 1){
			continue;
		}
		check[i] = 1;
		result[index] = i;
		go(index + 1, n, m);
		check[i] = 0;
	}
}

int main() {
	int n, m;
	cin >> n>>m;
	go(0,n, m);
	return 0;
}