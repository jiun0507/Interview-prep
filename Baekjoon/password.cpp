//baekjoon 1759

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
char input[15];
char vowels[] = {'a', 'e', 'i', 'o', 'u'};

bool viable(string passcode){
	int l = passcode.length();
	int vowel, consonant;
	vowel = consonant = 0;
	for(int i = 0;i<l;i++){
		bool isC = true;
		for(int j =0;j<5; j++){
			if(vowels[j] == passcode.at(i)){
				vowel +=1;
				isC = false;
				break;
			}
		}
		if(isC) consonant +=1;
	}
	if(vowel>=1 && consonant >= 2){
		return true;
	}
	else{
		return false;
	}
}

void code(int index, int l, string passcode, int n){
	int length = passcode.length();
	if(l == length){
		if(viable(passcode)){
			cout<<passcode<<"\n";
		}
		return;
	}
	if(index >= n){
		return;
	}
	
	code(index + 1, l, passcode + input[index], n);
	code(index + 1, l, passcode, n);
	return;
}

int main() {
	int l,n;
	cin>>l>>n;
	
	for(int i = 0;i<n;i++){
		cin>>input[i];
	}
	sort(input, input + n);
	string passcode = "";
	code(0, l, passcode, n);
	return 0;
}