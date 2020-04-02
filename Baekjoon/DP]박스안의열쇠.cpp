//baekjoon 1413
//박스 안의 열쇠
#include <iostream>
#include <cstdio>
using namespace std;
long long gcd(long long x, long long y) {
    if (y == 0) return x;
    else return gcd(y, x%y);
}
long long d[21][21];
int main() {
    int n, m;
    cin >> n >> m;
    d[1][1] = 1;
    for (int i=2; i<=n; i++) {
        for (int j=1; j<=i; j++) {
            d[i][j] = d[i-1][j-1] + (i-1) * d[i-1][j];
        }
    }
    long long bunja = 0;
    for (int i=1; i<=m; i++) {
        bunja += d[n][i];
    }
    long long bunmo = 1;
    for (int i=1; i<=n; i++) {
        bunmo *= i;
    }
    long long g = gcd(bunja, bunmo);
    bunja /= g;
    bunmo /= g;
    printf("%lld/%lld\n",bunja,bunmo);
    return 0;
}