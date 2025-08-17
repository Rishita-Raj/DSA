class Solution {
public:
    int DFS(vector<int>adj[], int src, int parent, vector<bool>&apple){
        int time = 0;
        for(auto nbr : adj[src]){
            if(nbr == parent) continue;
            int childTime = DFS(adj,nbr,src,apple);
            if(childTime or apple[nbr]){
                time += childTime + 2;
            }
        }
        return time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int> adj[n];
        for(auto x : edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        return DFS(adj,0,-1,hasApple);
    }
};