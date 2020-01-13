//baekjoon 14002
//DP using for loop(bottom-up)
//backtracking added to lis question
#include <iostream>

using namespace std;

int length[1001];
int back[1001];
int arr[1001];

void lis(int n){
	for(int i = 1;i<=n;i++){
		int max = 0;
		for(int j = 0;j<i;j++){
			if(arr[i]>arr[j]&&max<length[j]){
				max = length[j];
				back[i] = j;
			}
		}
		length[i] += max;
	}
	return;
}

void go(int n){
	if(n == -1){
		return;
	}
	go(back[n]);
	cout<<arr[n]<<" ";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	
	for(int i = 0;i<n;i++){
		back[i] = -1;
		length[i] = 1;
		cin>>arr[i];
	}
	lis(n);
	int ans = length[0];
    int p = 0;
    for (int i=0; i<n; i++) {
        if (ans < length[i]) {
            ans = length[i];
            p = i;
        }
    }
    cout << ans << '\n';
    go(p);
    cout << '\n';
    return 0;

}