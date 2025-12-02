class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        
        // Step 1: Create bitmask for each word
        vector<int> mask(n, 0);
        vector<int> length(n, 0);
        
        for (int i = 0; i < n; i++) {
            int m = 0;
            for (char c : words[i]) {
                m |= 1 << (c - 'a');  // set bit
            }
            mask[i] = m;
            length[i] = words[i].size();
        }
        
        int maxProduct = 0;
        
        // Step 2: Compare each pair
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((mask[i] & mask[j]) == 0) {
                    maxProduct = max(maxProduct, length[i] * length[j]);
                }
            }
        }
        
        return maxProduct;
    }
};
