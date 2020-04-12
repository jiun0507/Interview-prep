//baekjoon 17436
//소수의 배수

//주어진 소수 중 적어도 하나로 나누어 떨어지는 수의 개수. 합집합.
//나누어 떨어지는 소수가 홀 수 이면 그 소수들의 곱으로 나누어 떨어지는 수들을 더하고 짝수면은
//그 수만큼 빼준다.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long n, m;
long long num[11];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    long long ans = 0;
    // for(int i =0 ;i<n;i++){
    //     ans += m / num[i];
    // }
    for (long long i = 1; i < (1 << n); i++)
    {
        long long mult = 1;
        int count = 0;
        for (long long j = 0; j < n; j++)
        {
            if ((1 << j) & i)
            {
                mult *= num[j];
                count++;
            }
        }
        // cout<<mult<<"\n";
        if (count % 2 == 0)
        {
            ans -= m / mult;
        }
        else
        {
            ans += m / mult;
        }
    }
    cout << ans << "\n";
    return 0;
}
