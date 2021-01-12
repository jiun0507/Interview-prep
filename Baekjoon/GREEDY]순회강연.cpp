// 2109
// baekjoon 순회공연
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

pair<int, int> lectures[10001];

bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.second > b.second)
    {
        return true;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    int latest = 0;
    for (int i = 0; i < n; i++)
    {
        int pay, due;
        cin >> pay >> due;
        if (due > latest)
            latest = due;
        lectures[i].first = pay;
        lectures[i].second = due;
    }

    sort(lectures, lectures + n, compare);

    priority_queue<int> pq;
    int i, j;
    long long sum = 0;

    j = 0;
    for (i = latest; i >= 1; i--)
    {
        while (j < n && lectures[j].second >= i)
        {
            pq.push(lectures[j].first);
            j++;
        }
        if (!pq.empty())
        {
            sum += pq.top();
            pq.pop();
        }
    }
    cout << sum << endl;
    return 0;
}
