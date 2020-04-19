//baekjoon 17386
//선분의 교차

/*
세 점이 한 직선상에 있는 경우가 없다고 가정했을 때 두 개의 선을 두고 보았을 때 ccw를 통해서 교차하는지 알아볼 수 있다. 
교차하는 경우 ccw(첫째 줄의 두 점(2개), 다른 줄의 첫번째 점) * ccw(첫재 줄(2개), 다른 줄의 두번째 점)은 음수 일 수 밖에 없다.

*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Point
{
    long long y, x;
    Point(long long one, long long second) : y(one), x(second)
    {
    }
};
struct Line
{
    Line(Point one, Point two) : first(one), second(two)
    {
    }
    Point first;
    Point second;
};

int ccw(Point one, Point two, Point three)
{
    long long ans = one.y * two.x + two.y * three.x + three.y * one.x;
    ans -= (one.x * two.y + two.x * three.y + three.x * one.y);
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
    return l1l2 < 0 && l2l1 < 0;
}

int main(void)
{
    long long y1, x1, y2, x2, y3, x3, y4, x4;
    cin >> y1 >> x1 >> y2 >> x2 >> y3 >> x3 >> y4 >> x4;

    Line line1 = Line(Point(y1, x1), Point(y2, x2));
    Line line2 = Line(Point(y3, x3), Point(y4, x4));
    // cout<<line1.first.y<<" "<<line1.first.x<<"\n";
    cout << cross(line1, line2) << "\n";
    return 0;
}
