class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int a : asteroids) {
            bool destroyed = false;

            while (!st.empty() && st.top() > 0 && a < 0) {
                if (abs(a) > st.top()) {
                    st.pop();  
                    continue;
                } else if (abs(a) == st.top()) {
                    st.pop();  
                }
                destroyed = true;
                break;
            }

            if (!destroyed) {
                st.push(a);
            }
        }

        vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; --i) {
            result[i] = st.top();
            st.pop();
        }

        return result;
    }
};