class Solution {
public:
    void DFS(vector<vector<int>>& rooms,vector<int>&visited,int node){
        visited[node] = 1;
        for(auto child : rooms[node]){
            if(visited[child] == 0){
                DFS(rooms,visited,child);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int number_of_room = rooms.size();
        vector<int> visited(number_of_room,0);
        DFS(rooms,visited,0);
        for(int i=0;i<rooms.size();i++){
            if(visited[i] == 0) return false;
        }
        return true;
    }
};