class Solution {
public:
    vector<vector<int>> result;
    void DFS(vector<vector<int>> &graph,vector<int>&path,int node,int target){
        for(auto child : graph[node]){
            path.push_back(child); // pushing child into the current vector.
            if(child == target) result.push_back(path);
            DFS(graph,path,child,target);
            path.pop_back();//Poping the node at backtracking step.
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int target = graph.size()-1;
        vector<int> path;
        path.push_back(0);
        DFS(graph,path,0,target);
        return result;
    }
};