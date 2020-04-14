//baekjoon 2086
//피보나치 수의 합

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const long long k = 1500000000;
const long long mod = 1000000000;
long long a, b;

/*
n번재 피보나치 수까지의 모든 수의 합 은 n+2번째 피보나치 수에 -1을 더한 것이다. 이로써
log n시간안에 합을 구할 수 있다.
*/

typedef vector<vector<long long>> matrix;

matrix operator*(matrix &a, matrix &b)
{
    matrix c(2, vector<long long>(2));
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                c[i][j] += a[i][k] % mod * b[k][j] % mod;
                c[i][j] %= mod;
            }
            c[i][j] %= mod;
        }
    }
    return c;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b;

    a %= k;
    b %= k;
    long long n = a + 1;
    matrix ans = {{1, 0}, {0, 1}};
    matrix amat = {{1, 1}, {1, 0}};

    while (n > 0)
    {
        if (n % 2 == 1)
        {
            ans = ans * amat;
        }
        amat = amat * amat;
        n /= 2;
    }
    n = b + 2;
    long long atotal = ans[0][1];
    ans = {{1, 0}, {0, 1}};
    amat = {{1, 1}, {1, 0}};
    while (n > 0)
    {
        if (n % 2 == 1)
        {
            ans = ans * amat;
        }
        amat = amat * amat;
        n /= 2;
    }

    long long btotal = ans[0][1];

    cout << ((btotal - 1) % mod - (atotal - 1) % mod + mod) % mod << "\n";

    return 0;
}
