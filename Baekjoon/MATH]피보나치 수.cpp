//baekjoon 2747
//피보나치 수

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n;
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    if (n == 0)
    {
        cout << "0\n";
        return 0;
    }
    if (n == 1 || n == 2)
    {
        cout << "1\n";
        return 0;
    }
    int first = 1;
    int second = 1;
    for (int i = 3; i <= n; i++)
    {
        int temp = second;
        second += first;
        first = temp;
    }
    cout << second << "\n";
    return 0;
}
