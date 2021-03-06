//baekjoon 11066
//파일 합치기
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> num;
int d[501][501];
int d2[501][501];

int go(int i, int j)
{
    if (i == j)
    {
        return 0;
    }
    if (d2[i][j] != -1)
        return d2[i][j];
    int sum = num[j];
    if (i - 1 >= 0)
        sum -= num[i - 1];
    // cout<<sum<<"\n";
    int &ans = d2[i][j];
    for (int k = i; k < j; k++)
    {
        int temp = go(i, k) + go(k + 1, j) + sum;
        if (ans == -1 || ans > temp)
            ans = temp;
    }
    return ans;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        memset(d, -1, sizeof(d));
        num.clear();
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int buf;
            cin >> buf;
            num.push_back(buf);
            d[i][i] = buf;
            d2[i][i] = buf;
            if (i > 0)
            {
                num[i] += num[i - 1];
            }
        }
        cout << go(0, n - 1) << "\n";
        for (int j = 1; j < n; j++)
        {
            for (int i = 1; i < n; i++)
            {
                if (i - j < 0)
                    continue;
                for (int k = i - j; k < i; k++)
                {
                    int cur = 0;
                    if (i != k + 1)
                        cur += d[i][k + 1];
                    if (k != i - j)
                        cur += d[k][i - j];
                    cur += num[i];
                    if (i - j - 1 >= 0)
                        cur -= num[i - j - 1];
                    // cout<<i-j<<" "<<k<<" "<<k+1<<" "<<i<<" "<<cur<<" \n";
                    if (d[i][i - j] == -1 || d[i][i - j] > cur)
                    {
                        d[i][i - j] = cur;
                    }
                }
            }
        }
        cout << d[n - 1][0] << "\n";
    }

    return 0;
}