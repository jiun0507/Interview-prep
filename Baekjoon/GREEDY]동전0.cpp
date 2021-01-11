// 11047
// baekjoon 동전 0
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int n, k;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    vector<int> coins;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        coins.push_back(num);
    }
    int ans = 0;
    while (k != 0)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            if (k / coins[i] != 0)
            {
                ans += k / coins[i];
                k %= coins[i];
            }
        }
    }
    cout << ans << endl;
    return 0;
}