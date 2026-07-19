class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;
        int fresh = 0;

        // collect all rotten oranges and count fresh ones
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        int minutes = 0;
        // BFS level by level
        while(!q.empty() && fresh > 0) {
            int size = q.size();
            for(int k=0; k<size; k++){
                auto [r, c] = q.front();
                q.pop();

                // Down
                if(r+1<m && grid[r+1][c]==1){
                    grid[r+1][c] = 2;
                    q.push({r+1, c});
                    fresh--;
                }
                // Up
                if(r-1>=0 && grid[r-1][c]==1){
                    grid[r-1][c] = 2;
                    q.push({r-1, c});
                    fresh--;
                }
                // Right
                if(c+1<n && grid[r][c+1]==1){
                    grid[r][c+1] = 2;
                    q.push({r, c+1});
                    fresh--;
                }
                // Left
                if(c-1>=0 && grid[r][c-1]==1){
                    grid[r][c-1] = 2;
                    q.push({r, c-1});
                    fresh--;
                }
            }
            minutes++; // after finishing one level
        }

        return fresh == 0 ? minutes : -1;
    }
};