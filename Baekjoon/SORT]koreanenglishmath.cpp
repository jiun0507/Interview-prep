//baekjoon 10825
//국영수
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
struct person{
    string name;
    int korean;
    int english;
    int math;
};
bool cmp(const Person &u, const Person &v) {
    return make_tuple(-u.korean, u.english, -u.math, u.name) < make_tuple(-v.korean, v.english, -v.math, v.name);
}
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
    vector<person> a(n);
    for(int i =0;i<n;i++){
        string name;
        int korean, english,math;
        cin>>name>>korean>>english>>math;
        person temp = {name, korean, english,math};
        a[i] =temp ;
    }
	sort(a.begin(), a.end(), cmp_y);
    for(int i =0;i<n;i++){
        cout<<a[i].name<<"\n";
    }
}