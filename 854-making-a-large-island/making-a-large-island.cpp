class Solution {
public:
    int n;
    vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    
    int dfs(vector<vector<int>>& grid, int i, int j, int id) {
        if(i<0 || j<0 || i>=n || j>=n || grid[i][j] != 1) return 0;
        grid[i][j] = id; // mark with island id
        int size = 1;
        for(auto& d : dirs) {
            size += dfs(grid, i+d[0], j+d[1], id);
        }
        return size;
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        unordered_map<int,int> islandSize;
        int id = 2; // start labeling islands from 2
        int maxIsland = 0;
        
        // Step 1: label islands and record sizes
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    int size = dfs(grid, i, j, id);
                    islandSize[id] = size;
                    maxIsland = max(maxIsland, size);
                    id++;
                }
            }
        }
        
        // Step 2: try flipping each 0
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 0) {
                    unordered_set<int> seen;
                    int newSize = 1; // flipped cell
                    for(auto& d : dirs) {
                        int ni = i+d[0], nj = j+d[1];
                        if(ni>=0 && nj>=0 && ni<n && nj<n && grid[ni][nj] > 1) {
                            int neighborId = grid[ni][nj];
                            if(seen.insert(neighborId).second) {
                                newSize += islandSize[neighborId];
                            }
                        }
                    }
                    maxIsland = max(maxIsland, newSize);
                }
            }
        }
        
        return maxIsland;
    }
};