class Solution {
public:
     int m, n;
    
    void bfs(vector<vector<int>>& grid2, int i, int j) {
        queue<pair<int,int>> q;
        q.push({i,j});
        grid2[i][j] = 0;
        
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        
        while(!q.empty()) {
            auto [x,y] = q.front(); q.pop();
            for(auto& d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if(nx>=0 && ny>=0 && nx<m && ny<n && grid2[nx][ny]==1) {
                    grid2[nx][ny] = 0;
                    q.push({nx,ny});
                }
            }
        }
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        m = grid1.size();
        n = grid1[0].size();
        
        // Step 1: eliminate invalid land
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid2[i][j]==1 && grid1[i][j]==0) {
                    bfs(grid2, i, j); // wipe out this island
                }
            }
        }
        
        // Step 2: count remaining islands
        int count = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid2[i][j]==1) {
                    bfs(grid2, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};