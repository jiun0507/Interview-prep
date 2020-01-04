//baekjoon 2529
/*두 종류의 부등호 기호 ‘<’와 ‘>’가 k개 나열된 순서열  A가 있다. 우리는 이 부등호 기호 앞뒤에 서로 다른 한 자릿수 숫자를 
넣어서 모든 부등호 관계를 만족시키려고 한다. 예를 들어, 제시된 부등호 순서열 A가 다음과 같다고 하자. 
A =>  < < < > < < > < >
부등호 기호 앞뒤에 넣을 수 있는 숫자는 0부터 9까지의 정수이며 선택된 숫자는 모두 달라야 한다. 아래는 부등호 순서열 A를 만족시키는 한 예이다. 
3 < 4 < 5 < 6 > 1 < 2 < 8 > 7 < 9 > 0
이 상황에서 부등호 기호를 제거한 뒤, 숫자를 모두 붙이면 하나의 수를 만들 수 있는데 이 수를 주어진 
부등호 관계를 만족시키는 정수라고 한다. 그런데 주어진 부등호 관계를 만족하는 정수는 하나 이상 존재한다. 
예를 들어 3456128790 뿐만 아니라 5689023174도 아래와 같이 부등호 관계 A를 만족시킨다. 
5 < 6 < 8 < 9 > 0 < 2 < 3 > 1 < 7 > 4
여러분은 제시된 k개의 부등호 순서를 만족하는 (k+1)자리의 정수 중에서 최댓값과 최솟값을 찾아야 한다. 
앞서 설명한 대로 각 부등호의 앞뒤에 들어가는 숫자는 { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }중에서 선택해야
하며 선택된 숫자는 모두 달라야 한다. 
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
char alligator[9];
int n;
int check[10];
vector<int> big, small;

bool valid(vector<int> &nums){
	
	for(int i =0;i<n;i++){
		int left = nums[i];
		int right = nums[i+1];
		if(alligator[i]== '<' && left > right) return false;
		else if(alligator[i] == '>' && left < right) return false;
	}
	return true;
}

void alli(vector<int> &numbers){
	int length = numbers.size();
	if(length == n+1){
		if(!valid(numbers)) return;
		if(big < numbers){
			big = numbers;
		}
		if(small > numbers){
			small = numbers;
		}
		return;
	}
	for(int i = 0;i<10;i++){
		if(check[i] == 1) continue;
		check[i] = 1;
		numbers.push_back(i);
		alli(numbers);
		numbers.pop_back();
		check[i] = 0;
	}
	
	return;
}

int main() {
	cin>>n;
	for(int i = 0;i<n;i++){
		cin>>alligator[i];
	}
	for(int i = 0;i<=n;i++){
		big.push_back(0);
		small.push_back(9);
	}
	vector<int> numbers;
	alli(numbers);
	for(int i = 0;i<=n;i++){
		cout<<big[i];
	}
	cout<<"\n";
	for(int i = 0;i<=n;i++){
		cout<<small[i];
	}
	cout<<"\n";
}