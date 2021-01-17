// baekjoon 9663
// N-QUEEN

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n;
int ans = 0;
int dx[2] = {1, -1};
int column[15] = {0};
int diagonal[15][15] = {0};

void queen(int row, int col, int val)
{
    column[col] += val;
    for (int j = 0; j < 2; j++)
    {
        for (int i = 0; i < n; i++)
        {
            int newx = col + i * dx[j];
            if (newx < 0 || newx >= n || row + i >= n)
            {
                break;
            }
            else
            {
                diagonal[row + i][newx] += val;
            }
        }
    }
    return;
}

void calc(int row)
{
    if (row == n)
    {
        ans++;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (diagonal[row][i] || column[i])
        {
            continue;
        }
        queen(row, i, 1);
        calc(row + 1);
        queen(row, i, -1);
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    calc(0);
    cout << ans << endl;
    return 0;
}
