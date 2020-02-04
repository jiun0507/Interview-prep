//baekjon 12738
//가장 긴 증가하는 수열 3

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n;

int main(void){
    cin>>n;
    vector<int> arr(n);
    vector<int> ans;
    
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    ans.push_back(arr[0]);
    for(int i = 1;i<n;i++){
        auto it = lower_bound(ans.begin(),ans.end(), arr[i]);
        if(it != ans.end()){
            *it = arr[i];
        }
        else{
            ans.push_back(arr[i]);
        }
    }
    cout<<ans.size()<<"\n";
    
    return 0;
}