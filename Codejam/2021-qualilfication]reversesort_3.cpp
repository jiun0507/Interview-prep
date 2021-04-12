
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
        for(int i = 1;i<=n;i++){
            nums[i-1] = i;
        }
        bool found = false;
        do{
            vector<int> v = nums;
            int total = 0;
            for(int i = 0;i<n-1;i++){
                int mn = v[i];
                int index = i;
                for(int j = i+1;j<n;j++){
                    if(mn>v[j]){
                        mn = v[j];
                        index = j;
                    }
                }
                total += index - i + 1;
                reverse(v.begin()+i, v.begin()+index+1);
            }
            if(total==cost){
                for(int a:nums){
                    cout<<a<<" ";
                }
                cout<<"\n";
                found =true;
                break;
            }
        }while(next_permutation(nums.begin(),nums.end()));
        if(!found){
            cout<<"IMPOSSIBLE\n";
        }
    }
    return 0;
}
