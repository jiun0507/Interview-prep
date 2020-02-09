//baekjoon 1517
//버블 소트

//baekjoon 2447
//별찍기 10
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int num[500001];
int b[500001];

long long merge(int start, int middle, int end){
    long long cnt = 0;
    int i = start;
    int j = middle +1;
    int k = start;
    while(i<=middle && j<=end){
        // cout<<k<<" ";
        if(num[i]>num[j]){
            // cout<<"yes";
            b[k++] = num[j++];
            cnt += middle- i + 1;
        }
        else if(num[i]<=num[j]){
            b[k++] = num[i++];
            
        }        
    }
    while(i<=middle){
        b[k++] = num[i++];
    }
    while(j<=end){
        b[k++] = num[j++];
    }
    for(int l = start;l<=end;l++){
        num[l] = b[l];
    }
    return cnt;
}

long long solve(int start, int end){
    
    if(start== end) return 0;
    int middle = (start+ end)/2;
    long long ans = solve(start, middle) + solve(middle+1, end);
    return ans + merge(start, middle, end);
    
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