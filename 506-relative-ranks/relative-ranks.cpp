class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> str(score.size());
        priority_queue<pair<int, int>> pq;
        for(int i=0;i<score.size();i++){
            pq.push({score[i],i});
        }
        for(int i=0;i<3;i++){
            if(pq.empty() == true) break;
            auto a = pq.top();
            pq.pop();
            if(i == 0){
                str[a.second] = "Gold Medal";
            }
            else if(i == 1){
                str[a.second] = "Silver Medal";
            }
            else if(i == 2){
                str[a.second] = "Bronze Medal";
            }
        }
        int i = 4;
        while(!pq.empty()){
            auto a = pq.top();
            pq.pop();
            str[a.second] = to_string(i++);
        }
        return str;
    }
};