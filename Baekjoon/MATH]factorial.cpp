//baekjoon 1676
//number of zeroes in factorial
#include <iostream>
using namespace std;
int main() {
    int ans = 0;
    int n;
    cin >> n;
    for (int i=5; i<=n; i*=5) {
        ans += n/i;
    }
    cout << ans << '\n';
    return 0;
}