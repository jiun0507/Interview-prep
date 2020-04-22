//baekjoon 13913
//hideandseek4
//find the path as well as the time it takes

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

int n, k;
int check[100010];
int cnt[100010];
int backtrace[100010];

//better way(recursively)
void print(int n, int m)
{
	if (n != m)
	{
		print(n, backtrace[m]);
	}
	print << m << " ";
}
int BFSlist(int index)
{
	queue<int> q;
	q.push(index);
	check[index] = 1;
	int distance = 0;
	cnt[index] = distance;
	while (!q.empty())
	{
		int top = q.front();
		q.pop();
		if (top == k)
		{
			return cnt[top];
		}
		if (top > 0 && !check[top - 1])
		{
			q.push(top - 1);
			check[top - 1] = 1;
			cnt[top - 1] = cnt[top] + 1;
			backtrace[top - 1] = top;
		}
		if (top * 2 <= 100000 && !check[top * 2])
		{
			q.push(top * 2);
			check[top * 2] = 1;
			cnt[top * 2] = cnt[top] + 1;
			backtrace[top * 2] = top;
		}
		if (top + 1 <= 100000 && !check[top + 1])
		{
			q.push(top + 1);
			check[top + 1] = 1;
			cnt[top + 1] = cnt[top] + 1;
			backtrace[top + 1] = top;
		}
	}
	return -1;
}
int main()
{
	cin >> n >> k;
	int time = BFSlist(n);
	cout << time << "\n";
	int ans[100001];
	int cur = k;
	for (int i = time; i >= 0; i--)
	{
		ans[i] = k;
		k = backtrace[k];
	}
	for (int i = 0; i <= time; i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}