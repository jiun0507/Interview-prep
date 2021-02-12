// 1916 최소비용 구하기
// baekjoon
// 다익스트라 알고리즘
// 벨만포드와 같이 최단거리 구하기 알고리즘이다. O(V^2)시간안에 문제를 해결하고 O(ElogE)까지도 할 수 있다.
// 시작점 부터 i정점까지 가는 최단거리를 dist[i]라고 할 때 dist[i]가 낮은 점들 부터 하나식 돌면서 해당 정점이
// 간선으로 연결된 정점들의 dist를 업데이트해가는 알고리즘이다. 주변의 정점들의 dist를 업데이트한뒤 또 다음 정점을
// 고른다. 모든 정점은 한번 씩 고르고 고를 떄 마다 모든 정점들의 dist를 비교하므로 O(V) x O(V)시간이 소요된다.
#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

int n, m;
vector<pair<int, int>> edges[1001];

int check[1001];
long long dist[1001];
long long inf = 1000000001;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(check, -1, sizeof(check));
    memset(dist, -1, sizeof(dist));
    cin >> n;
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int from, to, dist;
        cin >> from >> to >> dist;
        edges[from].push_back(make_pair(to, dist));
    }
    int start, end;
    cin >> start >> end;
    dist[start] = 0;
    for (int i = 0; i < n; i++)
    {
        int cur = -1;
        int temp = -1;
        for (int j = 1; j <= n; j += 1)
        {
            if (check[j] == -1 && dist[j] != -1 && (temp == -1 || temp > dist[j]))
            {
                cur = j;
                temp = dist[j];
            }
        }
        check[cur] = 1;
        for (auto &next : edges[cur])
        {
            if (check[next.first] == -1)
            {
                if (dist[next.first] == -1 || dist[next.first] > dist[cur] + next.second)
                {
                    dist[next.first] = dist[cur] + next.second;
                }
            }
        }
    }

    cout << dist[end] << endl;

    return 0;
}
