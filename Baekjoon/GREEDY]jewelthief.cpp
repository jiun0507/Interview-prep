//baekjoon 1202
//보석도둑
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int n,k;
vector<pair<int,int>> jewel;
multiset<int> bag;
bool bagcmp(int & a, int &b){
    return a>b;
}
bool compare(pair<int,int> &a, pair<int, int> &b){
    return a.first > b.first;
}
int main(void){
    
    cin>>n>>k;

    
    for(int i = 0;i<n;i++){
        int jewelM, jewelV;          
        cin>>jewelM>>jewelV;
        jewel.push_back(make_pair(jewelV, jewelM));
    }
    // vector<int> bag(k);
    for(int i = 0;i<k;i++){
        int bagsize;
        cin>>bagsize;
        bag.insert(bagsize);
        // cin>>bag[i];
    }
    sort(jewel.begin(), jewel.end(), compare);
    // for(int i = 0;i<k;i++){
    //     cout<<bag[i]<<" ";
    // }
    long long money = 0;
    for(int i = 0;i<n;i++){
        if(bag.empty()){
            break;
        }
        
        auto it = bag.lower_bound(jewel[i].second);
        if(it != bag.end()){
            bag.erase(it);
            money += jewel[i].first;
            // cout<<"found";
            // cout<<bag[1]<<"\n";
        }
        
    }
    cout<<money<<"\n";
}