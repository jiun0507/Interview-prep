//baekjoon 1339


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int alpha[256];

int calc(vector<string> &words, vector<char> &alphabets, vector<int> &numbers){
	int m = alphabets.size();
	for(int i = 0;i<m;i++){
		alpha[alphabets[i]] = numbers[i];
	}
	int result = 0;
	for(string word: words){
		int now = 0;
		for(char x:word){
			now = now * 10 + alpha[x];
		}
		result += now;
	}
	return result;
}

int main() {
	vector<int> numbers;
	vector<char> alphabets;
	int n;
	cin>>n;
		
	vector<string> words(n);
	for(int i = 0;i<n;i++){
		cin>>words[i];
		for(char x: words[i]){
			alphabets.push_back(x);
		}
	}
	sort(alphabets.begin(),alphabets.end());
	alphabets.erase(unique(alphabets.begin(),alphabets.end()), alphabets.end());
	int k = alphabets.size();
	for(int i = 0;i<k;i++){
		numbers.push_back(9-i);
	}
	sort(numbers.begin(),numbers.end());
	int ans =0;
	do{
		int temp = calc(words, alphabets, numbers);
		if(ans<temp){
			ans = temp;
		}
	}while(next_permutation(numbers.begin(),numbers.end()));
	cout<<ans<<"\n";
	return 0;
}