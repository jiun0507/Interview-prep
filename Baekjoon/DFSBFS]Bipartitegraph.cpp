//baekjoon 1260

//DFS and BFS implemented using edge list(count array) and linked list(vector)

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

int n, m;
vector<int> connection2[20001];
int check[20001];
int groups[200001];

void DFSlist(int index, int groupID)
{
	check[index] = groupID;
	for (int E : connection2[index])
	{
		if (!check[E])
		{
			DFSlist(E, 3 - groupID);
		}
	}
	return;
}

bool DFSlist2(int index, int groupID)
{
	check[index] = groupID;
	for (int E : connection2[index])
	{
		if (!check[E])
		{
			if (DFSlist2(E, 3 - groupID) == false)
			{
				return false;
			}
		}
		else if (check[index] == check[E])
		{
			return false;
		}
	}
	return true;
}

bool BFSlist(int index)
{
	int groupID = 1;
	queue<int> q;
	q.push(index);
	check[index] = groupID;
	bool ok = true;
	while (!q.empty())
	{
		int top = q.front();
		q.pop();
		groupID = 3 - check[top]; // important that check[top] is subtracted
		for (int E : connection2[top])
		{
			if (!check[E])
			{
				q.push(E);
				check[E] = groupID;
			}
			else if (check[top] == check[E])
			{
				ok = false;
			}
		}
	}
	return ok;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
		{
			connection2[i].clear();
			check[i] = 0;
		}
		for (int i = 0; i < m; i++)
		{
			int from, to;
			cin >> from >> to;
			connection2[from].push_back(to);
			connection2[to].push_back(from);
		}

		for (int i = 0; i < n; i++)
		{
			sort(connection2[i].begin(), connection2[i].end());
		}
		//BFSlist implementation part
		bool ok = true;
		for (int i = 1; i <= n; i++)
		{
			if (!check[i])
			{
				if (!BFSlist(i))
				{
					ok = false;
				}
			}
		}
		printf("%s\n", ok ? "YES" : "NO");
		/*		//DFSlist2 implementation part
		bool ok = true;
		for(int i = 1;i<=n;i++){
			if(!check[i]){
				if(!DFSlist2(i, 1)){
				ok = false;
				}
			}
		}
*/

		//DFSlist implementation part
		/*		bool ok = true;
		for(int i = 1;i<=n;i++){
			for(int j: connection2[i]){
				if(check[i] == check[j]){
					ok = false;
				}
			}
		}
		*/
	}
	return 0;
}