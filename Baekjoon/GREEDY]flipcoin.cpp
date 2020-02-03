//baekjoon 1285
//동전 뒤집기
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> gen(int k){
    vector<int> ans;
    for(int i = 0;i<n;i++){
        ans.push_back(k&1);
        k >>=1;
    }
    return ans;
}
int flip(vector<int> &dir, vector<string> before){
    for(int i = 0;i<n;i++){
        if(dir[i] == 1){
            for(int j= 0;j<n;j++){
                if(before[j][i] == 'H') before[j][i] = 'T';
                else{
                    before[j][i] = 'H';
                }
            }
        }
    }
    int cnt = 0;
    for(int i = 0;i<n;i++){
        int tail = 0; int head = 0;
        for(int j = 0;j<n;j++){
            if(before[i][j] == 'H') head +=1;
            else if(before[i][j] == 'T') tail +=1;
        }
        cnt += min(tail, head);
    }
    return cnt;
}
int main(void){
    cin >> n;
    
    vector<string> a(n);
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }
    int ans = 1000;;
    for(int i = 0;i<(1<<n);i++){
        vector<int> dir = gen(i);
        int temp = flip(dir, a);
        if(ans >temp){
            ans = temp;
        }
    }
    cout<<ans<<"\n";
}
