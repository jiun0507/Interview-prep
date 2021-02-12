// 11799 최소비용구하기 2
// baekjoon
// 다익스트라로 최단경로의 경로까지 구하기

#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

int n, m;
vector<pair<int,int>> edges[1001];

int check[1001];
pair<int,int> dist[1001]; //distance, from
long long inf = 1000000001;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(check, -1, sizeof(check));
    cin>>n;
    cin>>m;
    for(int i = 1;i<=m;i++){
        int from, to, dist;
        cin>>from>>to>>dist;
        edges[from].push_back(make_pair(to, dist));
    }
    for(int i = 1;i<=n;i++){
        dist[i] = make_pair(-1, -1);
    }
    int start, end;
    cin>>start>>end;
    dist[start] = make_pair(0, -1);
    for(int i = 0;i<n-1;i++){
        int cur = -1;
        int temp = -1;
        for(int j = 1;j<=n;j+=1){
            if(check[j]==-1&&dist[j].first!=-1&&(temp==-1||temp>dist[j].first)){
                cur = j;
                temp = dist[j].first;
            }
        }
        check[cur] = 1;
        for(auto &next:edges[cur]){
            if(check[next.first]==-1){
                if(dist[next.first].first==-1||dist[next.first].first>dist[cur].first+next.second){
                    dist[next.first] = make_pair(dist[cur].first+next.second, cur);
                }
            }
        }
        // for(int i = 1;i<=n;i++){
        //     cout<<dist[i].first<<" "<<dist[i].second<<endl;
        // }
        // cout<<"\n";
    }
    
    cout<<dist[end].first<<endl;
    // for(int i = 1;i<=n;i++){
    //     cout<<dist[i].first<<" "<<dist[i].second<<endl;
    // }
    vector<int> ans;
    while(end!=-1){
        ans.push_back(end);
        end = dist[end].second;
    }
    cout<<ans.size()<<endl;
    reverse(ans.begin(), ans.end());
    for(auto &a:ans){
        cout<<a<<" ";
    }
    cout<<"\n";

    return 0;
}
