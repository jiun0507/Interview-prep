//baekjoon 1629
//곱셉

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long n, m;
long long mod;

//3^27 = 3^(16 + 8 + 2 + 1)
//27의 비트마스크를 작은 자리부터 하나씩 확인하면서 갱신되는 a의 값을 ans에다가 곱해준다.

long long go(long long a, long long b)
{
    long long ans = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            ans *= a;
            ans %= mod;
        }
        a = a * a;
        a %= mod;
        b /= 2;
    }
    return ans;
}

/*
분할정복
b를 계속 2로 나누어 주면서 분할해서 결국 log b 만큼의 계산만하게 된다.
*/

long long go2(long long a, long long b)
{
    if (b == 0)
    {
        return 1LL;
    }
    if (b == 1)
    {
        return a % mod;
    }
    if (b % 2 == 0)
    {
        long long temp = go2(a, b / 2) % mod;
        return (temp * temp) % mod;
    }
    else
    {
        return (a * go2(a, b - 1)) % mod;
    }

    int main(void)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cin >> n >> m >> mod;

        cout << go(n, m) << "\n";
        return 0;
    }
