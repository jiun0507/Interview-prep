// 15558 점프 게임
// baekjoon
#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

int n, k;
int check[2][100001];
char board[2][100001];

int main()
{
    memset(check, -1, sizeof(check));
    cin >> n >> k;
    cin >> board[0];
    cin >> board[1];
    queue<pair<int, int>> q; //number, left or right 0 = left 1 = right
    q.push(make_pair(0, 0));
    check[0][0] = 1;
    bool found = false;
    for (int turn = 0; turn < n; turn++)
    {
        queue<pair<int, int>> nq;
        while (!q.empty())
        {
            int cur, lr;
            tie(lr, cur) = q.front();
            q.pop();
            if (cur < turn)
                continue;
            for (int next : {cur + 1, cur - 1})
            {
                if (next >= n)
                {
                    found = true;
                    break;
                }
                if (next < 0 || board[lr][next] == '0')
                    continue;
                if (check[lr][next] == -1)
                {
                    nq.push(make_pair(lr, next));
                    check[lr][next] = 1;
                }
            }
            lr = 1 - lr;
            int next = cur + k;
            if (next >= n)
            {
                found = true;
                break;
            }
            else if (board[lr][next] != '0' && check[lr][next] == -1)
            {
                nq.push(make_pair(lr, next));
                check[lr][next] = 1;
            }
            if (found)
                break;
        }
        if (found)
            break;
        q = nq;
        nq = queue<pair<int, int>>();
    }

    if (found)
        cout << 1 << endl;
    else
    {
        cout << 0 << endl;
    }
    return 0;
}
