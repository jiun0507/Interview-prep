//baekjoon 6549
//히스토그램에서 가장 큰 직사각형

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long height[100001], lefty[100001], righty[100001];

int main(void)
{
    int n;
    while (true)
    {
        cin >> n;
        if (n == 0)
            break;
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            cin >> height[i];
        }
        height[n] = -1;

        for (int i = 0; i < n + 1; i++)
        {
            if (st.empty())
            {
                lefty[i] = -1;
                st.push(i);
                continue;
            }
            long long h = height[i];
            if (height[st.top()] < h)
            {
                lefty[i] = st.top();
                st.push(i);
            }
            else
            {
                while (!st.empty() && height[st.top()] >= h)
                {
                    righty[st.top()] = i;
                    st.pop();
                }
                if (st.empty())
                    lefty[i] = -1;
                else
                {
                    lefty[i] = st.top();
                }
                st.push(i);
            }
        }
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, (righty[i] - lefty[i] - 1) * height[i]);
        }
        cout << ans << endl;
    }

    return 0;
}