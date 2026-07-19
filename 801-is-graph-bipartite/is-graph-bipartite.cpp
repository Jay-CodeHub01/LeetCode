class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>color(graph.size(),-1);
        queue<int>q;
        for(int k=0; k<graph.size();k++){
            if(color[k] == -1){
                color[k] = 0;
                q.push(k);
                while(!q.empty()){
                    int node = q.front();
                    q.pop();

                    for(int i=0; i<graph[node].size(); i++){
                        if(color[graph[node][i]] == -1){
                            color[graph[node][i]] = (color[node]+1)%2;
                            q.push(graph[node][i]);
                        }
                        else{
                            if(color[node] == color[graph[node][i]]){
                                return 0;
                            }
                        }
                    }
                }
            }
        }
        return 1;    
    }
};