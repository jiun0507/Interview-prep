//baekjoon 1786
//찾기

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string t, p;

vector<int> getPi(string p)
{
    int m = p.size();
    vector<int> pi(m, 0);
    int j = 0;
    for (int i = 1; i < m; i++)
    {
        while (j > 0 && p[i] != p[j])
        {
            j = pi[j - 1];
        }
        if (p[i] == p[j])
        {
            pi[i] = ++j;
        }
    }
    return pi;
}

int main()
{
    string t, p;
    getline(cin, t);
    getline(cin, p);
    vector<int> pi = getPi(p);
    int j = 0;
    int m = p.size();
    int n = t.size();
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        while (j > 0 && t[i] != p[j])
        {
            j = pi[j - 1];
        }
        if (t[i] == p[j])
        {
            if (j == m - 1)
            {
                ans.push_back(i - m + 2);
                j = pi[j];
            }
            else
            {
                j++;
            }
        }
    }
    cout << ans.size() << endl;
    for (auto cur : ans)
    {
        cout << cur << " ";
    }
    cout << endl;
    return 0;
}
