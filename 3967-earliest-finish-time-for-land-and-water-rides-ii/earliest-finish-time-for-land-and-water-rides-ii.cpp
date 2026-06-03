class Solution {
public:
    long long solveOneDirection(vector<int>& firstStart,
                                vector<int>& firstDuration,
                                vector<int>& secondStart,
                                vector<int>& secondDuration) {

        int m = secondStart.size();

        vector<pair<long long, long long>> rides;

        for (int i = 0; i < m; i++) {
            rides.push_back({secondStart[i], secondDuration[i]});
        }

        sort(rides.begin(), rides.end());

        vector<long long> starts(m);

        for (int i = 0; i < m; i++) {
            starts[i] = rides[i].first;
        }

        vector<long long> prefixMinDuration(m);
        prefixMinDuration[0] = rides[0].second;

        for (int i = 1; i < m; i++) {
            prefixMinDuration[i] =
                min(prefixMinDuration[i - 1], rides[i].second);
        }

        vector<long long> suffixMinFinish(m);

        suffixMinFinish[m - 1] =
            rides[m - 1].first + rides[m - 1].second;

        for (int i = m - 2; i >= 0; i--) {
            suffixMinFinish[i] =
                min(suffixMinFinish[i + 1],
                    rides[i].first + rides[i].second);
        }

        long long answer = LLONG_MAX;

        for (int i = 0; i < firstStart.size(); i++) {

            long long finishTime =
                (long long)firstStart[i] + firstDuration[i];

            int pos =
                upper_bound(starts.begin(),
                            starts.end(),
                            finishTime) -
                starts.begin();

            if (pos > 0) {
                answer = min(
                    answer,
                    finishTime + prefixMinDuration[pos - 1]);
            }

            if (pos < m) {
                answer = min(
                    answer,
                    suffixMinFinish[pos]);
            }
        }

        return answer;
    }

    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        long long landThenWater =
            solveOneDirection(
                landStartTime,
                landDuration,
                waterStartTime,
                waterDuration);

        long long waterThenLand =
            solveOneDirection(
                waterStartTime,
                waterDuration,
                landStartTime,
                landDuration);

        return (int)min(landThenWater, waterThenLand);
    }
};