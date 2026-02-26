class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto& pre : prerequisites){
            adj[pre[1]].push_back(pre[0]);
        }

        vector<int> indegree(numCourses, 0);
        for(int i = 0; i<numCourses; ++i){
            for(int neighbour : adj[i]){
                indegree[neighbour]++;
            }
        }

        queue<int>q;
        for(int i = 0; i<numCourses; ++i){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        int count = 0;
        while(!q.empty()){
            int course = q.front();
            q.pop();
            count++;

            for(int neighbour: adj[course]){
                indegree[neighbour]--;
            if(indegree[neighbour] == 0){
                q.push(neighbour);
            }
            }
        }

        return count == numCourses;
    }
};