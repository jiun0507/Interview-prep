//baekjoon 2193
//이친수 문제 포인트: long long을 써서 fibonacci처럼 빨리 커지는 수를 모두 표현해줌.
#include <iostream>
using namespace std;


long long d[92][2]= {0};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	for (int i=0; i<2; i++) d[1][i] = i;
	for (int i=2; i<=n; i++) {
		for (int j=0; j<2; j++) {
			d[i][j] = 0;
			d[i][j] += d[i-1][0];
			if (j == 0) d[i][j] += d[i-1][1];
		}
	}
	long long ans = 0;
	for (int i=0; i<2; i++){
		ans += d[n][i];
	} 
	
	cout<<ans;
	return 0;

}