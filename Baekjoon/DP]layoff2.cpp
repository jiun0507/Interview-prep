//baekjoon 15486
//퇴사 2
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n;
int pay[1500001];
int date[1500001];
int d[1500001];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> date[i] >> pay[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (i + date[i] <= n)
        {
            d[i + date[i]] = max(d[i + date[i]], pay[i] + d[i]);
        }

        d[i + 1] = max(d[i + 1], d[i]);
    }
    cout << d[n] << "\n";
    return 0;
}