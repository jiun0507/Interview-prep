//baekjoon 9935
//문자열 폭발

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int number[1000001];

int main(void)
{
    string s, bomb;
    cin >> s;
    cin >> bomb;
    int len = bomb.size();
    int cnt = 0;
    stack<int> st;
    for (int i = 0; i < s.size(); i++)
    {
        st.push(i);
        if (s[i] == bomb[cnt])
        {
            cnt++;
            if (cnt == len)
            {
                for (int j = 0; j < cnt; j++)
                {
                    st.pop();
                }
                if (st.empty())
                    cnt = 0;
                else
                {
                    int last = st.top();
                    cnt = number[last];
                }
            }
            else
            {
                number[i] = cnt;
            }
        }
        else
        {
            cnt = 0;
            if (s[i] == bomb[0])
                cnt = 1;
            number[i] = cnt;
        }
    }
    if (st.empty())
    {
        cout << "FRULA" << endl;
    }
    else
    {
        string ans = "";
        while (!st.empty())
        {
            ans += s[st.top()];
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }

    return 0;
}