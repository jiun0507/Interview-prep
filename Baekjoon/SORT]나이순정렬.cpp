//baekjoon 10841
//나이순 정렬
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
struct person{
    int age;
    string name;
    int join;
};
bool cmp_y(person &u, person &v){
    if(u.age<v.age){
        return true;
    }else{
        if(u.age == v.age){
            return u.join<v.join;
        }
        return false;
    }
}


int main(void){
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    int n;
    cin>>n;
    vector<person> a(n);
    for(int i =0;i<n;i++){
        int first;
        string second;
        cin>>first>>second;
        person temp = {first, second, i};
        a[i] =temp ;
    }
	sort(a.begin(), a.end(), cmp_y);
    for(int i =0;i<n;i++){
        cout<<a[i].age<<" "<<a[i].name<<"\n";
    }
}