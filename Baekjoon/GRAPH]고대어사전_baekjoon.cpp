
#include <iostream>
#include <tuple>
#include <algorithm>
#include <cstring>
#include <queue>
#include <string>
using namespace std;

vector<vector<int>> adjacent;
vector<int> visited;

char nth_letter(int n)
{
    return "abcdefghijklmnopqrstuvwxyz"[n];
}

string dfs(int cur){
    visited[cur] = 1;
    string ret;
    for(int i = 0;i<26; i++){
        if(adjacent[cur][i] && !visited[i]){
            string sub = dfs(i);
            if(sub=="") return "";
            ret += sub;
        } 
    }
    ret += nth_letter(cur);
    return ret;
}

int main() {
    int n, m;
    cin>>n;
    while(n--){
        cin>>m;
        vector<string> words;
        for(int i = 0;i<m;i++){
            string input;
            cin>>input;
            words.push_back(input);
        }
        visited = vector<int>(26, 0);
        adjacent = vector<vector<int>> (26, vector<int>(26, 0));
        for(int second = 1;second<words.size();second++){
            int first = second - 1;
            for(int k = 0;k<words[first].size();k++){
                if(words[first][k] != words[second][k]){
                    adjacent[words[first][k]-'a'][words[second][k]-'a'] = 1;
                    break;
                }
            }
        }
        string ans = "";
        string latter = "";
        for(int i = 0;i<26;i++){
            if(!visited[i]){
                string ret = dfs(i);
                if(ret.size()==1){
                    latter += ret;
                } 
                else if(ret==""){
                    cout<<"INVALID HYPOTHESIS"<<"\n";
                } else{
                    ans += ret;
                }
                
            }
        }
        reverse(ans.begin(), ans.end());
        ans += latter;
        cout<<ans<<"\n";
    }


    return 0;
}