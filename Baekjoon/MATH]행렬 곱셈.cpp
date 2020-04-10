//baekjoon 2740
//행렬 곱셈

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int a[101][101];
int b[101][101];
int c[101][101];
int n, m;
int n2, m2;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            // cout<<a[i][j]<<" ";
        }
        // cout<<"\n";
    }
    cin >> n2 >> m2;
    for (int i = 0; i < n2; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            cin >> b[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            for (int k = 0; k < m; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            cout << c[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
