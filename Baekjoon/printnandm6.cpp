//baekjoon 15655
#include <iostream>
#include <algorithm>
using namespace std;



int result[10];
int check[10];
int array[10];
void go(int index, int start, int n, int m){
	if(index == m){
		for(int i = 0; i<m ; i++){
			cout<<result[i]<<" ";
		}
		cout<<"\n";
	}
	for(int i = start;i<n;i++){
		if(check[i] == 1){
			continue;
		}
		check[i] = 1;
		result[index] = array[i];
		go(index + 1, i + 1, n, m);
		check[i] = 0;
	}
}
int main() {
	int n, m;
	cin >> n>>m;
	
	for(int i = 0;i<n;i++){
		cin>>array[i];
	}

	sort(array, array+n);
	go(0,0,n,m);
	return 0;
}