//baekjoon 14225
//use bitmask to implement all cases
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> s;
int n;
int subsum[20000000] = {0};

void go(){
	for(int i = 1; i<(1<<n);i++){
		int sum = 0;
		for(int j = 0;j<n;j++){
			if((i&(1<<j)) != 0 ){
				sum += s[j];
			}
		}
		subsum[sum] = 1;
	}
	
	return;
}

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        int temp;
        cin>>temp;
        s.push_back(temp);
    }
	
    go();
	int minimum;
	for(int i = 1;i<20000000;i++){
		if(subsum[i] == 0){ 
			minimum = i;
			break;
		}
	}
	cout<<minimum<<"\n";
    return 0;
}