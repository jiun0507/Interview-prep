//baekjoon 10830
//행렬 제곱

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> matrix;

/*
log b & n*n. n = a 매트릭스의 사이즈.
*/

matrix operator*(const matrix &a, const matrix &b)
{
    int n = a.size();
    matrix c(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
            c[i][j] %= 1000;
        }
    }
    return c;
}

matrix matrixX(matrix &a, int b)
{
    int n = a.size();
    if (b == 0)
    {
        matrix c(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            c[i][i] = 1;
        }
        return c;
    }
    if (b == 1)
    {
        return a;
    }
    if (b % 2 == 0)
    {
        matrix temp = matrixX(a, b / 2);
        return temp * temp;
    }
    matrix temp = matrixX(a, b - 1);

    return a * temp;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    long long b;
    cin >> n >> b;
    matrix a(n, vector<int>(n));
    matrix ans(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
        ans[i][i] = 1;
    }

    while (b > 0)
    {
        if (b % 2 == 1)
        {
            ans = ans * a;
        }
        a = a * a;
        b /= 2;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
