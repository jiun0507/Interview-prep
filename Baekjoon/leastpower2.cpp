//baekjoon 1699
//제곱수의 합
#include <iostream>

using namespace std;

int least[100001];
//forloop solution
void power2(int n){
	for(int i = 1;i<=n;i++){
		least[i] = i;
		for(int j = 1;j*j<=i;j++){
			if(least[i]>least[i-j*j]+1){
				least[i] = least[i-j*j]+1;
			}
		}
	}
	return;
}

//while loop solution
int power22(int n){
	if(n==0){
		return 0;
	}
	if(least[n] != 0){
		return least[n];
	}
	least[n] = n;
	for(int j = 1;j*j<=n;j++){
		int temp = power22(n-j*j)+1;
		if(least[n]>temp){
			least[n] = temp;
		}
	}
	return least[n];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	
	power2(n);
	cout<<least[n]<<"\n";
    return 0;

}