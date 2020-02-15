
//baekjoon 1939
//중량 제한
#include <iostream>
#include <bits/stdc++.h>

using namespace std; 

int n,m;
int fac1, fac2;
int check[10001];
vector<pair<int,int>> connection[10001];

bool DFSlist(int island, int weight){
	check[island] = 1;
	if(island == fac2){
	    return true;
	}
	for(auto &p:connection[island]){
		if(!check[p.first] && p.second>=weight){
			if(DFSlist(p.first, weight)){
			    return true;
			}
		}
	}
	return false;
}


int main(void){
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	cin>>m;
    long long max = -1;
	for(int i =0 ;i<m;i++){
		int from, to, limit;
		cin>>from>>to>>limit;
		if(max == -1||max < limit) max = limit;
		connection[from].push_back(make_pair(to, limit));
		connection[to].push_back(make_pair(from, limit));
	}
	cin>>fac1>>fac2;
// 	cout<<fac1<<fac2<<"\n";
// 	for(int i =0 ;i<n;i++){
// 		sort(connection[i].begin(), connection[i].end());
// 	}
    long long left = 1;
    long long right = max;
    long long ans = -1;
    
    while(left<=right){
        long long  middle = (left+right)/2;
        memset(check, 0, sizeof(check));
        // cout<<left<<" "<<right<<" "<<middle<<" "<<can<<"\n";
        if(DFSlist(fac1, middle)){
            ans = middle;
            left = middle +1;
        }
        else{
            right = middle -1;
        }
    }
    cout<<ans<<"\n";

    
    return 0;
}