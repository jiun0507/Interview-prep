//baekjoon 4963
//DFS BFS problem similar to bipartitgraph but more ways to move on
//DFS and BFS implemented using edge list(count array) and linked list(vector)

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

int n, m;
int check[50][50];
int houses[50][50];
pair<int, int> direction[8] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {-1, -1}, {1, -1}, {1, 1}, {-1, 1}};

void DFSlist(int y, int x, int groupID)
{
	check[y][x] = groupID;
	for (int i = 0; i < 4; i++)
	{
		int newy = y + direction[i].first;
		int newx = x + direction[i].second;
		if (newy < 0 || newy >= n || newx < 0 || newx >= n)
			continue;
		if (check[newy][newx] == 0 && houses[newy][newx] == 1)
		{
			DFSlist(newy, newx, groupID);
		}
	}
	return;
}

void BFSlist(int y, int x, int groupID)
{
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	check[y][x] = groupID;
	while (!q.empty())
	{
		pair<int, int> coor = q.front();
		q.pop();
		y = coor.first;
		x = coor.second;
		for (int i = 0; i < 8; i++)
		{
			int newy = y + direction[i].first;
			int newx = x + direction[i].second;
			if (newy < 0 || newx < 0 || newy >= m || newx >= n)
				continue;
			if (!check[newy][newx] && houses[newy][newx] == 1)
			{
				q.push(make_pair(newy, newx));
				check[newy][newx] = groupID;
			}
		}
	}
	return;
}

int main()
{
	do
	{
		cin >> n >> m;
		if (n == 0 || m == 0)
			break;
		//reset check array
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				check[i][j] = 0;
			}
		}
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> houses[i][j];
			}
		}
		int number = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (houses[i][j] == 1 && check[i][j] == 0)
				{
					number++;
					BFSlist(i, j, number);
				}
			}
		}

		cout << number << "\n";
	} while (true);
	return 0;
}