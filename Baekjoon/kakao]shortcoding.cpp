#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <cstring>
#include <algorithm>
#include <math.h>

using namespace std;

int rel[10][10];
vector<vector<string>> storage(10);

void store(string left, string right, bool equal){
    int setL= -1;
    int setR = -1;
    int i = 0;
    while(!storage[i].empty()){
        vector<string>::iterator itL;
        vector<string>::iterator itR;
        itL = find (storage[i].begin(), storage[i].end(), left); 
        itR = find (storage[i].begin(), storage[i].end(), right); 
        if(itL != storage[i].end()){
            setL = i;
        }
        if(itR != storage[i].end()){
            setR = i;
        }
        i++;
    }
    if(setL == -1){
        storage[i].push_back(left);
        setL = i;
        if(!equal) i++;
        // cout<<left<<" stored at: "<<setL<<"\n";
        
    }
    if(setR == -1){
        if(equal){
            setR = setL;
        } 
        else{
            setR = i;
        }
        storage[setR].push_back(right);
        // cout<<right<<" stored at: "<<setR<<"\n";
    }
    if(!equal){
        rel[setL][setR] =1;
        ;
    }
}

int main(void){
    string line;
    cin>>line;
    string buf = "";
    int setnum = 0;
    for(int i = 0;i<line.size();i++){
        char cur = line.at(i);
        if(cur == '&'||i == line.size()-1){
            if(i == line.size()-1){
                buf += line.at(i);
                
            }
            int first = buf.find("==");
            int second = buf.find("!=");
            string left;
            string right;
            if(first != -1){
                left = buf.substr(0, first);
                right = buf.substr(first+2, buf.size()-first-1);
                store(left, right, 1);
                // cout<<left<<" "<<right<<"\n";
            }
            else{
                left = buf.substr(0, second);
                right = buf.substr(second+2, buf.size()-second-1);
                store(left, right, 0);
                // cout<<left<<" "<<right<<"\n";
            }
            if(i == line.size()-1){
                break;
            }
            buf = "";
            i+=2;
        }
        buf += line.at(i);
        
    }
    int index = 0;
    while(!storage[index].empty()){
        sort(storage[index].begin(), storage[index].end());
        // cout<<storage[index][0]<<"\n";
        index++;
        // cout<<i<<" ";
    }
    bool started = false;
    bool ended =false;
    for(int i = 0;i<index;i++){
        for(int j = 1;j<storage[i].size();j++){
            if(started)cout<<"&&";
            started = true;
            cout<<storage[i][0]<<"=="<<storage[i][j];
        }
    }
    for(int i = 0;i<index;i++){
        for(int j = 0;j<index;j++){
            if(i!=j){
                if(rel[i][j]){
                    cout<<"&&";
                    cout<<storage[i][0]<<"!="<<storage[j][0];
                }
                
            }
        }
    }
}
