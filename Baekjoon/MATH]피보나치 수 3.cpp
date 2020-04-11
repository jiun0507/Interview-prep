//baekjoon 2749
//피보나치 수 3

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long n;
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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
    long long m = 1500000;
    n %= m;
    long long first = 1;
    long long second = 1;
    for (int i = 3; i <= n; i++)
    {
        long long temp = second % 1000000;
        second += first;
        second %= 1000000;
        first = temp;
    }
    cout << second << "\n";
    return 0;
}
