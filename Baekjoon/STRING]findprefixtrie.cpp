//baekjoon 14426
//접두사 찾기
//solved using trie. Only one line changed from the solution of 14425 문자열 집합
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n;

struct Trie{
    struct Node{
        int children[26];
        bool valid;
        Node(){
            for(int i = 0;i<26;i++){
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
            return;
        }
        int c = s[index] - 'a';
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
        if(index == s.size()){
            return true;
            // return trie[node].valid;
        }
        char c = s[index] - 'a';
        int child = trie[node].children[c];
        return search(child, s, index + 1);
    }
    bool search(string &s){
        return search(root, s, 0);
    }
};


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin>>n>>m;
    Trie t;
    for(int i = 0;i<n;i++){
        string str;
        cin>>str;
        t.add(str);
    }
    int ans = 0;
    for(int i = 0;i<m;i++){
        string str;
        cin>>str;
        if(t.search(str)){
            ans++;
        }
        
    }
    cout<<ans<<"\n";
    return 0;
}
