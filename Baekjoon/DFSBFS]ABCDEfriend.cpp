//baekjoon 13023

#include <iostream>
#include <vector>
using namespace std;

int n, m;
bool connection1[2000][2000];
vector<int> connection2[2000];
vector<pair<int, int>> connection3;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int from, to;
		cin >> from >> to;
		connection3.push_back({from, to});
		connection3.push_back({to, from});
		connection2[from].push_back(to);
		connection2[to].push_back(from);
		connection1[from][to] = connection1[to][from] = 1;
	}
	m *= 2;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int A = connection3[i].first;
			int B = connection3[i].second;
			int C = connection3[j].first;
			int D = connection3[j].second;
			if (A == C || A == D || A == B || B == C || B == D || B == A)
			{
				continue;
			}
			if (!connection1[B][C])
			{
				continue;
			}
			for (int E : connection2[D])
			{
				if (A != E && B != E && C != E)
				{
					cout << "1"
						 << "\n";
					return 0;
				}
			}
		}
	}
	cout << "0"
		 << "\n";

	return 0;
}