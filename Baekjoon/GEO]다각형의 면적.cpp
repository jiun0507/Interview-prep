//baekjoon 2166
//다각형의 면적

/*
다각형의 면적은 CCW로 구할 수 있다. 벡터의 곱은 곧 두 선분으로 만들어진 사각형의 곲이므로
1/2을 한다면 삼각형이 곱이 된다. 다각형을 벡터의 곲으로 하여 1/2하면 답을 구할 수 있다.

*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

double y[10001];
double x[10001];

double ccw(int n)
{
    double temp = 0.0;
    for (int i = 0; i <= n; i++)
    {
        temp += y[i] * x[i + 1];
        temp -= x[i] * y[i + 1];
    }
    if (temp < 0)
        temp = -temp;
    return temp / 2.0;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lf %lf", &y[i], &x[i]);
        // cout<<y[i]<<" "<<x[i]<<"\n";
    }
    y[n] = y[0];
    x[n] = x[0];
    printf("%.1lf\n", ccw(n));
    return 0;
}
