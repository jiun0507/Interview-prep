//baekjoon 14225

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> s;
int n;
int subsum[20000000] = {0};

void go(int index, int sum){
	if(index ==n){
		subsum[sum] = 1;
		return;
	}
	
	go(index+1, sum + s[index]);
	go(index+1, sum);
	return;
}

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        int temp;
        cin>>temp;
        s.push_back(temp);
    }
  //  for (int i=0; i<n; i++) {
		// cout<<s[i]<<"\n";
  //  }
    go(0, 0);
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