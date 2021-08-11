class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int ind[numCourses];
        memset(ind, 0, sizeof(ind));
        vector<vector<int>> vertices(numCourses, vector<int>());
        bool check[numCourses];
        memset(check, false, numCourses);
        for(int i = 0;i<prerequisites.size();i++){
            ind[prerequisites[i][1]]++;
            vertices[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        queue<int> q;
        for(int i = 0;i<numCourses;i++){
            if(ind[i]==0) q.push(i);
        }
        while(!q.empty()){
            int cur = q.front(); q.pop();
            check[cur] = true;
            for(auto next:vertices[cur]){
                ind[next]--;
                if(ind[next]==0){
                    q.push(next);
                }
            }
        }
        for(int i = 0;i<numCourses;i++){
            if(!check[i]) return false;
        }
        return true;
    }
};