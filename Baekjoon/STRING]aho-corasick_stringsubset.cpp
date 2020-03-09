//baekjoon 9250
//문자열 집합 판별
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Node {
    int children[26];
    int pi;
    bool valid;
    Node() {
        for (int i=0; i<26; i++) {
            children[i] = -1;
        }
        valid = false;
        pi = -1;
    }
};
vector<Node> trie;
int init() {
    Node x;
    trie.push_back(x);
    return (int)trie.size()-1;
}
void add(int node, string &s, int index) {
    if (index == s.size()) {
        trie[node].valid = true;
        return;
    }
    int c = s[index] - 'a';
    if (trie[node].children[c] == -1) {
        int next = init();
        trie[node].children[c] = next;
    }
    add(trie[node].children[c], s, index+1);
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int root = init();
    for(int i = 0;i<n;i++){
        string s;
        cin>>s;
        add(root, s, 0);
        
    }
    queue<int> q;
    q.push(root);
    trie[root].pi = root;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i = 0;i<26;i++){
            int next = trie[cur].children[i];
            if(next == -1) continue;
            if(cur == root){
                trie[next].pi = root;
            }
            else{
                int x = trie[cur].pi;
                while(x != root && trie[x].children[i] == -1){
                    x = trie[x].pi;
                }
                if(trie[x].children[i] != -1){
                    x = trie[x].children[i];
                }
                trie[next].pi = x;
            }
            int pi = trie[next].pi;
            trie[next].valid |= trie[pi].valid;
            q.push(next);
        }
        
    }
    int m;
    cin>>m;
    while(m--){
        string s;
        cin>>s;
        int node = root;
        bool ok = false;
        for(int i =0 ;i<s.size();i++){
            int c = s.at(i) - 'a';
            while(node != root && trie[node].children[c] == -1){
                node = trie[node].pi;
            }
            if(trie[node].children[c] != -1){
                node = trie[node].children[c];
            }
            if(trie[node].valid){
                ok = true;
            }
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
    
    return 0;
}