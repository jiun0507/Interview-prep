//baekjoon 6603

//recursively permute through all possible cases
//input is increasing order + order of recursion ->  automatically 사전순
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> input;

void go(vector<int> &d, int index, int cnt){
	if(cnt == 6){
		for(int i = 0;i<6;i++){
			cout<<d[i]<<" ";
		}
		cout<<"\n";
		return;
	}
	if(index >= input.size()) return;
	d.push_back(input[index]);
	go(d, index+1, cnt+1);
	d.pop_back();
	go(d, index + 1, cnt);
	return;
}

int main() {
	int k;
	cin>>k;
	while(k != 0){
		for(int i = 0;i<k;i++){
			int temp;
			cin>>temp;
			input.push_back(temp);
		}

		vector<int> d;
		go(d, 0, 0);
		cout<<"\n";
		input.clear();
		cin>>k;
	}
	
	return 0;
}