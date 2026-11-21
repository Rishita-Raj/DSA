class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> children(n), newTree(n);

        for (int i = 1; i < n; i++) {
            children[parent[i]].push_back(i);
        }

        vector<int> newParent(n, -1);
        vector<vector<int>> path(26);

        // Find the closest matching ancestor in the original tree.
        stack<pair<int, bool>> st;
        st.push({0, false});

        while (!st.empty()) {
            auto [u, exit] = st.top();
            st.pop();

            int c = s[u] - 'a';

            if (exit) {
                path[c].pop_back();
                continue;
            }

            if (!path[c].empty()) {
                newParent[u] = path[c].back();
            } else {
                newParent[u] = parent[u];
            }

            path[c].push_back(u);

            st.push({u, true});

            for (int i = children[u].size() - 1; i >= 0; i--) {
                st.push({children[u][i], false});
            }
        }

        // Construct the modified tree.
        for (int i = 1; i < n; i++) {
            newTree[newParent[i]].push_back(i);
        }

        // Get traversal order of the modified tree.
        vector<int> order;
        stack<int> nodes;
        nodes.push(0);

        while (!nodes.empty()) {
            int u = nodes.top();
            nodes.pop();

            order.push_back(u);

            for (int v : newTree[u]) {
                nodes.push(v);
            }
        }

        // Calculate subtree sizes in reverse order.
        vector<int> ans(n, 1);

        for (int i = n - 1; i >= 0; i--) {
            int u = order[i];

            if (newParent[u] != -1) {
                ans[newParent[u]] += ans[u];
            }
        }

        return ans;
    }
};