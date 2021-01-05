//baekjoon 2422
//한윤정은 이탈리아에 가서 아이스크림을 사먹는데
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int no[201][201];
int menu, m;

int main(void)
{
    cin >> menu >> m;
    for (int i = 0; i < m; i++)
    {
        int y, x;
        cin >> y >> x;
        no[y][x] = 1;
        no[x][y] = 1;
    }
    int cnt = 0;
    for (int i = 1; i <= menu; i++)
    {
        for (int j = i + 1; j <= menu; j++)
        {
            for (int k = j + 1; k <= menu; k++)
            {
                if (no[i][k] || no[i][j] || no[j][k])
                    continue;
                cnt++;
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}