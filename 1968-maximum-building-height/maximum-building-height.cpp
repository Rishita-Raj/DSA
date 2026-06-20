class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {

        restrictions.push_back({1, 0});
        restrictions.push_back({n, n - 1});

        sort(restrictions.begin(), restrictions.end());

        int m = restrictions.size();
        for (int i = 1; i < m; i++) {
            long long dist = restrictions[i][0] - restrictions[i - 1][0];

            restrictions[i][1] = min(
                restrictions[i][1],
                restrictions[i - 1][1] + (int)dist
            );
        }
        for (int i = m - 2; i >= 0; i--) {
            long long dist = restrictions[i + 1][0] - restrictions[i][0];

            restrictions[i][1] = min(
                restrictions[i][1],
                restrictions[i + 1][1] + (int)dist
            );
        }

        long long answer = 0;

        for (int i = 1; i < m; i++) {

            long long leftId = restrictions[i - 1][0];
            long long rightId = restrictions[i][0];

            long long leftHeight = restrictions[i - 1][1];
            long long rightHeight = restrictions[i][1];

            long long dist = rightId - leftId;

            long long peak =
                (leftHeight + rightHeight + dist) / 2;

            answer = max(answer, peak);
        }

        return (int)answer;
    }
};