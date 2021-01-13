// 1780
// baekjoon 종이의 개수

#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int n;
int board[2187][2187];
int cnt[3] = {0};

pair<bool, int> dandq(int size, int y, int x, int number)
{
    if (size == 1)
    {
        if (board[y][x] == number)
        {
            return make_pair(true, 1);
        }
        return make_pair(false, 0);
    }
    int divide = size / 3;
    bool same = true;
    int count = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int ny = y + i * divide;
            int nx = x + j * divide;
            pair<bool, int> result = dandq(divide, ny, nx, number);
            if (!result.first)
            {
                same = false;
            }
            count += result.second;
        }
    }
    if (same)
    {
        return make_pair(true, 1);
    }
    return make_pair(false, count);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    int minus = 0;
    int zero = 0;
    int plus = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }
    for (int i = -1; i <= 1; i++)
    {
        pair<bool, int> result = dandq(n, 0, 0, i);
        if (result.first)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << result.second << endl;
        }
    }

    return 0;
}