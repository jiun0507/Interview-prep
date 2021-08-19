//Amazon OA review

#include <iostream>
#include <bits/stdc++.h>


using namespace std;

int x[10] = {3, 5, 2, 3, 5, 6, 7, 4, 1, 5};
int y[10] = {3, 5, 3, 3, 5, 6, 7, 4, 3, 5};


int main() {
    vector<pair<int,int>> restaurants;
    for(int i = 0;i<10;i++){
        restaurants.push_back(make_pair(x[i], y[i]));
    }
    int minimum = 1000000001;
    int index = -1;
    for(int i = 0;i<10;i++){
        int dist = (restaurants[i].first *restaurants[i].first) + (restaurants[i].second *restaurants[i].second);
        if(minimum > dist){
            minimum = dist;
            index = i;
        }
    }
    cout<<index<<"\n";
    return index;
}