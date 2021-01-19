//15486 퇴사 2
//백준

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int days[n];
    int pay[n];
    for (int i = 0; i < n; i++)
    {
        cin >> days[i];
        cin >> pay[i];
    }
    int ret[n + 1];
    ret[n] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        ret[i] = ret[i + 1];
        if (i + days[i] <= n)
        {
            ret[i] = max(ret[i], ret[i + days[i]] + pay[i]);
        }
    }
    cout << ret[0] << endl;
    return 0;
}
