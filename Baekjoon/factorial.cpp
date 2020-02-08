#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	int five = 0;
	int two = 0;
	for(int i = 5; i<=n; i *= 5){
		five += n/i;
	}
	for(int i = 2;i<=n;i *=2){
		two += n/i;
	}
	cout<<min(five, two);
	
	
	return 0;
}