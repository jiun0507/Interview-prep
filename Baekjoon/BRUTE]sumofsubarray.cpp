//baekjoon 1182

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> s;
int n, goal;
int go(int index, int sum){
	if(index ==n){
		if(sum == goal) return 1;
		return 0;
	}
	int ans = go(index+1, sum + s[index]) + go(index+1, sum);
	return ans;
}

int main() {
    cin >> n >> goal;
    for (int i=0; i<n; i++) {
        int temp;
        cin>>temp;
        s.push_back(temp);
    }
    int ans = go(0, 0);
    if(goal == 0) ans-=1;
    cout<<ans<<"\n";
    return 0;
}