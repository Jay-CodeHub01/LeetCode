class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>>adj(n);
        vector<int>InDeg(n,0);
        
        for(auto &e: relations){
            adj[e[0]-1].push_back(e[1]-1);
            InDeg[e[1]-1]++;
        }

        queue<int>q;
        vector<int> finishTime(n, 0);

        // Initialize with courses having no prerequisites
        for (int i = 0; i < n; i++) {
            if (InDeg[i] == 0) {
                q.push(i);
                finishTime[i] = time[i];
            }
        }

        int totalTime = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            totalTime = max(totalTime, finishTime[node]);

            for(int i=0; i<adj[node].size();i++){
                finishTime[adj[node][i]] = max(finishTime[adj[node][i]], finishTime[node] + time[adj[node][i]]);
                InDeg[adj[node][i]]--;
                if(!InDeg[adj[node][i]]) q.push(adj[node][i]);
            }
        }

        return totalTime;
    }
};