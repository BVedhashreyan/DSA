class Solution {
public:
    void mark(int r, int c, vector<vector<int>>&grid){
        // north
        for(int i = r-1; i>=0; i--){
            if(grid[i][c] == 1 || grid[i][c] == 2)break;
            grid[i][c] = 3;
        }
        // south
        for(int i = r+1; i<grid.size(); i++){
            if(grid[i][c] == 1 || grid[i][c] == 2)break;
            grid[i][c] = 3;
        }
        // east
        for(int j = c+1; j<grid[0].size(); j++){
            if(grid[r][j] == 1 || grid[r][j] == 2)break;
            grid[r][j] = 3;
        }
        // west
        for(int j = c-1; j>=0; j--){
            if(grid[r][j] == 1 || grid[r][j] == 2)break;
            grid[r][j] = 3;
        }
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>grid(m,vector<int>(n,0));

        // 0 -green, 1 - guard, 2 - wall, 3 - red;
        for(auto it:guards){
            grid[it[0]][it[1]] = 1;
        }
        for(auto it:walls){
            grid[it[0]][it[1]] = 2;
        }
        for(auto it:guards){
            mark(it[0],it[1],grid);
        }

        int ans = 0;
        for(int i=0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 0)ans++;
            }
        }
        return ans;
    }
};