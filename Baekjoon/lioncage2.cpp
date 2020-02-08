//baekjoon onetwothree 1309
//number of putting lions in 2xn cage without putting them beside each other
//solving it in a harder way
#include <iostream>
#include <algorithm>
using namespace std;

long long d[100001];
long long s[100001];
//if we paint nth house with i color. 
//the least money spent is price[n][i] = color[i] + min(price[n-1][i-1],price[n-1][i+1]);

//d[i] is number of cass when we put lion for sure in ith cage
//s[i] = d[i] + d[i-1] ...d[0]
void cage(int n){
	d[0] = 1;//when  put lion in 0th(none)->no lion at all.
	s[0] = 1;
	d[1] = 2;
	s[1] = 3;
	for(int i = 2;i<=n;i++){
		d[i] = d[i-1] + 2*s[i-2];
		s[i] = s[i-1] + d[i];
		d[i] %= 9901;
		s[i] %= 9901;
	}
	return ;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	cage(n);
	
	
	cout<<s[n]<<"\n";
	
	
	return 0;

}