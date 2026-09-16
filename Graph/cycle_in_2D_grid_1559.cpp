class Solution {
public:
    int m,n;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    bool dfsCycleDetect(int i,int j, int prev_i, int prev_j,vector<vector<char>>& grid, vector<vector<bool>>&vis){
        if(vis[i][j])
            return true;
        vis[i][j]=true;
        for(auto dir:directions){
            int ni=i+dir[0];
            int nj=j+dir[1];
            if(ni>=0 && nj>=0 && ni<m && nj<n && grid[i][j]==grid[ni][nj]){
                if(prev_i==ni && prev_j==nj)
                    continue;
                if(dfsCycleDetect(ni,nj,i,j,grid,vis))
                    return true;
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<bool>>vis (m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && dfsCycleDetect(i,j,-1,-1,grid,vis))
                    return true;
            }
        }
        return false;
    }
};