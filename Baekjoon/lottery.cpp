//baekjoon 6603
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool next_permutation(int *a, int n){
	int i = n-1;
	while(i>0 && a[i]<=a[i-1]) i--;
	if(i<=0){
		return false;
	}
	int j = n-1;
	while(a[i-1]>=a[j]){
		j--;
	}
	swap(a[i-1],a[j]);
	j = n-1;
	while(j>i){
		swap(a[j], a[i]);
		i+=1; 
		j-=1;
	}
	return true;
}
int main() {
	while(true){
		int n;
		cin>>n;
		if(n == 0) break;
		int input[n];
		vector<vector<int>> ans;
		for(int i = 0;i<n;i++){
			cin>>input[i];
		}
		int choice[n];
		for(int i = 0;i<n-6;i++){
			choice[i] = 0;
		}
		for(int i = n-6;i<n;i++){
			choice[i] = 1;
		}
		do{
			vector<int> current;
			for(int i = 0;i<n;i++){
				if(choice[i] == 1){
					current.push_back(input[i]);
				}
			}
			ans.push_back(current);
		}while(next_permutation(choice, n));
		sort(ans.begin(),ans.end());
		for(auto &vec:ans){
			for(int i =0;i<6;i++){
				cout<<vec[i]<<" ";
			}
			cout<<"\n";
		}
		cout<<"\n";
	}
	
	
	return 0;
}