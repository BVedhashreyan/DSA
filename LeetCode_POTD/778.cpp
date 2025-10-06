// Approach 1 - using , bs on answers
class Solution {
public:
    vector<vector<int>>directions {{1,0}, {0,1}, {-1,0}, {0,-1}};
    int n;
    bool possible(vector<vector<int>>& grid,int r, int c, int t, vector<vector<bool>>& visited){
        if(r < 0 || c < 0 || r >= n || c >= n || visited[r][c] || grid[r][c] > t){
            return false;
        }

        visited[r][c] = true;
        if(r == n-1 && c == n-1)return true;

        for(auto &dir: directions){
            int R = r+dir[0];
            int C = c+dir[1];

            if(possible(grid, R, C, t, visited))return true;
        }

        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        int l = grid[0][0], r = n*n-1;
        int ans = 0;
        
        while(l<=r){
            int mid = l+(r-l)/2;

            vector<vector<bool>>visited(n, vector<bool>(n,false));
            if(possible(grid, 0, 0, mid, visited)){
                ans = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return ans;
    }
};
// TC - O(n^2 logn^2) => O(n^2 logn)
// Sc - O(n^2)

// Approach 2 - minHeap + djisktra
class Solution {
public:
    vector<vector<int>> directions {{-1,0},{0,-1},{1,0},{0,1}};
    int swimInWater(vector<vector<int>>& grid) {
        int N = grid.size();
        int r = 0, c = 0;
        vector<vector<bool>>visited (N,vector<bool>(N,false));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>minHeap;

        minHeap.push({grid[0][0],r,c});

        while(!minHeap.empty()){
            auto top = minHeap.top();
            minHeap.pop();

            int t = top[0], r = top[1], c = top[2];
            if(r == N-1 && c == N-1)return t;

            for(auto dir:directions){
                int R = r+dir[0]; 
                int C = c+dir[1];

                if(R>=N || C>=N || R<0 || C<0 || visited[R][C])continue;

                visited[R][C] = true;
                minHeap.push({max(t, grid[R][C]), R, C}); 
            }
        }
        return -1;

    }
};

// TC - O(n^2 logn)
// SC - O(n^2)