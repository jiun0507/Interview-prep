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
    for(int i = 0;i<storage.size();i++){
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
    }
    if(setL == -1){
        storage[storage.size()-1].push_back(left);
        cout<<"stored"<<"\n";
    }
    if(setR == -1){
        storage[storage.size()-1].push_back(right);
    }
}

int main(void){
    string line;
    cin>>line;
    string buf = "";
    int setnum = 0;
    for(int i = 0;i<line.size();i++){
        char cur = line.at(i);
        if(cur == '&'){
            int first = buf.find("==");
            int second = buf.find("!=");
            string left;
            string right;
            if(first != -1){
                left = buf.substr(0, first);
                right = buf.substr(first+2, buf.size()-first-1);
                store(left, right, 1);
                cout<<left<<" "<<right<<"\n";
            }
            else{
                left = buf.substr(0, second);
                right = buf.substr(first+2, buf.size()-second-1);
                store(left, right, 0);
                cout<<left<<" "<<right<<"\n";
            }
            buf = "";
            i+=2;
        }
        buf += line.at(i);
        
    }
    
}
