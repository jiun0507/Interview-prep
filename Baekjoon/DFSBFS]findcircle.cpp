//baekjoon 1260

//DFS and BFS implemented using edge list(count array) and linked list(vector)

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

int m, n;
int check[51][51];
char board[51][51];
int movey[4] = {0, 0, -1, 1};
int movex[4] = {-1, 1, 0, 0};
int starty, startx;

bool DFSlist(int y, int x, char c, int distance)
{
	check[y][x] = distance;
	for (int i = 0; i < 4; i++)
	{
		int newy = y + movey[i];
		int newx = x + movex[i];
		if (newy < 0 || newy >= n || newx < 0 || newx >= n)
			continue;
		else if (check[newy][newx] == 0 && board[newy][newx] == c)
		{
			if (DFSlist(newy, newx, c, distance + 1))
			{
				return true;
			}
		}
		else if (newy == starty || newx == startx)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	string str;
	cin >> m >> n;
	cin.ignore();
	for (int i = 0; i < m; i++)
	{
		getline(cin, str);
		for (int j = 0; j < n; j++)
		{
			board[i][j] = str.at(j);
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (check[i][j] == 0)
			{
				starty = i;
				startx = j;
				if (DFSlist(i, j, board[i][j], 1))
				{
					cout << "Yes"
						 << "\n";
					for (int i = 0; i < m; i++)
					{
						for (int j = 0; j < n; j++)
						{
							cout << check[i][j] << " ";
						}
						cout << "\n";
					}
					return 0;
				}
			}
		}
	}

	cout << "No"
		 << "\n";

	return 0;
}