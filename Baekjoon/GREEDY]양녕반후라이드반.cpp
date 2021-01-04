//baekjoon 16917
//양념 반 후라이드 반
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int a, b, c, x, y;

int main()
{
    cin >> a >> b >> c >> x >> y;
    int price = 0;
    int halves = a + b >= c * 2 ? min(x, y) * 2 : 0;
    if (halves > 0)
    {
        price = c * halves;
        x -= halves / 2;
        y -= halves / 2;
        if (x > 0 && 2 * c < a)
        {
            cout << price + 2 * x * c << endl;
            return 0;
        }
        else if (y > 0 && 2 * c < b)
        {
            cout << price + 2 * y * c << endl;
            return 0;
        }
    }
    price += x * a + y * b;
    cout << price << endl;
    return 0;
}
