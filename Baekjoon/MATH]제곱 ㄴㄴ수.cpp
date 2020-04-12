//baekjoon 1016
//제곱 ㄴㄴ수

//ㅇㅔ라스토스테네스의 체를 사용하여 10^12 까지의 큰 수 중 100만 구간에 제곱 ㄴㄴ수를 구한다.
/*
min을 index = 0으로 하고 첫 start를 찾는게 문제의 관건. i*i가 현재 제곱일 경우 0부터 i*i-1
까지가 스타트 가능 범위이다.  min%(i*i)를 i*i에서 빼주면 스타트의 인덱스를 갖게됨
ex) i*i = 9. n = 20
첫 인덱스는 7 (실제 숫자는 18) = i*i(9) - min(20) % (i*i)(9) = 7
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool check[1000001];
long long mn, mx;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> mn >> mx;
    // scanf("%lld %lld",&mn,&mx);
    long long gap = mx - mn;
    for (long long i = 2; i * i <= mx; i++)
    {
        long long start = i * i - mn % (i * i);
        if (start == i * i)
            start = 0;

        for (long long j = start; j <= gap; j += i * i)
        {
            check[j] = true;
        }
    }

    int ans = 0;
    for (int i = 0; i <= gap; i++)
    {
        if (check[i] == 0)
            ans++;
    }
    // printf("%d\n", ans);
    cout << ans << "\n";
    return 0;
}
