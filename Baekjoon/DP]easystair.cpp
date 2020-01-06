//baekjoon 10844
//number of possible number that move in stairs with n length.
//DP in foor loop
#include <iostream>
using namespace std;

int mod = 1000000000;
int d[101][10]= {0};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	for (int i=1; i<=9; i++) d[1][i] = 1;
	for (int i=2; i<=n; i++) {
		for (int j=0; j<=9; j++) {
			d[i][j] = 0;
			if (j-1 >= 0) d[i][j] += d[i-1][j-1];
			if (j+1 <= 9) d[i][j] += d[i-1][j+1];
			d[i][j] %= mod;
		}
	}
	long long ans = 0;
	for (int i=0; i<=9; i++) ans += d[n][i];
	ans %= mod;
	cout<<ans;
	return 0;

}