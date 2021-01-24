//baekjoon 13506
//카멜레온 부분순열

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> preprocess(string p)
{
    int len = p.size();
    vector<int> pi(len);
    pi[0] = 0;
    int j = 0;
    for (int i = 1; i < len; i++)
    {
        while (j > 0 && p[i] != p[j])
            j = pi[j - 1];
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
    string s;
    cin >> s;
    int n = s.size();
    string p = s;
    while (true)
    {
        int j = 0;
        vector<int> ans;
        vector<int> pi = preprocess(p);
        if (pi[p.size() - 1] == 0)
        {
            cout << "-1"
                 << "\n";
            break;
        }
        p = p.substr(0, pi[p.size() - 1]);
        int m = p.size();

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
        if (ans.size() >= 3)
        {
            cout << p << "\n";
            break;
        }
    }
    return 0;
}