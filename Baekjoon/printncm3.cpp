//baekjoon 15651
//print with overlaps
#include <iostream>
using namespace std;

int result[10];
int result2[10];
int check[10];
void go(int index, int n, int m){
	if(index == m){
		for(int i = 0; i<m ; i++){
			cout<<result[i]<<" ";
		}
		cout<<"\n";
		return;
	}
	for(int i = 1;i<=n;i++){
		result[index] = i;
		go(index + 1, n, m);
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
	go(0, n, m);

	return 0;
}