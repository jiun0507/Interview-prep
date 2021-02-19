// 3948 홍준이의 친위대
// baekjoon

// Tall[n] = 1번>2번 순으로 진행될 때 n명을 줄 세우는 방법의 수.
// k번째가 가장 큰 사람일 때, k번째 왼족은 tall[k-1], 오른쪽은 short[n-k]의 가지수로 각각 표현될 수 있다.
// 둘을 곱하고 왼쪽에 k-1개의 숫자를 n-1개에서 뽑아내는 가지수인 n-1Ck-1을 곱해준다.
// tall[n] = sum of k from 1 to n, (2개씩 커지게), tall[k-1]xshort[n-k]xn-1Ck-1이된다.
// short[n]은 tall[n]와 같기 때문에 d[21]하나로 처리 할 수도 있다. n이 한명 일 때를 제외하고 tall[n]*2
// 은 답을 리턴한다.
// nCr = n-1Cr-1 + n-1Cr =>미리 20까지의 ncr을 구해둔 뒤 계산한다.

#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

long long short_line[21];
long long tall[21];

int t, n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;

    long long Combination[51][51] = {};
    Combination[1][0] = 1;
    Combination[1][1] = 1;
    for (int i = 2; i <= 20; i++)
    {
        Combination[i][0] = 1;
        for (int j = 1; j <= 20; j++)
        {
            Combination[i][j] = Combination[i - 1][j - 1] + Combination[i - 1][j];
        }
    }

    short_line[0] = tall[0] = 1LL;
    short_line[1] = tall[1] = 1LL;
    short_line[2] = tall[2] = 1LL;

    for (int i = 3; i <= 20; i++)
    {
        for (int j = 1; j <= i; j += 2)
        {
            tall[i] += tall[j - 1] * short_line[i - j] * Combination[i - 1][j - 1];
        }
        short_line[i] = tall[i];
    }
    while (t--)
    {
        cin >> n;
        if (n == 1)
            cout << "1" << endl;
        else
        {
            cout << tall[n] * 2 << endl;
        }
    }
    return 0;
}
