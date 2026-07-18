class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto &e: prerequisites){
            adj[e[1]].push_back(e[0]);
        }

        // Calculate InDegree: 
        vector<int>InDeg(numCourses,0);
        for(int i=0; i<numCourses; i++){
            for(int j=0; j<adj[i].size(); j++){
                InDeg[adj[i][j]]++;
            }
        }

        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(!InDeg[i]){
                q.push(i);
            }
        }

        vector<int>ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(int i = 0; i<adj[node].size();i++){
                InDeg[adj[node][i]]--;
                if(!InDeg[adj[node][i]]){
                    q.push(adj[node][i]);
                }
            }
        }

        return (ans.size() == numCourses) ? ans : std::vector<int>{};
    }
};