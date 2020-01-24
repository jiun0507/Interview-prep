//baekjoon 6603 

//lottery question using permutation.
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int main() {
	int k;
	cin>>k;
	while(k != 0){
		vector<int> d(k);
		for(int i = 0;i<k;i++){
			cin>>d[i];
		}
		vector<int> combination(k);
		for(int i = 0;i<6;i++){
			combination[i] = 1;
		}
		do{
			for(int i = 0;i<k;i++){
				if(combination[i] != 0){
					cout<<d[i]<<" ";
				}
			}
			cout<<"\n";
		}while(prev_permutation(combination.begin(), combination.end()));
		cin>>k;
		cout<<"\n";
	}
	
	return 0;
}