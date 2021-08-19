//Amazon OA review

#include <iostream>
#include <bits/stdc++.h>


using namespace std;

vector<pair<int,int>> forwards;
vector<pair<int,int>> returns;
int maximumDistance = 10000;

int fdist[10] = {1000, 2000, 3000, 4000, 5000, 6000, 9000, 9000, 9000, 10000};
int rdist[10] = {1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000};

int main() {
    for(int i = 0;i<10;i++){
        forwards.push_back(make_pair(i, fdist[i]));
        returns.push_back(make_pair(i, rdist[i]));
    }
    
    map<int,vector<int>> forw;
    for(int i = 0;i<forwards.size();i++){
        if(forw.count(maximumDistance-forwards[i].second)==0){
            forw[maximumDistance-forwards[i].second] = vector<int>(1, forwards[i].first);   
        }
        else{
            forw[maximumDistance-forwards[i].second].push_back(forwards[i].first);
        }
    }
    int maximum = maximumDistance;
    vector<pair<int,int>> ans;
    for(int i = 0;i<returns.size();i++){
        auto it = forw.lower_bound(returns[i].second);
        if(it != forw.end()){
            if(maximum >= (it->first - returns[i].second)){
                if(maximum > (it->first - returns[i].second)){
                    ans.clear();
                    maximum = it->first - returns[i].second;
                }
                for(auto &route: it->second){
                    ans.push_back(make_pair(route, i));
                }
            } 
        }
    }
    for(int i = 0;i<ans.size();i++){
        cout<<ans[i].first<<" "<<ans[i].second<<"\n";
    }

    return 0;
}