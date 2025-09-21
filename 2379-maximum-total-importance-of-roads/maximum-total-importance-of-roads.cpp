class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> indegree(n,0);
        for(int i=0;i<roads.size();i++){
            vector<int> x = roads[i];
            indegree[x[0]]++;
            indegree[x[1]]++;
        }
        sort(indegree.begin(),indegree.end());
        long long result = 0;
        for(long long i=1;i<=n;i++){
            result += i*indegree[i-1];
        }
        return result;
    }
};