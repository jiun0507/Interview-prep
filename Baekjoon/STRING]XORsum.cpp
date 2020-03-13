//baekjoon 13504
//XOR 합
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n;

struct Trie{
    struct Node{
        int children[2];
        bool valid;
        Node(){
            for(int i = 0;i<2;i++){
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
    void add(int node, int s, int index){
        if(index == -1){
            trie[node].valid = true;
            return;
        }
        int c = (s>>index) & 1;
        
        if(trie[node].children[c] == -1){
            int next = init();
            trie[node].children[c] = next;
        }
        int child = trie[node].children[c];
        add(child, s, index - 1);
    }
    
    void add(int s){
        add(root, s, 31);
    }
    int search(int node, int s, int index){
        if(index == -1){
            return 0;
        }
        int c = (s>>index)&1;
        c = 1 - c;
        if(trie[node].children[c] == -1){
            c = 1 - c;
        }
        if(trie[node].children[c] == -1){
            return 0;
        }
        
        int child = trie[node].children[c];
        int next = 0;
        if (c == 1) next = 1 << index;
        return next|search(child, s, index-1);
    }
    int search(int s){
        return search(root, s, 31);
    }
};


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m;
    cin>>m;
    while(m--){
        int n;
        cin>>n;
        Trie t;
        int ans = 0;
        int prefix = 0;
        t.add(0);
        for(int i = 0;i<n;i++){
            int num;
            cin>>num;
            prefix ^= num;
            t.add(prefix);
            int temp = t.search(prefix)^prefix;
            if(ans < temp) ans = temp;
            
            
        }
        cout<<ans<<"\n";        
    }

    return 0;
}
