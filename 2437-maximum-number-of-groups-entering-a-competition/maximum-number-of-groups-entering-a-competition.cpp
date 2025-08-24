class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n = grades.size()*2, i=0;
        while((i*(i+1)) <= n) i++;
        return --i;
    }
};