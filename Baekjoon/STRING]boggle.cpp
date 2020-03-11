//baekjoon 14425
//문자열 집합
//solved using trie
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n;
int dy[8] = {0, 0, -1, 1, 1, 1, -1, -1};
int dx[8] = {1, -1, 0, 0, 1, -1, 1, -1};
vector<string> ans;
vector<string> board(4);
set<int> stored;
int d[4][4];
struct Trie{
    struct Node{
        int children[26];
        bool valid;
        string str;
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
            trie[node].str = s;
            return;
        }
        int c = s[index] - 'A';
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
    void search(int node, int y, int x){
        if(node == -1) return;
        if(trie[node].valid){
            if(stored.find(node) == stored.end()){
                ans.push_back(trie[node].str);
                stored.insert(node);
            }
            // cout<<trie[node].str<<"\n";
        }
        for(int i = 0; i<8;i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny>=0 && ny<4 && nx >=0 && nx <4){
                if(d[ny][nx] == 1) continue;
                char c = board[ny][nx] - 'A';
                int child = trie[node].children[c];
                d[ny][nx] = 1;
                search(child, ny, nx);
                d[ny][nx] = -1;
            }
        }
    }
    void search(int y, int x){
        char c = board[y][x] - 'A';
        int child = trie[root].children[c];
        // cout<<child<<" ";
        d[y][x] = 1;
        search(child, y, x);
        d[y][x] = -1;
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
    int n;
    cin>>n;
    Trie t;
    for(int i = 0;i<n;i++){
        string str;
        cin>>str;
        t.add(str);
    }
    int m;
    cin>>m;
    while(m--){
        ans.clear();
        stored.clear();
        for(int i = 0;i<4;i++){
            cin>>board[i];

        }
        
        for(int i = 0;i<4;i++){
            for(int j = 0;j<4;j++){
                memset(d, -1, sizeof(d));
                t.search(i, j);
            }
        }
        sort(ans.begin(), ans.end(), &s_comp);
        int cnt = 0;
        for(int i = 0;i<ans.size();i++){
            if(ans[i].size()>2){
                cnt++;
                if(ans[i].size()>4){
                    cnt++;
                    if(ans[i].size()>5){
                        cnt++;
                    }
                    if(ans[i].size()>6){
                        cnt += 2;
                        if(ans[i].size()>7){
                            cnt += +6;
                        }
                    }
                    
                }
                
            }
        }
        cout<<cnt<<" "<<ans[0]<<" "<<ans.size()<<"\n";        
    }

    return 0;
}

