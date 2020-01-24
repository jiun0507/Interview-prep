//baekjoon 14888 baekjoon 15658
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> s;
int n;
int subsum[20000000] = {0};
int maxi = -1000000001;
int mini = 1000000001;

void go(vector<int> &numbers, vector<int> &op,int index, int sum){
	if(index ==n){
		if(maxi<sum) maxi = sum;
		if(mini>sum) mini = sum;
		return;
	}
	if(op[0] > 0){
		op[0] -=1;
		go(numbers, op, index + 1, sum + numbers[index]);
		op[0] +=1;
	}
	if(op[1] >0){
		op[1] -=1;
		go(numbers, op, index + 1, sum - numbers[index]);
		op[1] +=1;
	}
	if(op[2] >0){
		op[2] -=1;
		go(numbers, op, index + 1, sum * numbers[index]);
		op[2] +=1;
	}
	if(op[3] >0){
		op[3] -=1;
		go(numbers, op, index + 1, sum / numbers[index]);
		op[3] +=1;
	}
	return;
}

int main() {
	cin>>n;
	vector<int> numbers(n);
	vector<int> op(4);
	for(int i = 0;i<n;i++){
		cin>>numbers[i];
	}
	for(int i = 0;i<4;i++){
		cin>>op[i];
	}

	go(numbers, op, 1, numbers[0]);
	cout<<maxi<<"\n";
	cout<<mini<<"\n";
	
    return 0;
}