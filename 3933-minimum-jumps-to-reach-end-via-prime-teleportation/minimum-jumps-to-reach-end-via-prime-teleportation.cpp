class Solution {
public:
    bool isPrime(int x) {
        if (x < 2) return false;

        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) return false;
        }

        return true;
    }

    int minJumps(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            int val = nums[i];

            for (int d = 2; d * d <= val; d++) {
                if (val % d == 0) {

                    if (isPrime(d))
                        mp[d].push_back(i);

                    while (val % d == 0)
                        val /= d;
                }
            }

            if (val > 1)
                mp[val].push_back(i);
        }
        queue<pair<int,int>> q;
        vector<bool> vis(n, false);

        q.push({0,0});
        vis[0] = true;

        while (!q.empty()) {
            auto [idx, steps] = q.front();
            q.pop();

            if (idx == n - 1)
                return steps;
            if (idx - 1 >= 0 && !vis[idx - 1]) {
                vis[idx - 1] = true;
                q.push({idx - 1, steps + 1});
            }

            if (idx + 1 < n && !vis[idx + 1]) {
                vis[idx + 1] = true;
                q.push({idx + 1, steps + 1});
            }
            int val = nums[idx];

            if (isPrime(val)) {

                for (int next : mp[val]) {
                    if (!vis[next]) {
                        vis[next] = true;
                        q.push({next, steps + 1});
                    }
                }
                mp[val].clear();
            }
        }

        return -1;
    }
};