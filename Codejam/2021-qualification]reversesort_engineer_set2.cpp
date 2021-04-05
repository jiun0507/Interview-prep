
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int pascal[501][501];
int n;

int main()
{
    int t;
    cin>>t;
    int cnt = 1;
    while(t--){
        cout<<"Case #"<<cnt++<<": ";
        int n, cost;
        cin>>n>>cost;

        vector<int> nums(n);
        int mx = 0;
        for(int i = 1;i<=n;i++){
            nums[i-1] = i;
            mx += i;
        }
        if(cost>=mx||cost<n-1){
            cout<<"IMPOSSIBLE\n";
            continue;
        }
        for(int i = n-2;i>=0;i--){
            if(cost-1==i){
                cost--;
                break;
            }
            int possible = n-i;
            int shift = possible;
            if(cost - possible < i){
                shift = cost-i;
            }
            // for(int a:nums){
            //     cout<<a<<" ";
            // }
            // cout<<"\n";
            // cout<<shift<<" "<<cost<<"\n";
            cost -= shift;
            reverse(nums.begin()+i, nums.begin()+i+shift);
        }
        for(int a:nums){
            cout<<a<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
