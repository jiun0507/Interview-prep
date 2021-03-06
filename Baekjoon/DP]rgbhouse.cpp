//baekjoon onetwothree 1149
//DP forloop from the bottom
//least price to paint n houses with rgb with given prices for painting
//rgb for ith house
#include <iostream>
#include <algorithm>
using namespace std;

long long price[1001][4] = {0};
int color[1001][4];
//if we paint nth house with i color.
//the least money spent is price[n][i] = color[i] + min(price[n-1][i-1],price[n-1][i+1]);

void paint(int n)
{
	for (int j = 0; j < 3; j++)
	{
		price[0][j] = color[0][j];
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			price[i][j] = color[i][j] + min(price[i - 1][(j + 1) % 3], price[i - 1][(j + 2) % 3]);
		}
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> color[i][j];
		}
	}
	paint(n);
	int min = 2100000000;
	for (int i = 0; i < 3; i++)
	{
		if (min > price[n - 1][i])
		{
			min = price[n - 1][i];
		}
	}
	cout << min << "\n";

	return 0;
}