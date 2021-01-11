// 12015
// baekjoon lis 2
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
// upper_bound key보다 큰 값중 첫번째 값의 index
// lower_bound key와 같거나 큰 값중 첫번쨰 값의 index(use on vector or array)

int n;
const int MAX = 1000001;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector<int> numbers;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        numbers.push_back(num);
    }

    vector<int> lis(n + 1, MAX);
    for (int i = 0; i < n; i++)
    {
        auto it = lower_bound(lis.begin(), lis.end(), numbers[i]) - lis.begin();
        lis[it] = numbers[i];
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (lis[i] != MAX)
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}
