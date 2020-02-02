//baekjoon 11399
//atm
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;



int main(void){
    int n;
    cin>>n;
    vector<int> d(n);
    for(int i = 0;i<n;i++){
        cin>>d[i];
    }
    int cumu[n];
    
    sort(d.begin(),d.end());
    cumu[0] = d[0];
    for(int i = 1;i<n;i++){
        cumu[i] = d[i] + cumu[i-1];
    }
    int ans = 0;
    for(int i = 0;i<n;i++){
        ans +=cumu[i];
    }
    cout<<ans<<"\n";
}
