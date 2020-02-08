#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int n;
int s;
int input[20];

bool check(int mask){
	int sum = 0;
	for(int i =0;i<n;i++){
		if((mask & (1<<i))>0){
			sum += input[i];
		}
	}
	if(s == sum){
		return true;
	} 
	else{
		return false;
	}
}

//better way ->much simpler
int masking(){
	int sum = 0;
	for(int i = 1; i<(1<<n);i++){
		if(check(i)) sum += 1;
	}
	return sum;
}

int masking2(int index, int mask){
	if(index == n){
		if(check(mask)&&mask != 0){
			//cout<<mask<<"\n";
			return 1;
		}
		return 0;
	}
	int ans = masking2(index + 1, mask);
	mask += 1<<index;
	ans +=masking2(index + 1, mask);
	return ans;
}

int main() {
	
	cin>>n>>s;
	for(int i = 0;i<n;i++){
		cin>>input[i];
	}
	cout<<masking()<<"\n";
}