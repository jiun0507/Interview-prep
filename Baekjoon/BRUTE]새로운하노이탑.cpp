
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int number[3];
string towers[3];
int check[1111][1111];
int a, b, c;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    a = b = c = 0;
    for (int i = 0; i < 3; i++)
    {
        cin >> number[i];
        if (number[i])
            cin >> towers[i];
        for (char c : towers[i])
        {
            if (c == 'A')
                a++;
            else if (c == 'B')
                b++;
            else if (c == 'C')
                c++;
        }
    }
    map<array<string, 3>, int> p;
    queue<array<string, 3>> q;
    array<string, 3> first = {towers[0], towers[1], towers[2]};
    q.push(first);
    p[first] = 1;
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                array<string, 3> new_array = cur;
                if (i == j || cur[i] == "")
                    continue;
                new_array[j] += cur[i].back();
                new_array[i] = cur[i].substr(0, cur[i].size() - 1);
                if (p.find(new_array) == p.end())
                {
                    p[new_array] = p[cur] + 1;
                    q.push(new_array);
                }
            }
        }
    }
    string ans_a, ans_b, ans_c;
    ans_a = ans_b = ans_c = "";
    for (int i = 0; i < a; i++)
        ans_a += "A";
    for (int i = 0; i < b; i++)
        ans_b += "B";
    for (int i = 0; i < c; i++)
        ans_c += "C";
    array<string, 3> ans = {ans_a, ans_b, ans_c};
    cout << ans_a << ans_b << ans_c << endl;
    cout << p[ans] << endl;

    return 0;
}
