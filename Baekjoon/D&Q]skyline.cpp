//baekjoon 1933
//스카이라인
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
struct Building {
    int left, right, height;
};
void append(vector<pair<int,int>> &skyline, pair<int, int> vertex){
    int n = skyline.size();
    if(n>0){
        if(skyline[n-1].second == vertex.second) return;
        if(skyline[n-1].first == vertex.first){
            skyline[n-1].second = vertex.second;
            return;
        }
    }
    skyline.push_back(vertex);
}

vector<pair<int,int>> merge(vector<pair<int,int>> &ans1, vector<pair<int,int>> &ans2){
    int i = 0;
    int j = 0;
    vector<pair<int,int>> temp;
    int h1, h2;
    h1 = h2 = 0;
    while(i<ans1.size() && j<ans2.size()){
        int x1, x2;
        x1 = ans1[i].first;
        x2 = ans2[j].first;
        if(x1<x2){
            h1 = ans1[i].second;
            int h = max(h1, h2);
            append(temp, make_pair(x1, h));
            i++;
        }
        else{
            h2 = ans2[j].second;
            int h = max(h1, h2);
            append(temp, make_pair(x2, h));
            j++;
        }    
    }
    while(i<ans1.size()){
        append(temp, ans1[i++]);
    }
    while(j<ans2.size()){
        append(temp, ans2[j++]);
    }
    return temp;
}

vector<pair<int,int>> solve(vector<Building> &skyline, int start, int end){
    if(start == end){
        vector<pair<int,int>> ans;
        ans.push_back(make_pair(skyline[start].left, skyline[start].height));
        ans.push_back(make_pair(skyline[start].right, 0));
        return ans;
    }
    int middle = (start+end)/2;
    vector<pair<int,int>> ans1 = solve(skyline, start, middle);
    vector<pair<int,int>> ans2 = solve(skyline, middle+1, end);
    vector<pair<int,int>> ans = merge(ans1, ans2);
    return ans;
    
}

int main(void){
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
    vector<Building> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i].left >> a[i].height >> a[i].right;
    }
    sort(a.begin(), a.end(), [](auto &u, auto &v) {
        return make_tuple(u.left, u.height, u.right) < make_tuple(v.left, v.height, v.right);
    });
	
	vector<pair<int,int>> ans = solve(a,0, n-1);
	for(int i = 0;i<ans.size();i++){
	    cout<<ans[i].first<<" "<<ans[i].second<<" ";
	}
	cout<<"\n";
	return 0;
	
}