//baekjoon 10256
//돌연변이

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Node {
    int children[4];
    int pi;
    int cnt;
    Node() {
        for (int i=0; i<4; i++) {
            children[i] = -1;
        }
        cnt = 0;
        pi = -1;
    }
};

int to_node(char c){
    if(c == 'A') return 0;
    else if(c == 'T') return 1;
    else if(c == 'G') return 2;
    else if(c == 'C') return 3;
    return 4;
}

vector<Node> trie;
int init() {
    Node x;
    trie.push_back(x);
    return (int)trie.size()-1;
}
void add(int node, string &s, int index) {
    if (index == s.size()) {
        trie[node].cnt = 1;
        return;
    }
    int c = to_node(s[index]);
    if (trie[node].children[c] == -1) {
        int next = init();
        trie[node].children[c] = next;
    }
    add(trie[node].children[c], s, index+1);
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        trie.clear();
        int n, m;
        cin>>n>>m;
        string dna;
        cin>>dna;
        string marker;
        cin>>marker;
        int root = init();
        vector<string> a;
        for(int i = 0;i<marker.size();i++){
            string marker_copy;
            for(int j = i + 1; j<=marker.size();j++){
                marker_copy = marker;
                reverse(marker_copy.begin() + i, marker_copy.begin() + j);
                // cout<<marker_copy<<"\n";
                a.push_back(marker_copy);
            }
        }
        
        sort(a.begin(),a.end());
        a.erase(unique(a.begin(),a.end()),a.end());
        for (string &s : a) {
            // cout<<s<<"\n";
            add(root, s, 0);
        }
    
        
        
        queue<int> q;
        q.push(root);
        trie[root].pi = root;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(int i = 0;i<4;i++){
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
                trie[next].cnt += trie[pi].cnt;
                q.push(next);
            }
            
        }
        
        string s = dna;
        int node = root;
        int ans = 0;
        for(int i =0 ;i<s.size();i++){
            int c = to_node(s[i]);
            
            while(node != root && trie[node].children[c] == -1){
                node = trie[node].pi;
            }
            if(trie[node].children[c] != -1){
                node = trie[node].children[c];
            }
            // if(trie[node].cnt >0){
            //     ans += trie[node].cnt;
            // }
            ans += trie[node].cnt;
        }
        
        cout<<ans<<"\n";
    }
    return 0;
}
