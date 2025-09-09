class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        map<string,int> m;
        for(int i=0;i<senders.size();i++){
            m[senders[i]] += count(messages[i].begin(),messages[i].end(),' ') + 1;
        }
        string str;
        int res = 0;
        for(auto x : m){
            if(x.second >= res){
                res = x.second;
                str = x.first;
            }
        }
        return str;
    }
};