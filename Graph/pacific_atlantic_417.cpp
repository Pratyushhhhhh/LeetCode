class Solution {
public:
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    void DFS(vector<vector<int>>& heights, int i, int j, int prevCellVal, vector<vector<bool>>& visited) {
        if(i < 0 || i >= heights.size() || j < 0 || j >= heights[0].size()) { //invalid cell
            return;
        }

        if(heights[i][j] < prevCellVal || visited[i][j])
            return;

        visited[i][j] = true;
        for(auto &dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            DFS(heights, i_, j_, heights[i][j], visited);
        }

    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(); 
        int n = heights[0].size();

        vector<vector<int>> result;

        vector<vector<bool>> pacificVis(m, vector<bool>(n, false)); 
        vector<vector<bool>> atlanticVis(m, vector<bool>(n, false)); 


        //Top Row 0,1 to 0,n-1 and Bottom Row m-1,0 to m-1,n-1

        for(int j = 0; j < n; j++) {
            DFS(heights, 0, j, INT_MIN, pacificVis);
            DFS(heights, m-1, j, INT_MIN, atlanticVis);
        }

        //First col 0,0 to m-1,0 and last column 0,n-1 to m-1,n-1
        for(int i = 0; i < m; i++) {
            DFS(heights, i, 0, INT_MIN, pacificVis);
            DFS(heights, i, n-1, INT_MIN, atlanticVis);
        }


        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(pacificVis[i][j] && atlanticVis[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};

//BRUTE O{(m*n)*(m*n)}
// class Solution {
// public:
//     int n, m;

//     int dr[4] = {-1, 1, 0, 0};
//     int dc[4] = {0, 0, -1, 1};

//     pair<bool, bool> dfs(int r, int c,vector<vector<int>>& vis,vector<vector<int>>& heights) {

//         vis[r][c] = 1;

//         bool po = false;
//         bool ao = false;

//         // Pacific
//         if (r == 0 || c == 0)
//             po = true;

//         // Atlantic
//         if (r == n - 1 || c == m - 1)
//             ao = true;

//         for (int i = 0; i < 4; i++) {

//             int nr = r + dr[i];
//             int nc = c + dc[i];

//             // Out of bounds
//             if (nr < 0 || nr >= n || nc < 0 || nc >= m)
//                 continue;

//             // Already visited
//             if (vis[nr][nc])
//                 continue;

//             // Water cannot flow from current cell to higher cell
//             if (heights[nr][nc] > heights[r][c])
//                 continue;

//             auto [p, a] = dfs(nr, nc, vis, heights);

//             po = po || p;
//             ao = ao || a;
//         }

//         return {po, ao};
//     }

//     vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

//         n = heights.size();
//         m = heights[0].size();

//         vector<vector<int>> res;

//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {

//                 // Fresh visited for every starting cell
//                 vector<vector<int>> vis(n, vector<int>(m, 0) );

//                 auto [po, ao] = dfs(i, j, vis, heights);

//                 if (po && ao) {
//                     res.push_back({i, j});
//                 }
//             }
//         }

//         return res;
//     }
// };