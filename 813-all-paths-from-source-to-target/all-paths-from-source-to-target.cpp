class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    
    void dfs(vector<vector<int>>& graph, int node) {
        path.push_back(node);
        
        if (node == graph.size() - 1) {
            ans.push_back(path);
        } else {
            for (int next : graph[node]) {
                dfs(graph, next);
            }
        }
        
        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        dfs(graph, 0);
        return ans;
    }
};