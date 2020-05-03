//baekjoon 2751
//수정렬
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int a[1000001];
int b[1000001];
void merge(int start, int end)
{
    int middle = (start + end) / 2;
    int i = start;
    int j = middle + 1;
    int k = start;
    while (i <= middle && j <= end)
    {
        if (a[i] > a[j])
        {
            b[k++] = a[j++];
        }
        else
        {
            b[k++] = a[i++];
        }
    }
    while (i <= middle)
    {
        b[k++] = a[i++];
    }
    while (j <= end)
    {
        b[k++] = a[j++];
    }
    for (int i = start; i <= end; i++)
    {
        a[i] = b[i];
    }
    return;
}

void solve(int start, int end)
{
    if (start == end)
        return;
    int middle = (start + end) / 2;
    solve(start, middle);
    solve(middle + 1, end);
    merge(start, end);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    solve(0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}