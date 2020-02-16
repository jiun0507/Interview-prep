//baekjoon 16938
//캠프 준비
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int A[15];
int n;
int diff, L,R;

vector<int> change(int bit){
    vector<int> output;
    for(int i = 0;i<n;i++){
        output.push_back((bit&1) == 1);
        bit >>=1;
    }
    return output;
}

bool works(vector<int> &sequence){
    int questions = 0;
    int sum = 0;
    int mx = 0;
    int mn = INT_MAX;
    for(int i = 0;i<n;i++){
        if(sequence[i] == 1){
            questions++;
            sum += A[i];
            mx = max(mx, A[i]);
            mn = min(mn, A[i]);
        }
    }
    return questions>=2 && sum>=L && sum<=R && (mx-mn)>=diff;
}

int main(void){
    cin>>n>>L>>R>>diff;
    for(int i =0 ;i<n;i++){
        cin>>A[i];
    }
    int ans = 0;
    for(int i = 0;i<(1<<n);i++){
        vector<int> sequence = change(i);
        if(works(sequence)) ans++;
    }
    cout<<ans<<"\n";
    
}