
//16928 백준
//뱀과 사다리

#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int n, m;
int check[105] = {0};
int ladder[105] = {0};
int snake[105] = {0};
void bfs()
{
    int start = 1;
    deque<int> next;
    next.push_back(start);
    check[start] = 0;
    while (!next.empty())
    {
        int cur = next.front();
        next.pop_front();
        for (int i = 1; i <= 6; i++)
        {
            int future = cur + i;
            if (future > 100)
                break;
            if (ladder[future] != 0)
            {
                if (check[ladder[future]] == 0)
                {
                    check[ladder[future]] = check[cur] + 1;
                    next.push_back(ladder[future]);
                }
                else
                {
                    continue;
                }
            }
            else if (snake[future] != 0)
            {
                if (check[snake[future]] == 0)
                {
                    check[snake[future]] = check[cur] + 1;
                    next.push_back(snake[future]);
                }
                else
                {
                    continue;
                }
            }
            else if (check[future] == 0)
            {
                check[future] = check[cur] + 1;
                next.push_back(future);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    int start, end;
    for (int i = 0; i < n; i++)
    {
        cin >> start >> end;
        ladder[start] = end;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> start >> end;
        snake[start] = end;
    }
    bfs();
    cout << check[100] << endl;
    return 0;
}