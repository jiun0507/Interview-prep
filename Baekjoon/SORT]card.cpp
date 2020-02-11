//baekjoon 11652
//카드
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
struct person{
    string name;
    int korean;
    int english;
    int math;
};
bool cmp_y(person &u, person &v){
    if(u.korean>v.korean){
        return true;
    }else if(u.korean == v.korean){
        if(u.english<v.english) return true;
        else if(u.english == v.english){
            if(u.math>v.math){
                return true;
            }
            else if(u.math == v.math){
                return u.name.compare(v.name)<0;
            }
        }
    }


    return false;
}


int main(void){
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    int n;
    cin>>n;
    vector<long long> a(n);
    for(int i =0;i<n;i++){
        cin>>a[i];
    }
	sort(a.begin(), a.end());
	long long ans = a[0];
	int max = 1;
	int cnt = 1;
	long long prev = a[0];
    for(int i =1;i<n;i++){
        if(prev == a[i]){
            cnt++;
        }
        else{
            cnt = 1;
            prev = a[i];
        }
        if(cnt>max){
            max = cnt;
            ans = a[i];
        }
    }
    
    cout<<ans<<"\n";
    return 0;
}