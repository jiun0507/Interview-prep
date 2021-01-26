//baekjoon 3015
//오아시스 재결합
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int people[500001];
int main(void)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> people[i];
    }
    stack<pair<int, int>> s;
    long long see = 0;
    for (int i = 0; i < n; i++)
    {
        pair<int, int> cur = {people[i], 1};
        while (!s.empty() && s.top().first <= people[i])
        {
            see += s.top().second;
            if (s.top().first == people[i])
            {
                cur.second += s.top().second;
            }
            s.pop();
        }
        if (!s.empty())
        {
            see++;
        }
        s.push(cur);
    }

    cout << see << "\n";
}