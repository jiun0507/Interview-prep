//baekjoon 2261
//가장 가까운 두 점
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
struct Point{
    int y, x;
};

bool cmp_x(Point &u, Point &v){
    return make_pair(u.x, u.y)<make_pair(v.x, v.y);
}
bool cmp_y(Point &u, Point &v){
    return make_pair(u.y, u.x)<make_pair(v.y, v.x);
}

int brute_force(vector<Point> &Points, int start, int end){
    int ans = -1;
    for(int i = start;i<end;i++){
        for(int j = i+1;j<=end;j++){
            auto x1 = Points[i];
            auto x2 = Points[j];
            int dist = (x1.x - x2.x)*(x1.x - x2.x) + (x1.y - x2.y)*(x1.y - x2.y);
            if(ans== -1 ||dist<ans) ans = dist;
        }
    }
    return ans;
}

int solve(vector<Point> &Points, int start, int end){
    int n = end-start+1;
    if(n<3){
        return brute_force(Points, start, end);
    }
    int middle = (start+end)/2;
    int left = solve(Points, start, middle);
    int right = solve(Points, middle+1, end);
    int ans = min(left, right);
    vector<Point> b;
    for(int i = start;i<=end;i++){
        int d =  Points[i].x - Points[middle].x;
        if(d*d<ans){
            b.push_back(Points[i]);
        }
    }
    sort(b.begin(), b.end(), cmp_y);
    int m = (int)b.size();
    for(int i= 0;i<m-1;i++){
        for(int j = i+1;j<m;j++){
            auto x1 = Points[i];
            auto x2 = Points[j];
            int dist = (x1.x - x2.x)*(x1.x - x2.x) + (x1.y - x2.y)*(x1.y - x2.y);
            if(ans > dist) ans = dist;
        }
    }
    return ans;
    
}

int main(void){
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
    vector<Point> a(n);
    for(int i = 0;i<n;i++){
        int x, y;
        cin>>x>>y;;
        a[i] = {x,y};
    }
    sort(a.begin(), a.end(), cmp_x);
    cout<<solve(a, 0, n-1);
    
    
	
}