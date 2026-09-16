class Solution {
public:
    void dfs(vector<vector<int>>& rooms,int source, vector<bool>&vis){
        vis[source]=true;
        for(int &it:rooms[source]){
            if(!vis[it])
                dfs(rooms,it,vis);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool>vis(n,false);
        dfs(rooms,0,vis);

        // bfs
        // queue<int>q;
        // q.push(0);
        // while(!q.empty()){
        //     int node = q.front();
        //     vis[node]=true;
        //     q.pop();
        //     for(auto it:rooms[node]){
        //         if(!vis[it])
        //             q.push(it);
        //     }
        // }

        for(auto it:vis){
            if(it==false)
                return false;
        }
        return true;
    }
};