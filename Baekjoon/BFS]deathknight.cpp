//baekjoon 16948
//death knight

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n;
int newy[6] = {-2, -2, 0, 0, 2, 2};
int newx[6] = {-1, 1, -2, 2, -1, 1};
int r1, c1, r2, c2;
int block[210][210];
int dist[210][210];

bool check_range(int y, int x)
{
	return y >= 0 && y < n && x >= 0 && x < n;
}
int BFS(int r, int c)
{
	queue<pair<int, int>> list;
	list.push(make_pair(r, c));
	dist[r][c] = 0;
	while (!list.empty())
	{
		auto cur = list.front();
		list.pop();
		int y = cur.first;
		int x = cur.second;
		int len = dist[y][x];
		if (y == r2 && x == c2)
			return len;
		for (int i = 0; i < 6; i++)
		{
			int ny = y + newy[i];
			int nx = x + newx[i];
			if (!check_range(ny, nx))
				continue;
			if (dist[ny][nx] == -1)
			{
				dist[ny][nx] = len + 1;
				list.push(make_pair(ny, nx));
			}
		}
	}
	return -1;
}

int main()
{
	cin >> n;
	cin >> r1 >> c1 >> r2 >> c2;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			dist[i][j] = -1;
		}
	}
	cout << BFS(r1, c1) << "\n";

	// for(int i = 0;i<n;i++){
	// 	for(int j = 0;j<n;j++){
	// 		cout<<dist[i][j]<<" ";
	// 	}
	// 	cout<<"\n";
	// }
	return 0;
}