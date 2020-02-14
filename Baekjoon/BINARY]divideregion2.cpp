//baekjoon 13397
//구간나누기2
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int nums[100001];
int n, m;
bool possible(int length){
    int small = nums[0];
    int big = nums[0];
    int group = 1;
    for(int i = 1;i<n;i++){
        if(max(big, nums[i])-min(small, nums[i])>length){
            small = nums[i];
            big = nums[i];
            group +=1;
        }
        else{
            big = max(big, nums[i]);
            small = min(small, nums[i]);
        }
    }
    return group <=m;
}

int main(void){
    cin>>n>>m;
    int max = 0;
    int left= 10001;
    int right = 0;
    for(int i = 0;i<n;i++){
        cin>>nums[i];
        if(right<nums[i]) right = nums[i];
        if(left>nums[i]) left = nums[i];
    }
    right -= left;
    left = 0;
    // cout<<right<<" "<<left<<"\n";
    int ans;
    while(left<=right){
        int middle = (right+left)/2;
        if(possible(middle)){
            ans = middle;
            right = middle -1;
        }
        else{
            left = middle + 1;
        }
    }
    cout<<ans<<"\n";
    return 0;
}