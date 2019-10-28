#include <bits/stdc++.h>
using namespace std;

bool customSort(const pair<int,int> &arrive, pair<int, int> &depart){
    if(arrive.first == depart.first){
        return arrive.second < depart.second;
    }
    return arrive.first < depart.first;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pair<int,int>> trains;
        int time;
        for(int i=0;i<2;i++){
            for(int j=0;j<n;j++){
                cin>>time;
                trains.push_back(make_pair(time, i));
            }
        }
        sort(trains.begin(), trains.end(), customSort);
        int stations = 0;
        int max = 0;
        for(int i=0;i<2*n;i++){
            if(trains[i].second == 0){
                stations += 1;
            }
            if(trains[i].second == 1){
                stations -= 1;
            }
            if(stations > max){
                max = stations;
            }
        }
        cout<< max <<endl;
	//code
    }
	return 0;
}
