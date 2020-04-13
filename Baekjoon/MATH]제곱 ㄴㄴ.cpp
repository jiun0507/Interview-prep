//baekjoon 1557
//제곱 ㄴㄴ

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int MAX = 100000;
long long k;
vector<int> primes;
int c[MAX + 1];

long long calc(int index, long long num, long long m)
{
    if (index >= primes.size())
        return 0;
    long long ans = 0;
    if (m < primes[index] * num)
        return 0;
    ans += m / (num * primes[index]);
    ans += calc(index + 1, num, m);
    ans -= calc(index + 1, num * primes[index], m);
    return ans;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 2; i <= MAX; i++)
    {
        if (c[i])
            continue;
        primes.push_back(i * i);
        for (int j = i + i; j <= MAX; j += i)
            c[j] = true;
    }
    long long left = 0;
    long long right = 2147483647;
    long long ans = right;
    cin >> k;
    while (left <= right)
    {
        long long mid = (right + left) / 2;
        long long cnt = mid - calc(0, 1, mid);
        if (cnt >= k)
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    cout << ans << "\n";
    return 0;
}
