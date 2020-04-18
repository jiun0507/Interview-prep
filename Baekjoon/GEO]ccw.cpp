//baekjoon 11758
//CCW

/*
세개의 포인트가 있을 때 시계방향인지 반시계방향인지 아니면 일직선인지를 벡터의 곱으로 알 수 있는 
방법.
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int ccw(int p1y, int p1x, int p2y, int p2x, int p3y, int p3x)
{
    int temp = p1y * p2x + p2y * p3x + p3y * p1x;
    temp -= p1x * p2y + p2x * p3y + p3x * p1y;
    if (temp > 0)
        return 1;
    else if (temp < 0)
        return -1;
    return 0;
}

int main(void)
{
    int p1y, p1x, p2y, p2x, p3y, p3x;
    cin >> p1y >> p1x;
    cin >> p2y >> p2x;
    cin >> p3y >> p3x;
    cout << ccw(p1y, p1x, p2y, p2x, p3y, p3x) << "\n";
}
