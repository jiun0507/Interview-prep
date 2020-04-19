//baekjoon 17387
//선분의 교차 2

/*
3개의 점이 한 선위에 있는 경우도 포함시켰다. 3개의 점이 한 선위에 있는 것은 교차점이 생긴다. 하지만 4개의 점이 한 선위에 있다면
두 선이 겹치는 것인지 아니면 그저 한 선위에 있는 것인지 확인해주는 과정이 필요하다.

*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

using Point = pair<long long, long long>;
using Line = pair<Point, Point>;

int ccw(Point one, Point two, Point three)
{
    long long ans = one.first * two.second + two.first * three.second + three.first * one.second;
    ans -= (one.second * two.first + two.second * three.first + three.second * one.first);
    if (ans > 0)
        return 1;
    if (ans < 0)
        return -1;
    return 0;
}

bool cross(Line l1, Line l2)
{
    int l1l2 = ccw(l1.first, l1.second, l2.first) * ccw(l1.first, l1.second, l2.second);
    int l2l1 = ccw(l2.first, l2.second, l1.first) * ccw(l2.first, l2.second, l1.second);
    if (l1l2 == 0 && l2l1 == 0)
    {
        if (l1.first > l1.second)
            swap(l1.first, l1.second);
        if (l2.first > l2.second)
            swap(l2.first, l2.second);
        return l2.first <= l1.second && l1.first <= l2.second;
    }
    return l1l2 <= 0 && l2l1 <= 0;
}

int main(void)
{
    long long y1, x1, y2, x2, y3, x3, y4, x4;
    cin >> y1 >> x1 >> y2 >> x2 >> y3 >> x3 >> y4 >> x4;

    Line line1 = make_pair(make_pair(y1, x1), make_pair(y2, x2));
    Line line2 = make_pair(make_pair(y3, x3), make_pair(y4, x4));
    cout << cross(line1, line2) << "\n";
    return 0;
}
