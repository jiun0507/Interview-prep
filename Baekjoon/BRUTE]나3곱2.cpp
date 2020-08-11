//baekjoon 16936
//나3곱2
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

tuple<long long, long long, long long> find(long long x)
{
    long long num = x;
    long long three = 0;
    long long two = 0;
    while (x % 3 == 0)
    {
        three += 1;
        x /= 3;
    }
    while (x % 2 == 0)
    {
        two += 1;
        x /= 2;
    }
    return make_tuple(three, two, num);
}

bool sortCustom(const tuple<long long, long long, long long> &a,
                const tuple<long long, long long, long long> &b)
{
    long long afirst, asecond, athird, bfirst, bsecond, bthird;
    tie(afirst, asecond, athird) = a;
    tie(bfirst, bsecond, bthird) = b;
    return (afirst > bfirst || asecond < bsecond);
}

int main()
{
    int n;
    cin >> n;
    vector<tuple<long long, long long, long long>> unsorted;
    for (int i = 0; i < n; i++)
    {
        long long num;
        cin >> num;
        unsorted.push_back(find(num));
    }
    sort(unsorted.begin(), unsorted.end(), sortCustom);

    for (int i = 0; i < n; i++)
        cout << get<2>(unsorted[i]) << " ";
    return 0;
}
