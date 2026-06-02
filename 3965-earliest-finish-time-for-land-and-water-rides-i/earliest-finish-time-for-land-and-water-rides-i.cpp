class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        int answer = INT_MAX;

        int n = landStartTime.size();
        int m = waterStartTime.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int landFinish = landStartTime[i] + landDuration[i];

                int waterBegin = max(landFinish, waterStartTime[j]);

                int finish1 = waterBegin + waterDuration[j];
                int waterFinish = waterStartTime[j] + waterDuration[j];

                int landBegin = max(waterFinish, landStartTime[i]);

                int finish2 = landBegin + landDuration[i];

                answer = min(answer, min(finish1, finish2));
            }
        }

        return answer;
    }
};