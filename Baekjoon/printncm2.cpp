//baekjoon 15650
//Two ways of solving it
#include <iostream>
using namespace std;

int result[10];
int result2[10];
int check[10];
void go(int index, int start, int n, int m){
	if(index == m){
		for(int i = 0; i<m ; i++){
			cout<<result[i]<<" ";
		}
		cout<<"\n";
	}
	for(int i = start;i<=n;i++){
		check[i] = 1;
		result[index] = i;
		go(index + 1, i + 1, n, m);
		check[i] = 0;
	}
}
void go2(int index, int selected, int n , int m){
	if(selected == m){
		for(int i = 0; i<m;i++){
			cout<<result2[i]<<" ";
		}
		cout<<"\n";
		return;
	}
	if(index>n){
		return;
	}
	result2[selected] = index;
	go2(index + 1, selected +1, n, m);
	result2[selected] = 0;
	go2(index + 1, selected, n, m);
	
}

int main() {
	int n, m;
	cin >> n>>m;
	go(0, 1, n, m);
	go2(1,0, n,m);
	return 0;
}