class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>>adj;
        vector<int>InDeg(numCourses,0);
        for(auto &e: prerequisites){
            adj[e[0]].push_back(e[1]);
            InDeg[e[1]]++;
        }

        queue<int>q;
        for(int i=0; i<numCourses; i++){
            if(!InDeg[i]) q.push(i);
        }

        unordered_map<int,unordered_set<int>>mp;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            

            for(int neigh: adj[node]){
                mp[neigh].insert(node);

                // Insert pre requisusted of node, because by transistivity, they are prereq of neigh also
                for(auto &preq:mp[node]){
                    mp[neigh].insert(preq);
                }
                InDeg[neigh]--;
                if(!InDeg[neigh]) q.push(neigh);
            }
        }

        int Q = queries.size();
        vector<bool> result(Q , false);
        for(int i=0; i<Q; i++){
            int src = queries[i][0];
            int dest = queries[i][1];

            bool reachable = mp[dest].contains(src);
            result[i] = reachable;
        }

        return result;
    }
};