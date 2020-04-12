//baekjoon 11444
//피보나치 수 6

/*
매트릭스의 곱으로 표현했을 때, {{fn+1, fn}, {fn-1, fn}} = {{1, 1}, {1, 0}}^n
으로 표현이 가능하다. 따라서 곱섹을 행렬의 곱으로 표현하는 방식으로 총 time complexity를
log n으로 만들어 버린다.
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long n;
const long long m = 1000000007;
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
                c[i][j] += a[i][k] * b[k][j];
            }
            c[i][j] %= m;
        }
    }
    return c;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    if (n == 0)
    {
        cout << "0\n";
        return 0;
    }
    if (n == 1 || n == 2)
    {
        cout << "1\n";
        return 0;
    }
    n -= 1;
    matrix ans = {{1, 0}, {0, 1}};
    matrix a = {{1, 1}, {1, 0}};
    while (n > 0)
    {
        if (n % 2 == 1)
        {
            ans = ans * a;
        }
        a = a * a;
        n /= 2;
    }
    cout << ans[0][0] << "\n";
    return 0;
}
