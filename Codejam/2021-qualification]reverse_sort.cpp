// Pascal walk
// a OK
// b OK
// c OK
// a => 그냥 옆선만 따라 가도 해결
// b => 옆선 따라가다 한번 꺾어주기만 해도 해결
// c => n-30을 이진수로 표현. row가 check되어 있으면 horizontally 가로지름. 계속 내려감. 
// 부족한 숫자만큼 다 끝난뒤 옆선을 따라서 계속 움직임. 


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
        int n;
        cin>>n;
        vector<int> nums(n);
        for(int i = 0;i<n;i++){
            cin>>nums[i];
        }
        int total = 0;
        for(int i = 0;i<n-1;i++){
            int mn = nums[i];
            int index = i;
            for(int j = i+1;j<n;j++){
                if(mn>nums[j]){
                    mn = nums[j];
                    index = j;
                }
            }
            total += index - i + 1;
            // for(int a: nums){
            //     cout<<a<<" ";
            // }
            // cout<<"\n";
            reverse(nums.begin()+i, nums.begin()+index+1);
        }
        cout<<total<<"\n";

    }
    return 0;
}
