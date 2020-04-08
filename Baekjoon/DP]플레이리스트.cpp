//baekjoon 12872
//플레이리스트

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n, p, m;
long long d[101][101];
long long mod = 1000000007;

// d[position][x][y]
//position은 현재 몇번째 노래를 고르는 것인지(p번째까지 가면 모두 고른것). x는 이미 선택된 노래의 수. y는 선택되지 않은 노래(n-x로 표현 가능)이다.
//y는 x와 n으로 표현 가능하기 때문에 dynamic programming의 array에 들어가지 않는다.
//d[position+1][x+1][y-1] * y -> 다음 노래를 새로운 노래로 한다면 남은 노래중 아무 노래나 선택 할 수 있기 때문에
//다음 d[position+1][x+1][y-1]에 y를 곱한 수 모두이다. d[position+1][x][y] * (x-m)-> A ......(m개) A(이번에 고른 노래) 의 모양일 경우
//중간의 m개는 서로 같은 수가 없다. 그렇다면 불가능해진다.(문제를 읽어보면 같은 노래가 나오려면 중간에 최소 m개가 있어야된다.) 그렇기 때문에 x중에 한
//노래를 고른다면 x-m가지의 경우의 수가 있다. 따라서 d[position+1][x][y](x와 y가 같은 수인걸 봤을 때 새로운 노래를 고르지 않음)은 x-m로 곱해
//주어야 한다.

//이 문제는 모든 경우를 다 찾지 않는다. 비트마스크를 이용해 플레이리스트에 있는 노래 없는 노래를 표현할 수도 있겠지만 그렇게 한다면 2^100의 시간 복잡도
//가 걸리므로, 불가능하다. x와 y로 표현을 한다는 것은 경우의 수를 엄청나게 축소 할 수 있다. 다만 d[position+1][x+1][y-1] * y 그리고
//d[position+1][x][y] * (x-m) 같은 적절한 점화식을 찾았기 때문에 축소 시킬 수 있엇다.

long long go(int position, int x)
{
    int y = n - x;
    if (position == p)
    {
        if (y != 0)
            return 0;
        return 1;
    }
    long long &ans = d[position][x];
    if (ans != -1)
        return ans;
    ans = 0;
    if (y > 0)
    {
        ans += go(position + 1, x + 1) * y;
    }

    if (x > m)
    {
        ans += go(position + 1, x) * (x - m);
    }
    ans %= mod;
    return ans;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> p;

    memset(d, -1, sizeof(d));

    long long ans = go(0, 0);
    cout << ans << "\n";
    return 0;
}
