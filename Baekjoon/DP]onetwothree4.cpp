//baekjoon 15989
//1, 2, 3 더하기 4
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> num;
int d[10001];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        int buf;
        cin >> buf;
        num.push_back(buf);
        if (buf > mx)
            mx = buf;
    }
    d[0] = 1;
    for (int j = 1; j < 4; j++)
    {
        for (int i = 1; i <= mx; i++)
        {
            if (i - j >= 0)
            {
                d[i] += d[i - j];
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << d[num[i]] << "\n";
    }

    return 0;
}