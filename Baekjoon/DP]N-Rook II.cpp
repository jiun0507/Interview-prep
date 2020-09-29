//baekjoon 1767
//N-Rook II
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n, m, k;
long long d[101][101][101];
long long mod = 100001;

/*4가지 경우가 있다.
//d[n][m][k]일때 그 수는 크리 n x m의 상자에 rook을 k개 넣을 수 있는
//경우의 수이다. 룩은 안 넣거나, 1개 넣거나, 2개를 넣을 수 있다. 안 넣는 다면
//d[n-1][m][k-1]이다. 1개를 같은 columnㅇ에 공격하는 룩이 없는 곳에 넣을 때는 새로운 
줄을 끼워 넣는 다고 생각하고 row column을 줄인다. go(y - 1, x - 2, rook - 2). 
1개를 위의 것과 공격하는 column에 넣을 때는 위의 룩의 row에 아무 룩이 없어야 하기 때문에 
go(y - 2, x - 1, rook - 2)이다. 경우의 수는 (y - 1) * x이 된다. 
 2개를 넣을 때는 서로 이미 공격하기 떄문에 위에서 공격당할 수가 없다. 때문에 2 column을 
 넣는다고 생각하면 된다. go(y - 1, x - 2, rook - 2)이 된다. xC2는 x * (x - 1)/2이기
 때문에 이걸 곱해주면 된다.
*/

long long go(int y, int x, int rook)
{
    if (rook == 0)
    {
        return 1;
    }
    if (y <= 0 || x <= 0 || rook < 0)
        return 0;
    long long &ans = d[y][x][rook];
    if (ans != -1)
        return ans;

    ans = go(y - 1, x, rook) + go(y - 1, x - 1, rook - 1) * x + go(y - 1, x - 2, rook - 2) * x * (x - 1) / 2 + go(y - 2, x - 1, rook - 2) * (y - 1) * x;
    ans %= 1000001;
    return ans;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;

    memset(d, -1, sizeof(d));

    cout << go(n, m, k) << "\n";
    return 0;
}
