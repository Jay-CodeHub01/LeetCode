class Solution {
public:
    int topological(int V, vector<vector<int>>&adj){
        
        // Calculate InDegree: 
        vector<int>InDeg(V,0);
        for(int i=0; i<V; i++){
            for(int j=0; j<adj[i].size(); j++){
                InDeg[adj[i][j]]++;
            }
        }

        queue<int>q;
        for(int i=0;i<V;i++){
            if(!InDeg[i]){
                q.push(i);
            }
        }

        int count=0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;

            for(int i = 0; i<adj[node].size();i++){
                InDeg[adj[node][i]]--;
                if(!InDeg[adj[node][i]]){
                    q.push(adj[node][i]);
                }
            }
        }

        return count;

    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto &e: prerequisites){
            adj[e[1]].push_back(e[0]);
        }

        return (topological(numCourses, adj) == numCourses);
    }
};