//baekjoon 5052
//전화번호 목록
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n;

struct Trie{
    struct Node{
        int children[26];
        bool valid;
        string str;
        Node(){
            for(int i = 0;i<11;i++){
                children[i] = -1;
            }
            valid = false;
        }
        
    };
    vector<Node> trie;
    int root;
    int init(){
        Node x;
        trie.push_back(x);
        return (int)trie.size()-1;
    }
    Trie(){
        root = init();
    }
    void add(int node, string &s, int index){
        if(index == s.size()){
            trie[node].valid = true;
            trie[node].str = s;
            return;
        }
        int c = s[index] - '0';
        if(trie[node].children[c] == -1){
            int next = init();
            trie[node].children[c] = next;
        }
        int child = trie[node].children[c];
        add(child, s, index + 1);
    }
    
    void add(string &s){
        add(root, s, 0);
    }
    bool search(int node, string &s, int index){
        if(node == -1) return false;
        if(trie[node].valid){
            for(int i = 0;i<11;i++){
                if(trie[node].children[i] != -1) return false;
            }
            return true;
            // cout<<trie[node].str<<"\n";
            
        }
        int c = s.at(index) - '0';
        return search(trie[node].children[c], s, index + 1);
    }
    bool search(string &s){
        return search(root, s, 0);
    }
};

bool s_comp(string &a, string &b){
    if(a.size() > b.size()){
        return true;
    } else if(a.size() == b.size()){
        if(a < b){
            return true;
        }
    }
    return false;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m;
    int n;
    cin>>m;
    while(m--){
        cin>>n;
        Trie t;
        vector<string> a;
        for(int i = 0;i<n;i++){
            string str;
            cin>>str;
            a.push_back(str);
            t.add(str);
        }
        bool ans = true;
        for(int i = 0;i<a.size();i++){
            if(!t.search(a[i])){
                cout<<"NO"<<"\n";
                ans = false;
                break;
            } 
        }
        if(ans){
            cout<<"YES"<<"\n";    
        }
        
    }
    return 0;
}

