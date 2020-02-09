//baekjoon 1517
//버블 소트


#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int num[500001];
int b[500001];

long long merge(int y1, int x1, int y2, int x2){
    long long cnt = 0;
    int start;
    int k = start = y1;
    while(y1<=x1 && y2<=x2){
        // cout<<k<<" ";
        if(num[y1]>num[y2]){
            // cout<<"yes";
            b[k] = num[y2];
            k++; y2++;
            cnt += x1- y1 + 1;
        }
        else if(num[y1]<=num[y2]){
            b[k++] = num[y1++];
            
        }        
    }
    while(y1<=x1){
        b[k++] = num[y1++];
    }
    while(y2<=x2){
        b[k++] = num[y2++];
    }
    while(start<=x2){
        num[start] = b[start];
        start++;
    }
    return cnt;
}

long long solve(int y, int x){
    
    if(y == x) return 0;
    long long ans = solve(y, (y+x)/2);
    ans += solve((y+x)/2+1, x);
    // cout<<y<<" "<<(y+x)/2<<" "<<(y+x)/2+1<<" "<<x<<"\n";
    return ans +merge(y, (y+x)/2, (y+x)/2+1, x);
    
}

int main(void){
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	for(int i = 0;i<n;i++){
	    cin>>num[i];
	}
	cout<<solve(0, n-1);
	
}