#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> discovered;
vector<bool> isCutVertex;
int count = 0;

int findCutVertex(bool isRoot, int here){

    int children = 0;
    for(int i = 0;i<adj[here].size();i++){
        int there = adj[here][i];
        int ret = discovered[here];
        if(discovered[there]==-1){
            children++;
            int highest = findCutVertex(false, there);
            if(!isRoot && highest >= discovered[here]){
                isCutVertex[here] = true;
            }
            ret = min(ret, highest);
        }
        else{
            ret = min(ret, discovered[there]);
        }
    }
    if(isRoot){
        isCutVertex[here]= (children>=2);
    }
    return ret;
}