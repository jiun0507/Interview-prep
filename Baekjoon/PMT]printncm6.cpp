//baekjoon 15654
//nbym incremental with overlaps
#include <iostream>
#include <algorithm>
using namespace std;

int result2[10];
int check[10];
int input[10];
void go(int index, int start, int n, int m){
	if(index == m){
		for(int i = 0; i<m ; i++){
			cout<<result[i]<<" ";
		}
		cout<<"\n";
		return;
	}
	for(int i = start;i<=n;i++){
		result[selected] = i;
		go(index+1,i+1, n, m);
	}
}
//most significant
void go2(int index, int selected, int n , int m){
	if(selected == m){
		for(int i =0;i<m;i++){
			cout<<result2[i]<<" ";
		}
		cout<<"\n";
		return;
	}
	if(index==n){
		return;
	}
	check[index] = 1;
	result2[selected] = input[index];
	go2(index +1, selected +1, n,m);
	check[index] = 0;
	go2(index + 1, selected, n, m);
	
}

int main() {
	int n, m;
	cin >> n>>m;
	for(int i = 0;i<n;i++){
		cin>>input[i];
	}
	sort(input, input+n);
	go2(0,0, n, m);

	return 0;
}