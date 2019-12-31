//Baekjoon 1373

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	string str;
	getline(cin, str);
	int length = str.length();
	
	stack<int> s;
	for(int i = length;i>0;i-=3){
		int sum = 0;
		if(str[i-1] == '1'){//all if statements. Not else if or else.
			sum +=1;
		}
		
		if((i-2)>=0 &&str[i-2] == '1'){
			sum +=2;
		}
		
		if((i-3)>=0 && str[i-3] == '1'){
			sum +=4;
		}
		s.push(sum);
	}
	while(!s.empty()){
		cout<<s.top();
		s.pop();
	}
	return 0;
}