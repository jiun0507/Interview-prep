//baekjoon 14888

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int calc(vector<int> &d, vector<int> &numbers){
	int result = numbers[0];
	int m = d.size();
	for(int i = 0;i<m;i++){
		int symbol = d[i];
		if(symbol == 0) result += numbers[i+1];
		else if(symbol == 1) result -= numbers[i+1];
		else if(symbol == 2) result *= numbers[i+1];
		else if(symbol == 3) result /= numbers[i+1];
	}
	return result;
}

int main() {
	int n;
	cin>>n;
	vector<int> numbers(n);
	vector<int> d;
	for(int i = 0;i<n;i++){
		cin>>numbers[i];
	}
	for(int i = 0;i<4;i++){
		int sym;
		cin>>sym;
		for(int j = 0;j<sym;j++){
			d.push_back(i);
		}
	}
	sort(d.begin(),d.end());
	int maxAns =-1000000001;
	int minAns =1000000001;
 	do{
		int temp = calc(d, numbers);
		if(maxAns<temp){
			maxAns = temp;
		}
		if(minAns > temp){
			minAns = temp;
		}
	}while(next_permutation(d.begin(),d.end()));
	cout<<maxAns<<"\n";
	cout<<minAns<<"\n";

	return 0;
}