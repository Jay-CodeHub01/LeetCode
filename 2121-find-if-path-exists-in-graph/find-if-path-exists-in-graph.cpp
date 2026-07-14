class Solution {
public:

    bool checkPath(int n,int source, int destination, vector<vector<int>>adj){
        queue<int>q;
        vector<int>visited(n,0);
        
        q.push(source);
        visited[source] = 1;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int i=0; i<adj[node].size(); i++){
                if(!visited[adj[node][i]]){
                    visited[adj[node][i]] = 1;
                    q.push(adj[node][i]);
                }

                if(visited[destination]){
                    return 1;
                }
            }
        }

        return 0;

    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        if(n==1) {
            return true;
        }

        // convert edges to adj matrix
        vector<vector<int>>adj(n);
        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }


        if(checkPath(n, source, destination, adj)){
            return 1;
        }

        return 0;



    }
};