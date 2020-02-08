//baekjoon 2309
//brute force 일곱난쟁이
#include <iostream>
#include <algorithm>
using namespace std;

int height[9];
int n = 9;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int total = 0;
	for(int i =0;i<n;i++){
		cin>>height[i];
		total += height[i];
	}
	sort(height, height+9);
	bool found = false;
	for(int i =0;i+1<n;i++){
		if(found){
			break;
		}
		for(int j =i+1;j<n;j++){
			if(total - height[i] -height[j] == 100){
				height[i] = height[j]= 0;
				found = true;
				break;
			}
		}
	}
	
	for(int i =0;i<n;i++){
		if(height[i] != 0){
			cout<<height[i]<<"\n";
		}
	}

	return 0;

}