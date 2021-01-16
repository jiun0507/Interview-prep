// 사분면
// baekjoon 1891

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long d, x, y;
string n;
char directions[4][5] = {{'0', '2', '1', '4', '3'}, {'0', '2', '1', '4', '3'}, {'0', '4', '3', '2', '1'}, {'0', '4', '3', '2', '1'}};
int flips[4][5] = {{0, 1, 0, 0, 1}, {0, 0, 1, 1, 0}, {0, 1, 1, 0, 0}, {0, 0, 0, 1, 1}};

// direction
// right = 0 left = 1 up = 2 down = 3
bool move(int direction, int index, string &number)
{
    if (index >= number.length())
        return false;
    int num = number.at(index) - '0';
    if (flips[direction][num])
    {
        if (!move(direction, index + 1, number))
        {
            return false;
        }
    }
    number[index] = directions[direction][num];
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> d >> n >> x >> y;
    reverse(n.begin(), n.end());
    int direction = 0;
    if (x < 0)
    {
        direction = 1;
        x *= -1;
    }
    int index = 0;
    while (x != 0)
    {
        long long shift = 1 & x;
        x = x >> 1;
        if (shift && !move(direction, index, n))
        {
            cout << "-1"
                 << "\n";
            return 0;
        }
        index++;
    }
    direction = 2;
    if (y < 0)
    {
        direction = 3;
        y *= -1;
    }
    index = 0;
    while (y != 0)
    {
        long long shift = 1 & y;
        y = y >> 1;
        if (shift && !move(direction, index, n))
        {
            cout << "-1" << endl;
            return 0;
        }
        index++;
    }

    reverse(n.begin(), n.end());
    cout << n << "\n";
}
