//baekjoon 16964
//special judge for DFS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
int check[100001];
vector<int> connection2[100001];
int submit[100001];
int subIndex;
int parent[100001];
int order[100001];
vector<int> dfsResult;

void DFSlist(int index)
{
	check[index] = 1;
	dfsResult.push_back(index);
	for (int E : connection2[index])
	{
		if (!check[E])
		{
			DFSlist(E);
		}
	}
	return;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int from, to;
		cin >> from >> to;
		connection2[from].push_back(to);
		connection2[to].push_back(from);
	}
	for (int i = 0; i < n; i++)
	{
		cin >> submit[i];
	}
	for (int i = 1; i <= n; i++)
	{
		sort(connection2[i].begin(), connection2[i].end());
	}

	for (int i = 0; i < n; i++)
	{
		order[submit[i]] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		sort(connection2[i].begin(), connection2[i].end(), [&](const int &u, const int &v) {
			return order[u] < order[v];
		});
	}
	DFSlist(1);
	bool ok = true;
	for (int i = 1; i <= n; i++)
	{
		if (submit[i] != dfsResult[i])
		{
			ok = false;
			break;
		}
	}
	cout << ok << "\n";
	return 0;
}