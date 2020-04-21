//baekjoon 7562

//DFS and BFS implemented using edge list(count array) and linked list(vector)
//how many moves does the knight have to make?
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

int n;
int check[301][301];
int knights[301][301];
int movey[8] = {-2, 2, -2, 2, -1, 1, -1, 1};
int movex[8] = {-1, 1, 1, -1, -2, 2, 2, -2};
int starty, startx, endy, endx;

int BFSlist(int y, int x)
{
	int length = 1;
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	knights[y][x] = length;
	while (!q.empty())
	{
		pair<int, int> coor = q.front();
		q.pop();
		y = coor.first;
		x = coor.second;
		if (endy == y && endx == x)
		{
			return knights[y][x];
		}
		length = knights[y][x] + 1;
		for (int i = 0; i < 8; i++)
		{
			int newy = y + movey[i];
			int newx = x + movex[i];
			if (newy < 0 || newx < 0 || newy >= n || newx >= n)
				continue;
			if (knights[newy][newx] == 0)
			{
				q.push(make_pair(newy, newx));
				knights[newy][newx] = length;
			}
		}
	}
	return -1;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				knights[i][j] = 0;
			}
		}
		cin >> n;
		cin >> starty >> startx;
		cin >> endy >> endx;
		int distance = BFSlist(starty, startx);
		cout << distance - 1 << "\n";
	}

	return 0;
}