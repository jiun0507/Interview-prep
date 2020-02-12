
//baekjoon 1790
//수 이어 쓰기2
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long base[10];
long long tens[10];
int k;

int numofdigits(int m){
    int cnt = 0;
    while(m!=0){
        cnt++;
        m/=10;
    }
    return cnt;
}

int kth(int m){
    int cnt = numofdigits(m);
    int basis = tens[cnt];
    //tens[2] = 10
    int ans = (cnt) * (m-(basis-1));
    // cout<<m<<" "<<cnt<<basis<<"\n";
    if(cnt>=2){
        ans += base[cnt-1];
        //base[1] = 9
    }
    return ans;
}
int solve(int start, int end){
    int middle = (start+end)/2;
    int num = kth(middle);
    if(start>=end){
        return middle;
    }
    if(num<k){
        return solve(middle+1, end);
    }
    else if(num>=k){
        if(num == k){
            return middle;
        }
        return solve(start, middle-1);
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	cin>>k;

    int start = 9;
    base[1] = 9;
    for(int i = 2;i<=9;i++){
        base[i] = base[i-1] + i*start*10;
        start*=10;
    }
    tens[1] = 1;
    for(int i = 2;i<=9;i++){
        tens[i] = tens[i-1] * 10;
    }
    if(kth(n)<k){
        cout<<"-1\n";
        return 0;
    }
    
    int closest = solve(1, n);
    int cumu = kth(closest);
    int dist = cumu-k;
    // cout<<cumu<<"\n";
    if(dist<0){
        closest++;
        dist = -dist-1;
        string ans = to_string(closest);
        cout<<ans.at(dist)<<"\n";
    }
    else{
        string ans = to_string(closest);
        reverse(ans.begin(), ans.end());
        cout<<ans.at(dist)<<"\n";
    }
    // string test = "12345";
    // cout<<test.at(0)<<"yes\n";
    
    return 0;
}