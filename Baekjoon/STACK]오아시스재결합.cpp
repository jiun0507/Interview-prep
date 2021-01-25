//baekjoon 3015
//오아시스 재결합

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int height[500001];

int main(void)
{
    int n;
    cin >> n;
    long long cnt = 0;
    stack<pair<int, int>> st;
    for (int i = 0; i < n; i++)
    {
        int next;
        cin >> next;
        pair<int, int> cur = make_pair(next, 1);
        if (st.empty())
        {
            st.push(cur);
            continue;
        }
        while (!st.empty() && st.top().first <= cur.first)
        {
            if (st.top().first == cur.first)
            {
                cur.second += st.top().second;
            }
            cnt += st.top().second;
            st.pop();
        }
        if (!st.empty())
            cnt++;
        st.push(cur);
    }
    cout << cnt << endl;
    return 0;
}