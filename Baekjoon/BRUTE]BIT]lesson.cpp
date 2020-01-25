//baekjoon 1062

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> s;
int n,k;
int basic = 0;
int count(int mask){
	int cnt =0;
	for(int i = 0;i<s.size();i++){
		int word = s[i];
		if((word &(~mask)) == 0) cnt +=1;
	}
	return cnt;
}
int go(int left, int index, int learned){
	if(left == 0){
		return count(learned);
	}
	if(index == 26) return 0;
	int ans = 0;
	if((learned & (1<<index)) == 0){
		ans = go(left - 1, index + 1, learned | (1<<index));	
	}
	ans = max(ans, go(left, index + 1, learned));
	return ans;
}

int main() {
    cin >>n>>k;
    cin.ignore();
    for (int i=0; i<n; i++) {
        string line;
        getline(cin, line);
        int temp = 0;
        for(char c:line){
        	temp |= 1<<(c - 'a');
        }
        s.push_back(temp);
    }
	basic |= 1 + (1<<2) + (1<<13) + (1<<19) + (1<<8);

    int minimum = go(k-5, 0, basic);
	cout<<minimum<<"\n";
    return 0;
}