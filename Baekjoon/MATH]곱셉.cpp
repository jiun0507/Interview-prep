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

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> mod;

    cout << go(n, m) << "\n";
    return 0;
}
