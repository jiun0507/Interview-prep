//baekjoon 14501

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;

int n;
int maxi = -1000000001;
vector<int> day;
vector<int> pay;


int go(int d, int sum){
	if(d == n){
		return sum;
	}
	int ans = go(d+1, sum);
	if(d+day[d] <=n){
		ans = max(ans, go(d + day[d], sum + pay[d]));		
	}
	return ans;
}

int main() {
	cin>>n;
	for(int i = 0;i<n;i++){
		int d, p;
		cin>>d>>p;
		day.push_back(d);
		pay.push_back(p);
	}
	
	cout<<go(0,0)<<"\n";
    return 0;
}