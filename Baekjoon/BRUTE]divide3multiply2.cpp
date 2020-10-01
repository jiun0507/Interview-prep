//baekjoon 16936
//나3곱2
#include <iostream>
#include <bits/stdc++.h>
// #include <algorithm>
using namespace std;

long long b[100];
int n;

bool comp(tuple<long long, long long, long long> &u, tuple<long long, long long, long long> &v)
{
    long long ufirst, vfirst, usecond, vsecond, indexu, indexv;
    tie(ufirst, usecond, indexu) = u;
    tie(vfirst, vsecond, indexv) = v;

    if (ufirst > vfirst)
    {
        return true;
    }
    else
    {
        if (usecond < vsecond)
        {
            return true;
        }
    }
    return false;
}

int main(void)
{

    cin >> n;
    vector<tuple<long long, long long, long long>> store;
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        long long buf = b[i];
        long long twos = 0;
        long long threes = 0;
        while (b[i] % 2 == 0 && b[i] != 0)
        {
            twos++;
            b[i] /= 2;
        }
        while (b[i] % 3 == 0 && b[i] != 0)
        {
            threes++;
            b[i] /= 3;
        }
        store.push_back(make_tuple(threes, twos, buf));
        // cout<<twos<<" "<<threes<<"\n";
    }
    sort(store.begin(), store.end(), comp);
    for (int i = 0; i < store.size(); i++)
    {

        long long threes, twos, ans;
        tie(threes, twos, ans) = store[i];
        // cout<<threes<<" "<<twos<<"\n";
        cout << ans << " ";
    }
}
