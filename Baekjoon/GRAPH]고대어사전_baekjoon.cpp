
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

bool dfs(int cur, string &topo){
    visited[cur] = 1;
    for(int i = 0;i<26; i++){
        if(adjacent[cur][i] && !visited[i]){
            if(!dfs(i, topo)){
                return false;
            }
        } 

    }
    topo += nth_letter(cur);
    return true;
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
            cout<<input<<endl;
        }
        visited = vector<int>(26, 0);
        adjacent = vector<vector<int>> (26, vector<int>(26, 0));
        for(int second = 1;second<words.size();second++){
            int first = second - 1;
            for(int k = 0;k<words[first].size();k++){
                if(words[first][k] != words[second][k]){
                    if(adjacent[words[first][k]-'a'][words[second][k]-'a']){
                        cout<<"INVALID HYPOTHESIS"<<endl;
                        return 0;
                    }
                    adjacent[words[second][k]-'a'][words[first][k]-'a'] = 1;
                    break;
                }
            }
        }
        string ans = "";
        for(int i = 0;i<26;i++){
            if(!visited[i]){
                if(!dfs(i, ans)){
                    cout<<"INVALID_HYPOTHESIS\n";
                    break;
                }
                
            }
        }
        cout<<ans<<"\n";
    }


    return 0;
}