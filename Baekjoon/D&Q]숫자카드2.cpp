// 10816
// baekjoon 숫자카드
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int n, m;
vector<int> cards;

bool find(int number)
{
    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        int middle = (start + end) / 2;
        if (cards[middle] > number)
        {
            end = middle - 1;
        }
        else if (cards[middle] == number)
            return true;
        else
        {

            start = middle + 1;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int number;
        cin >> number;
        cards.push_back(number);
    }
    sort(cards.begin(), cards.end());
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int number;
        cin >> number;
        int count = upper_bound(cards.begin(), cards.end(), number) - lower_bound(cards.begin(), cards.end(), number);
        cout << count << " ";
    }
    return 0;
}
