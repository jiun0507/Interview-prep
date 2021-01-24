//baekjoon 12104
//순환 수열

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> getPi(string p)
{
    int len = p.size();
    vector<int> pi(len);
    pi[0] = 0;
    int j = 0;
    for (int i = 1; i < len; i++)
    {
        while (j > 0 && p[i] != p[j])
        {
            j = p[j - 1];
        }
        if (p[i] == p[j])
        {
            pi[i] = j + 1;
            j++;
        }
        else
        {
            pi[i] = 0;
        }
    }
    return pi;
}

int main(void)
{
    string s, p;
    cin >> s >> p;
    s.append(s);
    s.pop_back();
    vector<int> pi = getPi(p);
    int n = s.size();
    int m = p.size();
    int j = 0;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        while (j > 0 && s[i] != p[j])
        {
            j = pi[j - 1];
        }
        if (s[i] == p[j])
        {
            if (j == m - 1)
            {
                ans.push_back(i - m + 1);
                j = pi[j];
            }
            else
            {
                j++;
            }
        }
    }
    if (ans.size() == 0)
    {
        cout << "0\n";
        return 0;
    }
    cout << ans.size() << "\n";
    return 0;
}