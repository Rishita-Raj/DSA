#define pr pair<int,pair<int,int>>
class Solution {
public:
    int dy[4] = {1,-1,0,0};
    int dx[4] = {0,0,1,-1};
    int trapRainWater(vector<vector<int>>& heightMap) {
        int rows = heightMap.size();
        int cols = heightMap[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols,false));
        priority_queue<pr, vector<pr>, greater<pr>> pq;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(i==0 or j==0 or i==rows-1 or j==cols-1){
                    visited[i][j] = true;
                    pq.push({heightMap[i][j],{i,j}});
                }
            }
        }
        int water = 0;
        while(!pq.empty()){
            auto front = pq.top();
            pq.pop();
            int x = front.second.first;
            int y = front.second.second;
            for(int i=0;i<4;i++){
                int xx = x + dx[i];
                int yy = y + dy[i];
                if(xx>=0 && yy>=0 && xx<rows && yy<cols && !visited[xx][yy]){
                    int gap = max(0,front.first-heightMap[xx][yy]);
                    water += gap;
                    pq.push({heightMap[xx][yy] + gap, {xx,yy}});
                    visited[xx][yy] = true;
                }
            }
        }
        return water;
    }
};