//baekjoon 10826
//피보나치 수 4

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
피보나치 수의 n제한이 10000이므로 string을 이용해서 문제를 푼다. long long으로 표현 못할 때는
string이 유용할 수도 있다. carry라는 bool로 10이상이 나오는지 확인했고 carry값을 그대로 temp에
넣어주어 시작 값을 설정해준게 포인트이다. 

*/

string add(string &a, string &b)
{
    string ans(max(a.size(), b.size()), '0');
    bool carry = false;
    for (int i = 0; i < ans.size(); i++)
    {
        int temp = carry;
        carry = false;
        if (i < a.size())
        {
            temp += a[a.size() - i - 1] - '0';
        }
        if (i < b.size())
        {
            temp += b[b.size() - i - 1] - '0';
        }
        if (temp >= 10)
        {
            carry = true;
            temp %= 10;
        }
        ans[ans.size() - i - 1] = temp + '0';
    }
    if (carry)
    {
        ans.insert(ans.begin(), '1');
    }
    return ans;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    if (n == 0)
    {
        cout << "0\n";
        return 0;
    }
    if (n == 1 || n == 2)
    {
        cout << "1\n";
        return 0;
    }

    string first = "1";
    string second = "1";

    for (int i = 3; i <= n; i++)
    {
        string temp = add(first, second);
        first = second;
        second = temp;
    }
    cout << second << "\n";
    return 0;
}
