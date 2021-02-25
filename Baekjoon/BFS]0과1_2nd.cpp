//baekjoon 8222
//0과 1

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

int n;

int dp[20001];
int adds[20001];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i <= n; i++)
        {
            dp[i] = -1;
        }
        if (n == 1)
        {
            cout << 1 << "\n";
            continue;
        }
        dp[1 % n] = 1; // remainder of the number from before
        adds[1] = 1;   // the number that was added to add to this number
        queue<int> q;
        q.push(1);

        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            int add_one = (cur * 10 + 1) % n;
            int add_zero = (cur * 10) % n;
            if (dp[add_one] == -1)
            {
                dp[add_one] = cur;
                adds[add_one] = 1;
                q.push(add_one);
            }
            if (dp[add_zero] == -1)
            {
                dp[add_zero] = cur;
                adds[add_zero] = 0;
                q.push(add_zero);
            }
        }
        if (dp[0] == -1)
        {
            cout << "BRAK"
                 << "\n";
            continue;
        }

        vector<int> ans;
        int start = 0;

        while (true)
        {
            ans.push_back(adds[start]);
            if (dp[start] == start)
                break;
            start = dp[start];
        }
        reverse(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i];
        }
        cout << "\n";
    }

    return 0;
}