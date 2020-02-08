//baekjoon 1891
//사분면

//longlong 사용하기
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long two[50];

pair<long long, long long> solve(int index, string &a, long long y, long long x, long long size){
    if(size == 1){
        return make_pair(y, x);
    }
    if(a[index] == '1') return solve(index +1, a, y, x+size/2, size/2);
    else if(a[index] == '2') return solve(index +1, a, y, x, size/2);
    else if(a[index] == '3') return solve(index +1, a, y + size/2, x, size/2);
    else if(a[index] == '4') return solve(index +1, a, y + size/2, x+size/2, size/2);
    return make_pair(0, 0);
}
string go(long long r, long long c, long long y, long long x, long long size){
    if(size == 1){
        return "";
    }
    if(r+size/2>y){
        if(c+size/2>x){
            return '2' + go(r, c, y, x, size/2);
        }
        else{
            return '1' + go(r, c+size/2, y, x, size/2);
        }
    }
    else if(r+size/2<=y){
        if(c+size/2>x){
            return '3' + go(r+size/2, c, y, x, size/2);
        }
        else{
            return '4' + go(r+size/2, c+size/2, y, x, size/2);
        }
    }
    return "-1";
}

int main(void){
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int d;
	string num;
	cin>>d;
	cin>>num;
	long long right, up;
	cin>>right>>up;
	two[0] = 1;
	for(int i = 1;i<=50;i++){
	    two[i] = 1LL<<i; 
	}
// 	cout<<two[d]<<"\n";
    auto p = solve(0, num, 0, 0, two[d]);
    // cout<<p.first<<" "<<p.second;
    long long y = p.first - up;
    long long x = p.second + right;
    if(y<0 || y>=two[d] || x<0 || x>=two[d]){
        cout<<"-1"<<"\n";
    }
    else{
        cout<<go(0, 0, y, x, two[d])<<"\n";
    }
    return 0;
}