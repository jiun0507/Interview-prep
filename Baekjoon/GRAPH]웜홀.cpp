// 1865 웜홀
// baekjoon

#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

int n, m, w;
struct Edge
{
    long long dist;
    int from, to;
    Edge(int _dist, int _from, int _to) : dist(_dist), from(_from), to(_to)
    {
    }
};

long long t[501];
long long inf = 100000000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int num;
    cin>>num;
    while(num--){
        cin >> n>> m>> w;
        vector<Edge> edges;
        for (int i = 0; i < m; i++){
            int from, to;
            long long dist;
            cin >> from >> to >> dist;
            edges.push_back(Edge(dist, from, to));
            edges.push_back(Edge(dist, to, from));
        }
        
        for(int i=0;i<w;i++){
            int from, to;
            long long dist;
            cin>>from>>to>>dist;
            edges.push_back(Edge(-dist,from,to));
        }
        t[1] = 0;
        bool negative = false;
        for (int i = 1; i <= n; i++)
        {
            for (auto &child : edges)
            {
                if (t[child.from] != inf)
                {
                    if (t[child.to] > t[child.from] + child.dist)
                    {
                        t[child.to] = t[child.from] + child.dist;
                        if (i >= n)
                        {
                            negative = true;
                        }
                    }
                }
            }
        }
        if (negative)
        {
            cout << "YES\n";
        }
        else{
            cout<<"NO\n";
        }
        
    }

    return 0;
}
